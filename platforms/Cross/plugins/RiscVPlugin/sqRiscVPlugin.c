#define COG 1
#define FOR_COG_PLUGIN 1

#include "config.h"
#include "sqAssert.h"
#include "RiscVPlugin.h"

#include <stdarg.h>

#undef PACKAGE
#undef VERSION
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#include "sim-main.h"
#include "opcode/riscv.h"
#include "sim/callback.h"

#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#include <memory.h>
#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#include <bfd.h>
#include <disassemble.h>


#include "sqSetjmpShim.h"

struct sim_state *lastCPU = NULL;
sim_cpu initialSimState = {0,};

jmp_buf error_abort;

// These two variables exist, in case there are library-functions which write to a stream.
// In that case, we would write functions which print to that stream instead of stderr or similar
#define LOGSIZE 4096
static char	gdb_log[LOGSIZE+1];
static int	gdblog_index = 0;

static unsigned char *theMemory = 0;
static unsigned long  theMemorySize;
static unsigned long  minReadAddress;
static unsigned long  minWriteAddress;
static int            theErrorAcorn;
static int            continueRunning;

/* The interrupt check chain is a convention wherein functions wanting to be
 * called on interrupt check chain themselves together by remembering the head
 * of the interruptCheckChain when they register to be informed. See the source
 * of the plugin itself, src/plugins/GdbARMv8Plugin/GdbARMv8Plugin.c
 */
void	(*prevInterruptCheckChain)() = 0;

static host_callback callback; // we do not set any of the callbacks -> it is possible we get segfaults from this

void *
newCPU()
{
	if (!lastCPU) {
		char *riscv_argv[] = {"RISCV", 0};
		lastCPU = sim_open(SIM_OPEN_STANDALONE, &callback, 0, riscv_argv);
		initialSimState = *(lastCPU->cpu[0]);
		memset(&initialSimState.regs[0],
				0,
				(char *)&initialSimState.base - (char *)&initialSimState.regs[0]);
		// lastCPU->base.engine.jmpbuf = error_abort;
	}
	return lastCPU->cpu[0];
}

long
resetCPU(void *cpu)
{
	gdblog_index = 0;

	*(sim_cpu *)cpu = initialSimState;
	if (lastCPU->cpu[0]) /* why does this get nilled? eem 2019/11/19 */
		*(lastCPU->cpu[0]) = initialSimState;
	return 0;
}

#define run 0
#define step 1

static inline long
runOnCPU(sim_cpu *cpu, void *memory,
		uintptr_t byteSize, uintptr_t minAddr, uintptr_t minWriteMaxExecAddr, int runOrStep)
{
    cpu->base.core.common.map[2].first->buffer = memory;
    // + 4 as we assume instructions are always 4 byte
	uint64_t postpc = cpu->pc + 4;

	theMemory = (unsigned char *)memory;
	theMemorySize = byteSize;
	minReadAddress = minAddr;
	minWriteAddress = minWriteMaxExecAddr;
	theErrorAcorn = 0;

	if ((theErrorAcorn = setjmp(error_abort)) != 0)
		return theErrorAcorn;

	// assert(lastCPU->base.engine.jmpbuf = error_abort);
	gdblog_index = 0;

	if (runOrStep == step) {
        if(postpc <= minWriteMaxExecAddr) { step_once(cpu); }
		if (cpu->pc + 4 <= minWriteMaxExecAddr) {
			cpu->pc = cpu->pc + 4;
		}
	}
	else {
        while(!gdblog_index) {
            if (postpc <= minWriteMaxExecAddr) {
                step_once(cpu);
            } else {
                break;
            }
            if(!gdblog_index) {break;}

            if (cpu->pc + 4 <= minWriteMaxExecAddr)
                cpu->pc = cpu->pc + 4;
            postpc = cpu->pc + 4 + 4;
        }


	}
	if (postpc > minWriteMaxExecAddr
	 || cpu->pc + 4 > minWriteMaxExecAddr)
		return InstructionPrefetchError;

#if 0
	// collect the PSR from their dedicated flags to have easy access from the image.
	ARMul_SetCPSR(state, ARMul_GetCPSR(state));

	if (state->EndCondition != NoError)
		return state->EndCondition;
#endif
	if (theErrorAcorn)
		return theErrorAcorn;

	return gdblog_index == 0 ? 0 : SomethingLoggedError;
}

long
singleStepCPUInSizeMinAddressReadWrite(void *cpu, void *memory, 
		uintptr_t byteSize, uintptr_t minAddr, uintptr_t minWriteMaxExecAddr)
{
	return runOnCPU(cpu, memory, byteSize, minAddr, minWriteMaxExecAddr, step);
}

long
runCPUInSizeMinAddressReadWrite(void *cpu, void *memory, 
		uintptr_t byteSize, uintptr_t minAddr, uintptr_t minWriteMaxExecAddr)
{
	return runOnCPU(cpu, memory, byteSize, minAddr, minWriteMaxExecAddr, run);
}

/*
 * Currently a dummy for ARM Processor Alien.
 */
void
flushICacheFromTo(void *cpu, uintptr_t saddr, uintptr_t eaddr)
{
#if 0
# error not yet implemented
#endif
}

int
gdb_log_printf(void *stream, const char * format, ...)
{
	va_list arg;
	int n;
	va_start(arg,format);

	if (!stream) {
		n = vsnprintf((char*) (&gdb_log) + gdblog_index, LOGSIZE-gdblog_index, format, arg);
		gdblog_index = gdblog_index + n;
	}
	else
		vfprintf(stream, format, arg);
	return 0;
}

long
disassembleForAtInSize(void *cpu, uintptr_t laddr,
			void *memory, uintptr_t byteSize)
{
	gdblog_index = 0;
	// ignore the cpu
	// start disassembling at laddr relative to memory
	// stop disassembling at memory+byteSize

	disassemble_info* dis = (disassemble_info*) calloc(1, sizeof(disassemble_info));
	// void init_disassemble_info (struct disassemble_info *dinfo, void *stream, fprintf_ftype fprintf_func)
	init_disassemble_info ( dis, NULL, gdb_log_printf);

	dis->arch = bfd_arch_riscv;
    // needed to figure out the xlen internally
    dis->mach = bfd_mach_riscv64;

	// sets some fields in the structure dis to architecture specific values
	disassemble_init_for_target( dis );

	dis->buffer_vma = 0;
	dis->buffer = memory;
	dis->buffer_length = byteSize;

	// first print the address
	gdb_log_printf( NULL, "%08lx: ", laddr);
	// initializes an internal list without we cannot print anything
    riscv_get_disassembler(NULL);
	unsigned int size = print_insn_riscv((bfd_vma) laddr, dis);

	free(dis);
	gdb_log[gdblog_index+1] = 0;

	return size;
}

void
forceStopRunning() { continueRunning = 0; }

long
errorAcorn(void) { return errorAcorn; }

char *
getlog(long *len)
{
	*len = gdblog_index;
	return gdb_log;
}

void
storeIntegerRegisterStateOfinto(void *cpu, WordType *registerState)
{
	for (int n = 0; n < 32; n++) {
		registerState[n] = ((sim_cpu *)cpu)->regs[n];
	}
		
}
