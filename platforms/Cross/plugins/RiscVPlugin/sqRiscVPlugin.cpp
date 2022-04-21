#include <stdarg.h>
#define COG 1
#define FOR_COG_PLUGIN 1


extern "C"
{

#include "RiscVPlugin.h"

	static int cpu_has_been_reset = 0;

#define LOGSIZE 4096
	static char bochs_log[LOGSIZE + 1];
	static int blidx = 0;

	static unsigned char *theMemory = 0;
	static unsigned long theMemorySize;
	static unsigned long minReadAddress;
	static unsigned long minWriteAddress;
	static int theErrorAcorn;

	void (*prevInterruptCheckChain)() = 0;
	long resetCPU(void *cpu);

	void *newCPU() {
		return (void*)42;
	}

	long resetCPU(void *cpu) {
		return 99;
	}

	static inline void resetSegmentRegisters(uintptr_t byteSize, uintptr_t minWriteMaxExecAddr)
	{
	}


	long singleStepCPUInSizeMinAddressReadWrite(void *cpu,
										   void *memory, uintptr_t byteSize,
										   uintptr_t minAddr, uintptr_t minWriteMaxExecAddr)
	{
		return 99;
	}

	long runCPUInSizeMinAddressReadWrite(void *cpu, void *memory, uintptr_t byteSize,
									uintptr_t minAddr, uintptr_t minWriteMaxExecAddr)
	{
		return 100;
	}

	/*
	 * Currently a dummy for Bochs.
	 */
	void
	flushICacheFromTo(void *cpu, uintptr_t saddr, uintptr_t eaddr)
	{
	}

	long
	disassembleForAtInSize(void *cpu, uintptr_t laddr,
						   void *memory, uintptr_t byteSize)
	{
		return 500;
	}

	void
	forceStopRunning(void)
	{
	}

	long
	errorAcorn(void) {}

	char *
	getlog(long *len)
	{
		return bochs_log;
	}
	void
	storeIntegerRegisterStateOfinto(void *cpu, WordType *registerState)
	{
	}
} // extern "C"
