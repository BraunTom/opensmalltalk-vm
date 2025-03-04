/* Automatically generated from Squeak on {16 April 2022 . 10:02:11 pm} */

static char __buildInfo[] = "Generated on {16 April 2022 . 10:02:11 pm}. Compiled on "__DATE__ ;


#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#include "RiscVPlugin.h"
#include "sqMemoryAccess.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
# define INT_EXT "(i)"
#else
# define INT_EXT "(e)"
#endif


/* ProcessorSimulatorPlugin class>>preambleCCode */

# define isIntegerObject(oop) ((oop) & 1)
# define integerObjectOf(value) ((((usqInt) value) << NumSmallIntegerTagBits) | 1)
# define integerValueOf(oop) ((oop) >> NumSmallIntegerTagBits)

# if SPURVM
extern sqInt classIndexOf(sqInt);
#	define LargeNegativeIntegerClassIndex 32
#	define LargePositiveIntegerClassIndex 33
#	if BytesPerOop == 4
#	  define isImmediate(oop) ((oop) & 3)
#	else
#	  define isImmediate(oop) ((oop) & 7)
#	endif
#	define isKindOfInteger(oop) (isImmediate(oop) ? isIntegerObject(oop) : (unsigned)(classIndexOf(oop) - LargeNegativeIntegerClassIndex) <= 1)
#	define isLargeIntegerObject(oop) (!isImmediate(oop) && (unsigned)(classIndexOf(oop) - LargeNegativeIntegerClassIndex) <= 1)
#	define isLargeNegativeIntegerObject(oop) (!isImmediate(oop) && classIndexOf(oop) == LargeNegativeIntegerClassIndex)
#	define isLargePositiveIntegerObject(oop) (!isImmediate(oop) && classIndexOf(oop) == LargePositiveIntegerClassIndex)
# endif /* SPURVM */

#if !defined(isKindOfInteger)
# define isLargeNegativeIntegerObject(oop) (fetchClassOf(oop) == classLargeNegativeInteger())
# define isLargePositiveIntegerObject(oop) (fetchClassOf(oop) == classLargePositiveInteger())
# define isLargeIntegerObject(oop) (isLargeNegativeIntegerObject(oop) || isLargePositiveIntegerObject(oop))
# define isKindOfInteger(oop) (isIntegerObject(oop) || isLargeNegativeIntegerObject(oop) || isLargePositiveIntegerObject(oop))
#endif

/* end ProcessorSimulatorPlugin class>>preambleCCode */


