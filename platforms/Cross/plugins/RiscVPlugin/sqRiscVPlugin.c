#include <stdarg.h>
#include <stdbool.h>

#define COG 1
#define FOR_COG_PLUGIN 1

#include "sqSetjmpShim.h"
#include "RiscVPlugin.h"

#include "core.h"

void (*prevInterruptCheckChain)() = 0;
long resetCPU(void *cpu);

typedef struct squeak_soc {
    rv_core_td core;
    bool is_initialized;
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
    squeak_soc_t *soc = privat;
    
    // TOOD
    return rv_err;
}

long resetCPU(void *cpu) {
    squeak_soc_t *soc = cpu;

    rv_core_init(&soc->core, soc, squeak_soc_bus_access);

    return 0;
}

static inline void resetSegmentRegisters(uintptr_t byteSize,
        uintptr_t minWriteMaxExecAddr) {
}

long singleStepCPUInSizeMinAddressReadWrite(void *cpu, void *memory,
        uintptr_t byteSize,
        uintptr_t minAddr,
        uintptr_t minWriteMaxExecAddr) {
    return 44;
}

long runCPUInSizeMinAddressReadWrite(void *cpu, void *memory,
        uintptr_t byteSize, uintptr_t minAddr,
        uintptr_t minWriteMaxExecAddr) {
    return 45;
}

/*
 * Currently a dummy for Bochs.
 */
void flushICacheFromTo(void *cpu, uintptr_t saddr, uintptr_t eaddr) {
}

long disassembleForAtInSize(void *cpu, uintptr_t laddr, void *memory,
        uintptr_t byteSize) {
    return 46;
}

void forceStopRunning(void) {
}

long errorAcorn(void) { return 47; }

char *getlog(long *len) {
    return "Hello World";
}
void storeIntegerRegisterStateOfinto(void *cpu, WordType *registerState) {

}

