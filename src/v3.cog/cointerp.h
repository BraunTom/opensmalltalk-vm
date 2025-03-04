/* Automatically generated by
	CCodeGeneratorGlobalStructure VMMaker.oscog-eem.3183 uuid: c5c103b4-2c5c-44e7-8e32-030e79600ca6
 */


/*** Function Prototypes ***/


#if !PRODUCTION && defined(PlatformNoDbgRegParms)
# define NoDbgRegParms PlatformNoDbgRegParms
#endif

#if !defined(NoDbgRegParms)
# define NoDbgRegParms /*empty*/
#endif



#if !defined(NeverInline)
# define NeverInline /*empty*/
#endif

extern usqInt argumentCountAddress(void);
extern void assertValidMachineCodeFrame(sqInt instrPtr);
extern void callForCogCompiledCodeCompaction(void);
extern void ceActivateFailingPrimitiveMethod(sqInt aPrimitiveMethod);
extern sqInt ceActiveContext(void);
extern sqInt ceBaseFrameReturn(sqInt returnValue);
#if IMMUTABILITY
extern sqInt ceCannotAssignTowithIndexvalueToAssign(sqInt immutableObject, sqInt index, sqInt valueToAssign);
#endif /* IMMUTABILITY */
extern sqInt ceCannotResume(void);
extern void ceCheckForInterrupt(void);
extern sqInt ceContextinstVar(sqInt maybeContext, sqInt slotIndex);
extern sqInt ceContextinstVarvalue(sqInt maybeMarriedContext, sqInt slotIndex, sqInt anOop);
extern sqInt ceInterpretMethodFromPICreceiver(sqInt aMethodObj, sqInt rcvr);
extern sqInt ceMNUFromPICMNUMethodreceiver(sqInt aMethodObj, sqInt rcvr);
extern sqInt ceNewArraySlotSize(sqInt slotSize);
extern sqInt ceNonLocalReturn(sqInt returnValue);
extern void ceReapAndResetErrorCodeFor(CogMethod *cogMethod);
extern sqInt ceSendAborttonumArgs(sqInt selector, sqInt rcvr, sqInt numArgs);
extern sqInt ceSendFromInLineCacheMiss(CogMethod *cogMethodOrPIC);
extern sqInt ceSendMustBeBooleanTointerpretingAtDelta(sqInt aNonBooleanObject, sqInt jumpSize);
extern sqInt ceSendMustBeBoolean(sqInt anObject);
extern sqInt ceSendsupertonumArgs(sqInt selector, sqInt superNormalBar, sqInt rcvr, sqInt numArgs);
extern void ceStackOverflow(sqInt contextSwitchIfNotNil);
extern void ceTakeProfileSample(CogMethod *aCogMethodOrNil);
extern void ceTraceBlockActivation(void);
extern void ceTraceLinkedSend(sqInt theReceiver);
extern void ceTraceStoreOfinto(sqInt aValue, sqInt anObject);
extern usqInt cFramePointerAddress(void);
extern void checkAssertsEnabledInCoInterpreter(void);
extern sqInt checkIfCFramePointerInUse(void);
extern void clearTraceLog(void);
extern CogMethod * cogMethodOf(sqInt aMethodOop);
extern void compilationBreakpointFor(sqInt selectorOop);
extern usqInt cReturnAddressAddress(void);
extern sqInt createClosureNumArgsnumCopiedstartpc(sqInt numArgs, sqInt numCopied, sqInt initialIP);
extern usqInt cStackPointerAddress(void);
extern sqInt defaultNativeStackFrameSize(void);
extern void dumpPrimTraceLog(void);
extern void executeCogMethodfromLinkedSendWithReceiver(CogMethod *cogMethod, sqInt rcvr);
extern void executeCogPICfromLinkedSendWithReceiverandCacheTag(CogMethod *cogPIC, sqInt rcvr, sqInt cacheTag);
extern usqInt framePointerAddress(void);
extern void (*functionPointerForCompiledMethodprimitiveIndexprimitivePropertyFlagsInto(sqInt methodObj, sqInt primitiveIndex, sqInt *flagsPtr))(void);
extern void ifValidWriteBackStackPointersSaveTo(void *theCFP, void *theCSP, char **savedFPP, char **savedSPP);
extern usqInt instructionPointerAddress(void);
extern sqInt interpret(void);
extern usqInt interpretAddress(void);
extern sqInt isCogMethodReference(sqInt methodHeader);
extern sqInt lookupMNUreceiver(sqInt selector, sqInt rcvr);
extern sqInt lookupOrdinaryreceiver(sqInt selector, sqInt rcvr);
extern void markActiveMethodsAndReferents(void);
extern sqInt marryFrameCopiesTemps(void);
extern sqInt maxLookupNoMNUErrorCode(void);
extern usqInt methodCacheAddress(void);
extern sqInt methodHasCogMethod(sqInt aMethodOop);
extern sqInt methodNeedsLargeContext(sqInt methodObj);
extern sqInt methodShouldBeCogged(sqInt aMethodObj);
extern CogMethod * mframeHomeMethodExport(void);
extern CogMethod * mframeHomeMethod(char *theFP);
extern sqInt mMethodClass(void);
extern void mnuCompilationBreakpointFor(sqInt selectorOop);
extern usqInt newMethodAddress(void);
extern usqInt nextProfileTickAddress(void);
extern sqInt noAssertHeaderOf(sqInt methodPointer);
extern sqInt positive32BitIntegerFor(unsigned int integerValue);
extern unsigned int positive32BitValueOf(sqInt oop);
extern sqInt positive64BitIntegerFor(usqLong integerValue);
extern usqLong positive64BitValueOf(sqInt oop);
extern usqInt primFailCodeAddress(void);
extern usqInt primitiveFailAddress(void);
extern sqInt primitivePropertyFlagsnumArgs(sqInt primIndex, sqInt numArgs);
extern void * primTraceLogAddress(void);
extern usqInt primTraceLogIndexAddress(void);
EXPORT(void) printCogMethod(CogMethod *cogMethod);
extern sqInt quickPrimitiveConstantFor(sqInt aQuickPrimitiveIndex);
extern sqInt (*quickPrimitiveGeneratorFor(sqInt aQuickPrimitiveIndex))(void);
extern sqInt quickPrimitiveInstVarIndexFor(sqInt primIndex);
extern sqInt rawHeaderOf(sqInt methodPointer);
extern void rawHeaderOfput(sqInt methodOop, sqInt cogMethodOrMethodHeader);
extern sqInt recordFastCCallPrimTraceForMethod(sqInt aMethodObj);
extern sqInt recordPrimTraceForMethod(sqInt aMethodObj);
extern sqInt signed32BitIntegerFor(sqInt integerValue);
extern int signed32BitValueOf(sqInt oop);
extern sqInt signed64BitIntegerFor(sqLong integerValue);
extern sqLong signed64BitValueOf(sqInt oop);
extern sqInt specialSelectorNumArgs(sqInt index);
extern usqInt stackLimitAddress(void);
extern usqInt stackPointerAddress(void);
extern sqInt startPCOfMethodHeader(sqInt aCompiledMethodHeader);
extern sqInt startPCOrNilOfLiteralin(sqInt lit, sqInt aMethodObj);
extern void updateStackZoneReferencesToCompiledCodePreCompaction(void);
extern usqInt primitiveFunctionPointerAddress(void);
extern char * cStringOrNullFor(sqInt oop);
extern sqInt failed(void);
extern sqInt identityHashOf(sqInt anOop);
extern void primitiveClosureValueNoContextSwitch(void);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailForFFIExceptionat(usqLong exceptionCode, usqInt pc);
extern sqInt primitiveFailForOSError(sqLong osErrorCode);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt primitiveFailForwithSecondary(sqInt reasonCode, sqLong extraErrorCode);
extern sqInt primitiveFailureCode(void);
extern sqInt signalNoResume(sqInt aSemaphore);
extern usqInt sizeOfAlienData(sqInt oop);
extern void * startOfAlienData(sqInt oop);
extern sqInt ceStoreCheck(sqInt anOop);
extern usqInt freeStartAddress(void);
extern sqInt isReallyYoungObject(sqInt obj);
extern sqInt methodHeaderOf(sqInt methodObj);
extern sqInt noShiftCompactClassIndexOf(sqInt oop);
extern sqInt nullHeaderForMachineCodeMethod(void);
extern sqInt receiverTagBitsForMethod(sqInt aMethodObj);
extern usqInt scavengeThresholdAddress(void);
extern sqInt smallIntegerTag(void);
extern sqInt withoutForwardingOnandwithsendToCogit(sqInt obj1, sqInt obj2, sqInt aBool, sqInt (*selector)(sqInt,sqInt,sqInt));
extern usqInt youngStartAddress(void);
extern sqInt addressCouldBeObj(sqInt address);
extern sqInt characterValueOf(sqInt oop);
extern sqInt checkOkayOop(usqInt oop);
extern sqInt eeInstantiateClassIndexformatnumSlots(sqInt compactClassIndex, sqInt objFormat, sqInt numSlots);
extern sqInt eeInstantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt fetchClassTagOf(sqInt oop);
extern void findStringBeginningWith(char *aCString);
extern void findString(char *aCString);
extern double floatValueOf(sqInt oop);
extern sqInt isYoungObject(sqInt obj);
extern sqInt lastPointerOf(sqInt objOop);
extern sqInt leakCheckBecome(void);
extern sqInt leakCheckFullGC(void);
extern sqInt leakCheckNewSpaceGC(void);
extern sqInt literalCountOfMethodHeader(sqInt methodHeader);
extern sqInt objectAfter(sqInt oop);
extern sqInt pinObject(sqInt objOop);
extern sqInt safeLastPointerOf(sqInt objOop);
extern sqInt shortentoIndexableSize(sqInt obj, sqInt nSlots);
extern void unpinObject(sqInt objOop);
extern sqInt addressCouldBeOop(sqInt address);
extern sqInt arrayFormat(void);
extern void beRootIfOld(sqInt oop);
extern sqInt byteSizeOf(sqInt oop);
extern unsigned int byteSwapped32IfBigEndian(unsigned int w);
extern unsigned long long byteSwapped64IfBigEndian(unsigned long long w);
extern sqInt byteSwapped(sqInt w);
extern sqInt characterObjectOf(sqInt characterCode);
extern sqInt characterTable(void);
extern sqInt checkedLongAt(sqInt byteAddress);
extern sqInt checkOopHasOkayClass(usqInt obj);
extern sqInt classArray(void);
extern sqInt classFloat(void);
extern sqInt classHeader(sqInt oop);
extern sqInt classSmallInteger(void);
extern sqInt compactClassAt(sqInt ccIndex);
extern sqInt compactClassIndexOfClass(sqInt classObj);
extern sqInt compactClassIndexOfHeader(sqInt header);
extern sqInt compactClassIndexOf(sqInt oop);
extern sqInt falseObject(void);
extern sqInt fetchByteofObject(sqInt byteIndex, sqInt oop);
extern sqInt fetchPointerofObject(sqInt fieldIndex, sqInt oop);
extern sqInt formatOfClass(sqInt classPointer);
extern sqInt headerIndicatesAlternateBytecodeSet(sqInt methodHeader);
extern sqInt instanceSizeOf(sqInt classObj);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt isArrayNonImm(sqInt oop);
extern sqInt isCharacterValue(sqInt anInteger);
extern sqInt isCompiledMethod(sqInt oop);
extern sqInt isImmediate(sqInt anOop);
extern sqInt isIntegerValue(sqInt intValue);
extern sqInt isMarked(sqInt oop);
extern sqInt isNonImmediate(sqInt anOop);
extern sqInt isNonIntegerObject(sqInt objectPointer);
extern sqInt isOopCompiledMethod(sqInt oop);
extern sqInt isOopImmutable(sqInt anOop);
extern sqInt isOopMutable(sqInt anOop);
extern sqInt isPinned(sqInt objOop);
extern sqInt isYoung(sqInt oop);
extern sqInt literalCountOf(sqInt methodPointer);
extern sqInt markAndTrace(sqInt oop);
extern sqInt maybeSplObj(sqInt index);
extern sqInt minSlotsForShortening(void);
extern sqInt nilObject(void);
extern sqInt noShiftCompactClassIndexOfHeader(sqInt header);
extern sqInt numBytesOfBytes(sqInt objOop);
extern sqInt numBytesOf(sqInt objOop);
extern sqInt numSlotsOf(sqInt obj);
extern sqInt objectBefore(sqInt address);
extern sqInt objectExactlyBefore(sqInt oop);
extern sqInt popRemappableOop(void);
extern sqInt primitiveErrorTable(void);
extern void pushRemappableOop(sqInt oop);
extern sqInt remap(sqInt oop);
extern sqInt shouldRemapObj(sqInt oop);
extern sqInt shouldRemapOop(sqInt oop);
extern sqInt splObj(sqInt index);
extern sqInt storePointerUncheckedofObjectwithValue(sqInt fieldIndex, sqInt oop, sqInt valuePointer);
extern sqInt stringForCString(const char *aCString);
extern void tenuringIncrementalGC(void);
extern sqInt topRemappableOop(void);
extern sqInt trueObject(void);
extern void addIdleUsecs(sqInt idleUsecs);
extern sqInt argumentCountOfClosure(sqInt closurePointer);
extern sqInt argumentCountOfMethodHeader(sqInt header);
extern sqInt argumentCountOf(sqInt methodPointer);
extern sqInt canContextSwitchIfActivatingheader(sqInt theMethod, sqInt methodHeader);
extern sqInt copiedValueCountOfClosure(sqInt closurePointer);
extern sqInt copiedValueCountOfFullClosure(sqInt closurePointer);
extern sqInt disownVM(sqInt flags);
extern sqInt doSignalSemaphoreWithIndex(sqInt index);
extern void NeverInline eekcr(void);
extern void flush(void);
extern void (*functionPointerForinClass(sqInt primIdx,sqInt theClass))(void);
extern usqLong getNextWakeupUsecs(void);
extern sqInt * getStackPointer(void);
extern FILE * getTranscript(void);
extern sqInt highBit(usqInt anUnsignedValue);
extern sqInt isFloatObject(sqInt oop);
extern sqInt isKindOfInteger(sqInt oop);
extern sqInt isLargeIntegerObject(sqInt oop);
extern sqInt isLargeNegativeIntegerObject(sqInt oop);
extern sqInt isLargePositiveIntegerObject(sqInt oop);
extern sqInt isQuickPrimitiveIndex(sqInt anInteger);
extern sqInt isReadMediatedContextInstVarIndex(sqInt index);
extern sqInt isWriteMediatedContextInstVarIndex(sqInt index);
extern sqInt isKindOfClass(sqInt oop, sqInt aClass);
extern sqInt literalofMethod(sqInt offset, sqInt methodPointer);
extern sqInt longStoreBytecodeForHeader(sqInt methodHeader);
extern sqInt lookupSelectorinClass(sqInt selector, sqInt class);
extern sqInt maybeSelectorOfMethod(sqInt methodObj);
extern sqInt methodClassAssociationOf(sqInt methodPointer);
extern sqInt methodClassOf(sqInt methodPointer);
extern sqInt methodPrimitiveIndex(void);
extern sqInt methodUsesAlternateBytecodeSet(sqInt aMethodObj);
extern sqInt objCouldBeClassObj(sqInt objOop);
extern sqInt ownVM(sqInt threadIndexAndFlags);
extern sqInt penultimateLiteralOf(sqInt aMethodOop);
extern sqInt popStack(void);
extern sqInt primitiveIndexOfMethodheader(sqInt theMethod, sqInt methodHeader);
extern sqInt primitiveIndexOf(sqInt methodPointer);
extern sqInt printHexnp(usqInt n);
extern void printHex(usqInt n);
extern void print(char *s);
extern sqInt readableFormat(sqInt imageVersion);
extern void setNextWakeupUsecs(usqLong value);
extern sqInt sizeOfCallPrimitiveBytecode(sqInt methodHeader);
extern sqInt sizeOfLongStoreTempBytecode(sqInt methodHeader);
extern sqInt specialSelector(sqInt index);
extern usqIntptr_t stackPositiveMachineIntegerValue(sqInt offset);
extern sqIntptr_t stackSignedMachineIntegerValue(sqInt offset);
extern sqInt stackTop(void);
extern sqInt stackValue(sqInt offset);
extern sqInt startPCOfMethod(sqInt aCompiledMethod);
extern sqInt tempCountOf(sqInt methodPointer);
extern sqInt temporaryCountOfMethodHeader(sqInt header);
extern sqInt ultimateLiteralOf(sqInt aMethodOop);


