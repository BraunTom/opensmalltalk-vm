#include <stdarg.h>

#define COG 1
#define FOR_COG_PLUGIN 1

#include "sqSetjmpShim.h"
#include "RiscVPlugin.h"

void (*prevInterruptCheckChain)() = 0;
long resetCPU(void *cpu);

void *newCPU() {
	return (void*) 42;
}

long resetCPU(void *cpu) {
	return 43;
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