/*** Function Prototypes ***/
static void forceStopOnInterrupt(void);
EXPORT(const char*) getModuleName(void);
static sqInt is64BitISA(void);
EXPORT(sqInt) primitiveDisassembleAtInMemory(void);
EXPORT(sqInt) primitiveErrorAndLog(void);
EXPORT(sqInt) primitiveFlushICacheFromTo(void);
EXPORT(sqInt) primitiveIntegerRegisterState(void);
EXPORT(sqInt) primitiveMemoryOffset(void);
EXPORT(sqInt) primitiveNewCPU(void);
EXPORT(sqInt) primitiveResetCPU(void);
EXPORT(sqInt) primitiveRunInMemoryMinAddressMaxAddressReadWrite(void);
EXPORT(sqInt) primitiveRunInMemoryMinimumAddressReadWrite(void);
EXPORT(sqInt) primitiveRunInMemoryOffsetMinimumAddressReadWrite(void);
EXPORT(sqInt) primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite(void);
EXPORT(sqInt) primitiveSingleStepInMemoryMinimumAddressReadWrite(void);
EXPORT(sqInt) primitiveSingleStepInMemoryOffsetMinimumAddressReadWrite(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
static sqInt sizeField(sqInt alienOop);
static sqInt startOfData(sqInt alienOop);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classArray)(void);
static sqInt (*classDoubleWordArray)(void);
static sqInt (*classString)(void);
static sqInt (*classWordArray)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*getInterruptPending)(void);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
#if !defined(integerValueOf)
static sqInt (*integerValueOf)(sqInt oop);
#endif
#if !defined(isIntegerObject)
static sqInt (*isIntegerObject)(sqInt objectPointer);
#endif
static sqInt (*isWordsOrBytes)(sqInt oop);
static sqInt (*methodArgumentCount)(void);
static sqInt (*methodReturnInteger)(sqInt integer);
static sqInt (*methodReturnValue)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*popRemappableOop)(void);
static sqInt (*positive32BitIntegerFor)(unsigned int integerValue);
static sqInt (*positive64BitIntegerFor)(usqLong integerValue);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*primitiveFailForOSError)(sqLong osErrorCode);
static sqInt (*pushRemappableOop)(sqInt oop);
static void * (*setInterruptCheckChain)(void (*aFunction)());
static sqInt (*stackValue)(sqInt offset);
static sqInt (*storeIntegerofObjectwithValue)(sqInt index, sqInt oop, sqInt integer);
static sqInt (*storePointerofObjectwithValue)(sqInt index, sqInt oop, sqInt valuePointer);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classArray(void);
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 16)
extern sqInt classDoubleWordArray(void);
#else
# define classDoubleWordArray() 0
#endif
extern sqInt classString(void);
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 16)
extern sqInt classWordArray(void);
#else
# define classWordArray() 0
#endif
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt getInterruptPending(void);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
#if !defined(integerValueOf)
extern sqInt integerValueOf(sqInt oop);
#endif
#if !defined(isIntegerObject)
extern sqInt isIntegerObject(sqInt objectPointer);
#endif
extern sqInt isWordsOrBytes(sqInt oop);
extern sqInt methodArgumentCount(void);
extern sqInt methodReturnInteger(sqInt integer);
extern sqInt methodReturnValue(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt popRemappableOop(void);
extern sqInt positive32BitIntegerFor(unsigned int integerValue);
extern sqInt positive64BitIntegerFor(usqLong integerValue);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 14)
extern sqInt primitiveFailForOSError(sqLong osErrorCode);
#else
# define primitiveFailForOSError(osErrorCode) 0
#endif
extern sqInt pushRemappableOop(sqInt oop);
extern void * setInterruptCheckChain(void (*aFunction)());
extern sqInt stackValue(sqInt offset);
extern sqInt storeIntegerofObjectwithValue(sqInt index, sqInt oop, sqInt integer);
extern sqInt storePointerofObjectwithValue(sqInt index, sqInt oop, sqInt valuePointer);
extern
#endif
struct VirtualMachine* interpreterProxy;
static sqInt memoryOffset = 0;
static const char *moduleName = "RiscVPlugin 16 April 2022 " INT_EXT;


	/* ProcessorSimulatorPlugin>>#forceStopOnInterrupt */
static void
forceStopOnInterrupt(void)
{
	if (getInterruptPending()) {
		forceStopRunning();
	}
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* RiscVPlugin>>#is64BitISA */
static sqInt
is64BitISA(void)
{
	return 1;
}


/*	cpuAlien <CogProcessorAlien> */
/*	<Integer> */
/*	<Bitmap|ByteArray|WordArray|DoubleWordArray> */
/*	Return an Array of the instruction length and its decompilation as a
	string for the instruction at address in memory.
 */

	/* ProcessorSimulatorPlugin>>#primitiveDisassembleAt:InMemory: */
EXPORT(sqInt)
primitiveDisassembleAtInMemory(void)
{
	sqInt address;
	void *cpu;
	sqInt cpuAlien;
	sqInt instrLenOrErr;
	char *log;
	long logLen;
	sqInt logObj;
	char *memory;
	sqInt resultObj;

	logLen = 0;
	if (!((isIntegerObject((address = stackValue(1))))
		 && (isWordsOrBytes(stackValue(0))))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	address = integerValueOf(address);
	memory = ((char *) (firstIndexableField(stackValue(0))));
	cpuAlien = stackValue(2);
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if (address < memoryOffset) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	instrLenOrErr = disassembleForAtInSize(cpu, address, memory - memoryOffset, (byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize))) + memoryOffset);
	if (instrLenOrErr < 0) {
		return primitiveFailForOSError(-instrLenOrErr);
	}
	log = getlog((&logLen));
	resultObj = instantiateClassindexableSize(classArray(), 2);
	if (!resultObj) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	pushRemappableOop(resultObj);
	logObj = instantiateClassindexableSize(classString(), logLen);
	resultObj = popRemappableOop();
	if (!logObj) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	memcpy(firstIndexableField(logObj), log, logLen);
	storeIntegerofObjectwithValue(0, resultObj, instrLenOrErr);
	storePointerofObjectwithValue(1, resultObj, logObj);
	if (!(failed())) {
		methodReturnValue(resultObj);
	}
	return null;
}

	/* ProcessorSimulatorPlugin>>#primitiveErrorAndLog */