/*** Global Variables ***/
extern sqInt breakLookupClassTag;
extern char * breakSelector;
extern sqInt breakSelectorLength ;
extern sqInt checkedPluginName;
extern sqInt checkForLeaks;
extern sqInt debugCallbackInvokes;
extern sqInt debugCallbackPath;
extern sqInt debugCallbackReturns;
extern sqInt deferDisplayUpdates;
extern sqInt desiredCogCodeSize;
extern sqInt desiredEdenBytes;
extern sqInt desiredNumStackPages;
extern void * displayBits;
extern int displayDepth;
extern int displayHeight;
extern int displayWidth;
extern sqInt eventTraceMask;
extern sqInt extraVMMemory;
extern sqInt ffiExceptionResponse;
extern usqInt heapBase;
extern sqInt inIOProcessEvents;
extern struct VirtualMachine* interpreterProxy;
extern sqInt maxLiteralCountForCompile ;
extern sqInt minBackwardJumpCountForCompile ;
extern sqInt primitiveDoMixedArithmetic;
extern char * primTracePluginName;
extern volatile int sendTrace;
extern sqInt sendWheelEvents;
extern int (*showSurfaceFn)(sqIntptr_t, int, int, int, int);
extern sqInt suppressHeartbeatFlag;


/*** Macros ***/
#define compilationBreakpointclassTagisMNUCase(sel, classTag, isMNU) do { \
	if (numBytesOf(sel) == (isMNU ? -breakSelectorLength : breakSelectorLength) \
	 && !strncmp((char *)((sel) + BaseHeaderSize), breakSelector, (isMNU ? -breakSelectorLength : breakSelectorLength))) { \
		suppressHeartbeatFlag = 1; \
		compilationBreakpointFor(sel); \
	} \
} while (0)
#define compilationBreakpointisMNUCase(sel, isMNU) do { \
	if (numBytesOf(sel) == (isMNU ? -breakSelectorLength : breakSelectorLength) \
	 && !strncmp((char *)((sel) + BaseHeaderSize), breakSelector, (isMNU ? -breakSelectorLength : breakSelectorLength))) { \
		suppressHeartbeatFlag = 1; \
		compilationBreakpointFor(sel); \
	} \
} while (0)
#define mnuCompilationBreakpoint(sel, len) do { \
	if ((len) == -breakSelectorLength \
	 && !strncmp((char *)((sel) + BaseHeaderSize), breakSelector, -breakSelectorLength)) { \
		suppressHeartbeatFlag = 1; \
		compilationBreakpointFor(sel); \
	} \
} while (0)
#define classFieldOffset() (0 - BaseHeaderSize)
#define compactClassFieldWidth() 5
#define instFormatFieldLSB() 8
#define instFormatFieldWidth() 4
#define compactClassFieldLSB() 12
#define firstByteFormat() 8
#define firstCompiledMethodFormat() 12
#define firstLongFormat() 6
#define indexablePointersFormat() 3
#define isForwarded(oop) false
#define shiftForWord() 2
#define weakArrayFormat() 4
#define alternateHeaderNumLiteralsMask() 0x7FFF
#define primitiveDoMixedArithmetic() primitiveDoMixedArithmetic
#define remoteIsInstVarAccess() 128


