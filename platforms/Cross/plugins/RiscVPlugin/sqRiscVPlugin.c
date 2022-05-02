#include <stdarg.h>
#include <stdbool.h>

#define COG 1
#define FOR_COG_PLUGIN 1

#include "sqSetjmpShim.h"
#include "RiscVPlugin.h"

#include "core.h"
#include "riscv_types.h"

void (*prevInterruptCheckChain)() = 0;
long resetCPU(void *cpu);

typedef struct squeak_soc {
    rv_core_td core;
    bool is_initialized;

	WordType *RAM;
} squeak_soc_t;

static squeak_soc_t soc;

void *newCPU() {
    if (!soc.is_initialized) {
        resetCPU(&soc);
        soc.is_initialized = true;
    }
    return &soc;
}

static rv_ret squeak_soc_bus_access(void* privat, privilege_level priv_level, bus_access_type access_type, rv_uint_xlen address, void* value, uint8_t len)
{
    squeak_soc_t *ssoc = privat;
    
    if (access_type == bus_read_access)
	switch(access_type) {
		case bus_read_access:
			break;
		case bus_write_access:
			break;
		case bus_instr_access:
			break;
		case bus_access_type_max:
			// not sure what to do
			return rv_err;
	}
	return rv_err;
}

long resetCPU(void *cpu) {
    squeak_soc_t *ssoc = cpu;

    rv_core_init(&ssoc->core, ssoc, squeak_soc_bus_access);

    return 0;
}

static inline void resetSegmentRegisters(uintptr_t byteSize,
        uintptr_t minWriteMaxExecAddr) {
	// not sure if present in riscv
}

long singleStepCPUInSizeMinAddressReadWrite(void *cpu, void *memory,
        uintptr_t byteSize,
        uintptr_t minAddr,
        uintptr_t minWriteMaxExecAddr) {
	squeak_soc_t *ssoc = cpu;
	ssoc->RAM = memory;

	rv_core_run(&ssoc->core);

	// just success
	return 0;
}

long runCPUInSizeMinAddressReadWrite(void *cpu, void *memory,
        uintptr_t byteSize, uintptr_t minAddr,
        uintptr_t minWriteMaxExecAddr) {
	squeak_soc_t *ssoc = cpu;
    return 45;
}

/*
 * Currently a dummy for Bochs.
 */
void flushICacheFromTo(void *cpu, uintptr_t saddr, uintptr_t eaddr) {
}

long disassembleForAtInSize(void *cpu, uintptr_t laddr, void *memory,
        uintptr_t byteSize) {
	squeak_soc_t *ssoc = cpu;
    return 46;
}

void forceStopRunning(void) {
}

long errorAcorn(void) { return 47; }

char *getlog(long *len) {
    return "Hello World";
}

// see ProcessorSimulatorPlugin>>storeIntegerRegisterStateOf:into: and BochsX64Alien>>integerRegisterState
void storeIntegerRegisterStateOfinto(void *cpu, WordType *registerState) {
	squeak_soc_t *ssoc = cpu;

	for (int i = 0; i < 32; i++) {
		registerState[i] = ssoc->core.x[i];
	}
	registerState[32] = ssoc->core.pc;
	registerState[33] = ssoc->core.pc;
}