EXPORT(sqInt)
primitiveErrorAndLog(void)
{
	char *log;
	long logLen;
	sqInt logObj;
	sqInt resultObj;

	logLen = 0;
	log = getlog((&logLen));
	resultObj = instantiateClassindexableSize(classArray(), 2);
	if (!resultObj) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	storeIntegerofObjectwithValue(0, resultObj, errorAcorn());
	if (logLen > 0) {
		pushRemappableOop(resultObj);
		logObj = instantiateClassindexableSize(classString(), logLen);
		resultObj = popRemappableOop();
		if (!logObj) {
			return primitiveFailFor(PrimErrNoMemory);
		}
		memcpy(firstIndexableField(logObj), log, logLen);
		storePointerofObjectwithValue(1, resultObj, logObj);
	}
	methodReturnValue(resultObj);
	return 0;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Integer> */
/*	<Integer> */
/*	Flush the icache in the requested range */

	/* ProcessorSimulatorPlugin>>#primitiveFlushICacheFrom:To: */
EXPORT(sqInt)
primitiveFlushICacheFromTo(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt endAddress;
	sqInt startAddress;

	if (!((isIntegerObject((startAddress = stackValue(1))))
		 && (isIntegerObject((endAddress = stackValue(0)))))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	startAddress = integerValueOf(startAddress);
	endAddress = integerValueOf(endAddress);
	cpuAlien = stackValue(2);
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	flushICacheFromTo(cpu, startAddress, endAddress);
	if (!(failed())) {
		pop(2);
	}
	return null;
}


/*	Answer an IntegerArray of the processor's integer register state, ending
	with, if these are not otherwise
	included in the register state, the pc and the flags (if the processor has
	flags). This primitive is unnecessary; it exists only to speed up single
	stepping. 
 */

	/* ProcessorSimulatorPlugin>>#primitiveIntegerRegisterState */
EXPORT(sqInt)
primitiveIntegerRegisterState(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt registerStateVector;

	cpuAlien = stackValue(0);
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	registerStateVector = instantiateClassindexableSize((1
		? classDoubleWordArray()
		: classWordArray()), NumIntegerRegisterStateFields);
	if (registerStateVector == 0) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	if ((byteSizeOf(registerStateVector)) != (NumIntegerRegisterStateFields * (sizeof(sqLong)))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	storeIntegerRegisterStateOfinto(cpu, firstIndexableField(registerStateVector));
	if (!(failed())) {
		methodReturnValue(registerStateVector);
	}
	return null;
}


/*	Get or set the memory offset. If non-zero the memry offset is one word (4
	or 8 bytes), to marry with the
	SuprMemoryManager simulators discarding of the first word of memory as a
	null pointer trap. */

	/* ProcessorSimulatorPlugin>>#primitiveMemoryOffset */
EXPORT(sqInt)
primitiveMemoryOffset(void)
{
	sqInt offset;
	sqInt previousValue;

	if ((methodArgumentCount()) == 0) {
		return methodReturnInteger(memoryOffset);
	}
	if ((methodArgumentCount()) != 1) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	offset = stackValue(0);
	if (!(isIntegerObject(offset))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	previousValue = memoryOffset;
	memoryOffset = integerValueOf(offset);
	return methodReturnInteger(previousValue);
}

	/* ProcessorSimulatorPlugin>>#primitiveNewCPU */
EXPORT(sqInt)
primitiveNewCPU(void)
{
	void *cpu;

	cpu = newCPU();
	if (cpu == 0) {
		return primitiveFail();
	}
	popthenPush(1, (BytesPerWord == 8
		? positive64BitIntegerFor(((usqIntptr_t) cpu))
		: positive32BitIntegerFor(((usqIntptr_t) cpu))));
	return null;
}

	/* ProcessorSimulatorPlugin>>#primitiveResetCPU */
EXPORT(sqInt)
primitiveResetCPU(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;

	cpuAlien = stackValue(0);
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	maybeErr = resetCPU(cpu);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		methodReturnValue(cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	<Integer> */
/*	Run the cpu using the first argument as the memory and the following
	arguments defining valid addresses, running until it halts or hits an
	exception. 
 */

	/* ProcessorSimulatorPlugin>>#primitiveRunInMemory:minimumAddress:maximumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveRunInMemoryMinAddressMaxAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maxAddress;
	sqInt maybeErr;
	char *memory;
	sqInt memorySize;
	sqInt minAddress;
	sqInt minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(3)))
		 && ((isIntegerObject((minAddress = stackValue(2))))
		 && ((isIntegerObject((maxAddress = stackValue(1))))
		 && (isIntegerObject((minWriteMaxExecAddress = stackValue(0)))))))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	memory = ((char *) (firstIndexableField(stackValue(3))));
	minAddress = integerValueOf(minAddress);
	maxAddress = integerValueOf(maxAddress);
	minWriteMaxExecAddress = integerValueOf(minWriteMaxExecAddress);
	cpuAlien = stackValue(4);
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if ((minAddress < memoryOffset)
	 || ((maxAddress < memoryOffset)
	 || (minWriteMaxExecAddress < memoryOffset))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	prevInterruptCheckChain = setInterruptCheckChain(forceStopOnInterrupt);
	if (prevInterruptCheckChain == forceStopOnInterrupt) {
		prevInterruptCheckChain = 0;
	}
	memorySize = byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize));
	maybeErr = runCPUInSizeMinAddressReadWrite(cpu, memory - memoryOffset, (((memorySize + memoryOffset) < maxAddress) ? (memorySize + memoryOffset) : maxAddress), minAddress, minWriteMaxExecAddress);
	setInterruptCheckChain(prevInterruptCheckChain);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		methodReturnValue(cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	Run the cpu using the first argument as the memory and the following
	arguments defining valid addresses, running until it halts or hits an
	exception. 
 */

	/* ProcessorSimulatorPlugin>>#primitiveRunInMemory:minimumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveRunInMemoryMinimumAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;
	char *memory;
	sqInt minAddress;
	sqInt minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(2)))
		 && ((isIntegerObject((minAddress = stackValue(1))))
		 && (isIntegerObject((minWriteMaxExecAddress = stackValue(0))))))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	memory = ((char *) (firstIndexableField(stackValue(2))));
	minAddress = integerValueOf(minAddress);
	minWriteMaxExecAddress = integerValueOf(minWriteMaxExecAddress);
	cpuAlien = stackValue(3);
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if ((minAddress < memoryOffset)
	 || (minWriteMaxExecAddress < memoryOffset)) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	prevInterruptCheckChain = setInterruptCheckChain(forceStopOnInterrupt);
	if (prevInterruptCheckChain == forceStopOnInterrupt) {
		prevInterruptCheckChain = 0;
	}
	maybeErr = runCPUInSizeMinAddressReadWrite(cpu, memory - memoryOffset, (byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize))) + memoryOffset, minAddress, minWriteMaxExecAddress);
	setInterruptCheckChain(prevInterruptCheckChain);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		methodReturnValue(cpuAlien);
	}
	return null;
}


/*	cpuAlien <ProcessorSimulatorAlien> */
/*	<BitsObject> */
/*	<Integer> */
/*	<Integer> */
/*	<Integer> */
/*	Run the cpu using the first argument as the memory and the following
	arguments defining valid addresses, running until it halts or hits an
	exception. 
 */

	/* ProcessorSimulatorPlugin>>#primitiveRunInMemory:offsetBy:minimumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveRunInMemoryOffsetMinimumAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;
	char *memory;
	sqInt minAddress;
	sqInt minWriteMaxExecAddress;
	sqInt offset;

	if (!((isWordsOrBytes(stackValue(3)))
		 && ((isIntegerObject((offset = stackValue(2))))
		 && ((isIntegerObject((minAddress = stackValue(1))))
		 && (isIntegerObject((minWriteMaxExecAddress = stackValue(0)))))))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	memory = ((char *) (firstIndexableField(stackValue(3))));
	offset = integerValueOf(offset);
	minAddress = integerValueOf(minAddress);
	minWriteMaxExecAddress = integerValueOf(minWriteMaxExecAddress);
	cpuAlien = stackValue(4);
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if ((minAddress < memoryOffset)
	 || (minWriteMaxExecAddress < memoryOffset)) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	prevInterruptCheckChain = setInterruptCheckChain(forceStopOnInterrupt);
	if (prevInterruptCheckChain == forceStopOnInterrupt) {
		prevInterruptCheckChain = 0;
	}
	maybeErr = runCPUInSizeMinAddressReadWrite(cpu, ((((char *) memory)) - memoryOffset) + offset, ((byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize))) + memoryOffset) - offset, minAddress, minWriteMaxExecAddress);
	setInterruptCheckChain(prevInterruptCheckChain);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		methodReturnValue(cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	<Integer> */
/*	Single-step the cpu using the first argument as the memory and the
	following arguments defining valid addresses.
 */

	/* ProcessorSimulatorPlugin>>#primitiveSingleStepInMemory:minimumAddress:maximumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maxAddress;
	sqInt maybeErr;
	char *memory;
	sqInt memorySize;
	sqInt minAddress;
	sqInt minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(3)))
		 && ((isIntegerObject((minAddress = stackValue(2))))
		 && ((isIntegerObject((maxAddress = stackValue(1))))
		 && (isIntegerObject((minWriteMaxExecAddress = stackValue(0)))))))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	memory = ((char *) (firstIndexableField(stackValue(3))));
	minAddress = integerValueOf(minAddress);
	maxAddress = integerValueOf(maxAddress);
	minWriteMaxExecAddress = integerValueOf(minWriteMaxExecAddress);
	cpuAlien = stackValue(4);
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if ((minAddress < memoryOffset)
	 || ((maxAddress < memoryOffset)
	 || (minWriteMaxExecAddress < memoryOffset))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	memorySize = byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize));
	maybeErr = singleStepCPUInSizeMinAddressReadWrite(cpu, memory - memoryOffset, (((memorySize + memoryOffset) < maxAddress) ? (memorySize + memoryOffset) : maxAddress), minAddress, minWriteMaxExecAddress);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		methodReturnValue(cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	Single-step the cpu using the first argument as the memory and the
	following arguments defining valid addresses.
 */

	/* ProcessorSimulatorPlugin>>#primitiveSingleStepInMemory:minimumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveSingleStepInMemoryMinimumAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;
	char *memory;
	sqInt minAddress;
	sqInt minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(2)))
		 && ((isIntegerObject((minAddress = stackValue(1))))
		 && (isIntegerObject((minWriteMaxExecAddress = stackValue(0))))))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	memory = ((char *) (firstIndexableField(stackValue(2))));
	minAddress = integerValueOf(minAddress);
	minWriteMaxExecAddress = integerValueOf(minWriteMaxExecAddress);
	cpuAlien = stackValue(3);
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if ((minAddress < memoryOffset)
	 || (minWriteMaxExecAddress < memoryOffset)) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	maybeErr = singleStepCPUInSizeMinAddressReadWrite(cpu, memory - memoryOffset, (byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize))) + memoryOffset, minAddress, minWriteMaxExecAddress);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		methodReturnValue(cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	<Integer> */
/*	Single-step the cpu using the first argument as the memory and the
	following arguments defining valid addresses.
 */

	/* ProcessorSimulatorPlugin>>#primitiveSingleStepInMemory:offsetBy:minimumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveSingleStepInMemoryOffsetMinimumAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;
	char *memory;
	sqInt minAddress;
	sqInt minWriteMaxExecAddress;
	sqInt offset;

	if (!((isWordsOrBytes(stackValue(3)))
		 && ((isIntegerObject((offset = stackValue(2))))
		 && ((isIntegerObject((minAddress = stackValue(1))))
		 && (isIntegerObject((minWriteMaxExecAddress = stackValue(0)))))))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	memory = ((char *) (firstIndexableField(stackValue(3))));
	offset = integerValueOf(offset);
	minAddress = integerValueOf(minAddress);
	minWriteMaxExecAddress = integerValueOf(minWriteMaxExecAddress);
	cpuAlien = stackValue(4);
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if ((minAddress < memoryOffset)
	 || (minWriteMaxExecAddress < memoryOffset)) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	maybeErr = singleStepCPUInSizeMinAddressReadWrite(cpu, ((((char *) memory)) - memoryOffset) + offset, ((byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize))) - offset) + memoryOffset, minAddress, minWriteMaxExecAddress);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		methodReturnValue(cpuAlien);
	}
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
	sqInt ok;


	/* This may seem tautological, but in a real plugin it checks that the VM provides
	   the version the plugin was compiled against which is the version the plugin expects. */
	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		byteSizeOf = interpreterProxy->byteSizeOf;
		classArray = interpreterProxy->classArray;
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 16)
		classDoubleWordArray = interpreterProxy->classDoubleWordArray;
#else
#if !defined(classDoubleWordArray)
		classDoubleWordArray = 0;
#endif
#endif
		classString = interpreterProxy->classString;
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 16)
		classWordArray = interpreterProxy->classWordArray;
#else
#if !defined(classWordArray)
		classWordArray = 0;
#endif
#endif
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		getInterruptPending = interpreterProxy->getInterruptPending;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
#if !defined(integerValueOf)
		integerValueOf = interpreterProxy->integerValueOf;
#endif
#if !defined(isIntegerObject)
		isIntegerObject = interpreterProxy->isIntegerObject;
#endif
		isWordsOrBytes = interpreterProxy->isWordsOrBytes;
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		methodReturnInteger = interpreterProxy->methodReturnInteger;
		methodReturnValue = interpreterProxy->methodReturnValue;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		popRemappableOop = interpreterProxy->popRemappableOop;
		positive32BitIntegerFor = interpreterProxy->positive32BitIntegerFor;
		positive64BitIntegerFor = interpreterProxy->positive64BitIntegerFor;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 14)
		primitiveFailForOSError = interpreterProxy->primitiveFailForOSError;
#else
#if !defined(primitiveFailForOSError)
		primitiveFailForOSError = 0;
#endif
#endif
		pushRemappableOop = interpreterProxy->pushRemappableOop;
		setInterruptCheckChain = interpreterProxy->setInterruptCheckChain;
		stackValue = interpreterProxy->stackValue;
		storeIntegerofObjectwithValue = interpreterProxy->storeIntegerofObjectwithValue;
		storePointerofObjectwithValue = interpreterProxy->storePointerofObjectwithValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


/*	Answer the size field of an alienOop which is assumed to be an Alien of at
	least 8 bytes (32-bits) or 16 bytes (64 bits)
 */

	/* InterpreterPlugin>>#sizeField: */
static sqInt
sizeField(sqInt alienOop)
{
	return longAt(alienOop + BaseHeaderSize);
}


/*	Answer the start of an Alien's data. For direct aliens this is the address
	of the second field.
	For indirect and pointer aliens it is what the second field points to. */

	/* InterpreterPlugin>>#startOfData: */
static sqInt
startOfData(sqInt alienOop)
{
	return ((longAt(alienOop + BaseHeaderSize)) > 0
		? (alienOop + BaseHeaderSize) + BytesPerOop
		: longAt((alienOop + BaseHeaderSize) + BytesPerOop));
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "RiscVPlugin";
void* RiscVPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveDisassembleAtInMemory\000\000\000", (void*)primitiveDisassembleAtInMemory},
	{(void*)_m, "primitiveErrorAndLog\000\377\000", (void*)primitiveErrorAndLog},
	{(void*)_m, "primitiveFlushICacheFromTo\000\000\000", (void*)primitiveFlushICacheFromTo},
	{(void*)_m, "primitiveIntegerRegisterState\000\000\000", (void*)primitiveIntegerRegisterState},
	{(void*)_m, "primitiveMemoryOffset\000\000\001", (void*)primitiveMemoryOffset},
	{(void*)_m, "primitiveNewCPU\000\377\000", (void*)primitiveNewCPU},
	{(void*)_m, "primitiveResetCPU\000\000\000", (void*)primitiveResetCPU},
	{(void*)_m, "primitiveRunInMemoryMinAddressMaxAddressReadWrite\000\000\000", (void*)primitiveRunInMemoryMinAddressMaxAddressReadWrite},
	{(void*)_m, "primitiveRunInMemoryMinimumAddressReadWrite\000\000\000", (void*)primitiveRunInMemoryMinimumAddressReadWrite},
	{(void*)_m, "primitiveRunInMemoryOffsetMinimumAddressReadWrite\000\000\000", (void*)primitiveRunInMemoryOffsetMinimumAddressReadWrite},
	{(void*)_m, "primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite\000\000\000", (void*)primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite},
	{(void*)_m, "primitiveSingleStepInMemoryMinimumAddressReadWrite\000\000\000", (void*)primitiveSingleStepInMemoryMinimumAddressReadWrite},
	{(void*)_m, "primitiveSingleStepInMemoryOffsetMinimumAddressReadWrite\000\000\000", (void*)primitiveSingleStepInMemoryOffsetMinimumAddressReadWrite},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else // ifdef SQ_BUILTIN_PLUGIN

#if SPURVM
EXPORT(signed short) primitiveDisassembleAtInMemoryMetadata = 0;
EXPORT(signed short) primitiveFlushICacheFromToMetadata = 0;
EXPORT(signed short) primitiveIntegerRegisterStateMetadata = 0;
EXPORT(signed short) primitiveMemoryOffsetMetadata = 1;
EXPORT(signed short) primitiveResetCPUMetadata = 0;
EXPORT(signed short) primitiveRunInMemoryMinAddressMaxAddressReadWriteMetadata = 0;
EXPORT(signed short) primitiveRunInMemoryMinimumAddressReadWriteMetadata = 0;
EXPORT(signed short) primitiveRunInMemoryOffsetMinimumAddressReadWriteMetadata = 0;
EXPORT(signed short) primitiveSingleStepInMemoryMinAddressMaxAddressReadWriteMetadata = 0;
EXPORT(signed short) primitiveSingleStepInMemoryMinimumAddressReadWriteMetadata = 0;
EXPORT(signed short) primitiveSingleStepInMemoryOffsetMinimumAddressReadWriteMetadata = 0;
#endif // SPURVM

#endif // ifdef SQ_BUILTIN_PLUGIN