/*** Constants ***/
#define ActiveProcessIndex 1
#define BytecodeSetHasDirectedSuperSend 0
#define BytecodeSetHasExtensions 0
#define CharacterTable 24
#define CharacterValueIndex 0
#define ClassAlien 52
#define ClassArray 7
#define ClassArrayCompactIndex 3
#define ClassBitmap 4
#define ClassBitmapCompactIndex 0
#define ClassBlockClosure 36
#define ClassBlockClosureCompactIndex 0
#define ClassBlockContext 11
#define ClassBlockContextCompactIndex 13
#define ClassByteArray 26
#define ClassByteArrayCompactIndex 0
#define ClassByteString 6
#define ClassByteStringCompactIndex 11
#define ClassCharacter 19
#define ClassDoubleByteArray 31
#define ClassDoubleWordArray 33
#define ClassExternalAddress 43
#define ClassExternalData 45
#define ClassExternalFunction 46
#define ClassExternalLibrary 47
#define ClassExternalStructure 44
#define ClassFloat 9
#define ClassFloatCompactIndex 6
#define ClassFullBlockClosure 37
#define ClassFullBlockClosureCompactIndex 38
#define ClassLargeNegativeInteger 42
#define ClassLargeNegativeIntegerCompactIndex 4
#define ClassLargePositiveInteger 13
#define ClassLargePositiveIntegerCompactIndex 5
#define ClassMessage 15
#define ClassMessageCompactIndex 0
#define ClassMethodContext 10
#define ClassMethodContextCompactIndex 14
#define ClassPoint 12
#define ClassPointCompactIndex 0
#define ClassSemaphore 18
#define ClassSmallInteger 5
#define ClassString 6
#define ClassUnsafeAlien 54
#define ClassWeakFinalizer 55
#define ClassWordArray 32
#define ClosureFirstCopiedValueIndex 3
#define ClosureIndex 4
#define ClosureNumArgsIndex 2
#define ClosureOuterContextIndex 0
#define ClosureStartPCIndex 1
#define CMBlock 3
#define CMClosedPIC 4
#define CMFree 1
#define CMMaxUsageCount 7
#define CMMethod 2
#define CMOpenPIC 5
#define CompactClasses 28
#define CompletePrimitive 4
#define ConstMinusOne 0xFFFFFFFFU
#define ConstOne 3
#define ConstTwo 5
#define ConstZero 1
#define CtxtTempFrameStart 6
#define DisownVMForFFICall 16
#define DisownVMForThreading 32
#define DoAssertionChecks (!PRODUCTION)
#define DoExpensiveAssertionChecks 0
#define EncounteredUnknownBytecode -6
#define ExcessSignalsIndex 2
#define ExternalObjectsArray 38
#define FalseObject 1
#define FastCPrimitiveAlignForFloatsFlag 2
#define FastCPrimitiveFlag 1
#define FirstLinkIndex 0
#define ForeignCallbackProcess 56
#undef FoxCallerContext
#define FoxCallerSavedIP 4
#undef FoxFrameFlags
#define FoxIFReceiver -20
#define FoxIFrameFlags -12
#define FoxIFSavedIP -16
#define FoxMethod -4
#define FoxMFReceiver -12
#undef FoxReceiver
#define FoxSavedFP 0
#define FoxThisContext -8
#undef FrameSlots
#define FullClosureCompiledBlockIndex 1
#define FullClosureFirstCopiedValueIndex 4
#define FullClosureReceiverIndex 3
#define GCCheckFreeSpace 32
#define GCCheckImageSegment 16
#define GCCheckPrimCall 128
#define GCCheckShorten 64
#define GCModeBecome 8
#define GCModeFull 1
#define GCModeIncremental 4
#define GCModeNewSpace 2
#define HashMultiplyConstant 1664525
#define HashMultiplyMask 0xFFFFFFF
#define HeaderIndex 0
#define IFrameSlots 7
#define InstanceSpecificationIndex 2
#define InstructionPointerIndex 1
#define InsufficientCodeSpace -2
#define KeyIndex 0
#define LargeContextBit 0x40000
#define LargeContextSize bogus
#define LargeContextSlots 62
#define LastLinkIndex 1
#define LiteralStart 1
#define LookupRuleDynamicSuper 0x101
#define LookupRuleImplicit 0x100
#define LookupRuleMNU 259
#define LookupRuleOrdinary 258
#define LookupRuleSelf 0
#define LowcodeContextMark 60
#define LowcodeNativeContextClass 61
#define MaxLiteralCountForCompile 60
#define MaxMethodSize 65535
#define MaxNegativeErrorCode -8
#define MaxNumArgs 15
#define MaxStackCheckOffset 0xFFF
#define MessageArgumentsIndex 1
#define MessageLookupClassIndex 2
#define MessageSelectorIndex 0
#define MethodArrayIndex 1
#define MethodCacheClass 2
#define MethodCacheEntries 0x400
#define MethodCacheEntrySize 4
#define MethodCacheMask 0xFFC
#define MethodCacheMethod 3
#define MethodCachePrim null
#define MethodCachePrimFunction 4
#define MethodCacheSelector 1
#define MethodCacheSize 4096
#define MethodDictionaryIndex 1
#define MethodIndex 3
#define MethodTooBig -4
#define MFMethodFlagHasContextFlag 1
#define MFMethodFlagIsBlockFlag 2
#define MFMethodFlagsMask 0x7
#define MFMethodMask -0x8
#define MFrameSlots 5
#define MyListIndex 3
#define NewsqueakV4BytecodeSet 0
#define NextLinkIndex 0
#define NilObject 0
#define NotFullyInitialized -1
#define NSMethodCacheActualReceiver 7
#define NSMethodCacheCallingMethod 3
#define NSMethodCacheClassTag 2
#define NSMethodCacheDepthOrLookupRule 4
#define NSMethodCacheEntries 0x200
#define NSMethodCacheEntrySize 8
#define NSMethodCacheMask 0xFF8
#define NSMethodCachePrimFunction 6
#define NSMethodCacheSelector 1
#define NSMethodCacheSize 4096
#define NSMethodCacheTargetMethod 5
#define PrimCallCollectsProfileSamples 16
#define PrimCallIsExternalCall 32
#define PrimCallMayEndureCodeCompaction 8
#define PrimCallNeedsNewMethod 4
#define PrimCallOnSmalltalkStack 1
#define PrimCallOnSmalltalkStackAlign2x 2
#define PrimitiveErrorTableIndex 51
#define PrimNumberExternalCall 117
#define PrimNumberFFICall 120
#define PrimNumberHandlerMarker 199
#define PrimNumberNoContextSwitchMarker 123
#define PrimNumberUnwindMarker 198
#define PriorityIndex 2
#define ProcessInExternalCodeTag 40
#define ProcessListsIndex 0
#define ProcessSignalingLowSpace 22
#define ReceiverIndex 5
#define SchedulerAssociation 3
#define SelectorAboutToReturn 48
#define SelectorAttemptToAssign 50
#define SelectorCannotInterpret 34
#define SelectorCannotReturn 21
#define SelectorCounterTripped 58
#define SelectorDoesNotUnderstand 20
#define SelectorInvokeCallback 53
#define SelectorMustBeBoolean 25
#define SelectorRunWithIn 49
#define SelectorSistaTrap 59
#define SelectorStart 2
#define SelectorUnknownBytecode 57
#define SenderIndex 0
#define ShouldNotJIT -8
#define SistaV1BytecodeSet 0
#define SmallContextSize bogus
#define SmallContextSlots 22
#define SpecialSelectors 23
#define SqueakV3PlusClosuresBytecodeSet 1
#define StackPointerIndex 2
#define StreamArrayIndex 0
#define StreamIndexIndex 1
#define StreamReadLimitIndex 2
#define StreamWriteLimitIndex 3
#define SuperclassIndex 0
#define SuspendedContextIndex 1
#define TheDisplay 14
#define TheFinalizationSemaphore 41
#define TheInputSemaphore null
#define TheInterruptSemaphore 30
#define TheLowSpaceSemaphore 17
#define TheTimerSemaphore 29
#define TrueObject 2
#define UnfailingPrimitive 3
#define UnimplementedPrimitive -7
#define ValueIndex 1
#define XIndex 0
#define YIndex 1
#define YoungSelectorInPIC -5

