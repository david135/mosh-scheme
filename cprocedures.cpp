// Do not edit this file generated by gen-cproc.scm
static const int cProcNum = 604;
static Object (*cProcFunctions[])(VM* vm, int, const Object*) = {
     currentDynamicWindersEx,
     gensymPrefixSetDEx,
     joinWrapsEx,
     idTorealLabelEx,
     sameMarksPEx,
     sameMarksMulPEx,
     simpleStructNameEx,
     simpleStructSetDEx,
     simpleStructRefEx,
     makeSimpleStructEx,
     simpleStructPEx,
     sharedErrnoEx,
     pointerSetCPointerDEx,
     pointerSetCDoubleDEx,
     pointerSetCFloatDEx,
     pointerSetCLongLongDEx,
     pointerSetCLongDEx,
     pointerSetCIntDEx,
     pointerSetCShortDEx,
     pointerSetCCharDEx,
     pointerSetCUint64DEx,
     pointerSetCUint32DEx,
     pointerSetCUint16DEx,
     pointerSetCUint8DEx,
     pointerSetCInt64DEx,
     pointerSetCInt32DEx,
     pointerSetCInt16DEx,
     pointerSetCInt8DEx,
     pointerRefCPointerEx,
     pointerRefCDoubleEx,
     pointerRefCFloatEx,
     pointerRefCUnsignedLongLongEx,
     pointerRefCSignedLongLongEx,
     pointerRefCUnsignedLongEx,
     pointerRefCSignedLongEx,
     pointerRefCUnsignedIntEx,
     pointerRefCSignedIntEx,
     pointerRefCUnsignedShortEx,
     pointerRefCSignedShortEx,
     pointerRefCUnsignedCharEx,
     pointerRefCSignedCharEx,
     pointerRefCInt64Ex,
     pointerRefCInt32Ex,
     pointerRefCInt16Ex,
     pointerRefCInt8Ex,
     pointerRefCUint64Ex,
     pointerRefCUint32Ex,
     pointerRefCUint16Ex,
     pointerRefCUint8Ex,
     integerTopointerEx,
     pointerTointegerEx,
     pointerPEx,
     fileStatCtimeEx,
     fileStatAtimeEx,
     fileStatMtimeEx,
     fileSizeInBytesEx,
     fileWritablePEx,
     fileExecutablePEx,
     fileReadablePEx,
     fileRegularPEx,
     fileSymbolicLinkPEx,
     fileDirectoryPEx,
     createSymbolicLinkEx,
     renameFileEx,
     deleteDirectoryEx,
     createDirectoryEx,
     vectorSetDEx,
     vectorRefEx,
     vectorLengthEx,
     makeVectorEx,
     mutexUnlockDEx,
     mutexTryLockDEx,
     mutexLockDEx,
     makeMutexEx,
     mutexPEx,
     conditionVariableNotifyAllDEx,
     conditionVariableNotifyDEx,
     conditionVariableWaitDEx,
     makeConditionVariableEx,
     whereisEx,
     registerEx,
     vmSelfEx,
     mainVmPEx,
     vmJoinDEx,
     vmSetValueDEx,
     vmPEx,
     vmStartDEx,
     makeVmEx,
     socketPortEx,
     socketShutdownEx,
     socketCloseEx,
     socketSendEx,
     socketRecvDEx,
     socketRecvEx,
     osConstantEx,
     makeServerSocketEx,
     makeClientSocketEx,
     socketAcceptEx,
     socketPEx,
     moshExecutablePathEx,
     timeUsageEx,
     listTailEx,
     listRefEx,
     putDatumEx,
     makeCustomTextualInputOutputPortEx,
     makeCustomBinaryInputOutputPortEx,
     openFileInputOutputPortEx,
     moduloEx,
     remainderEx,
     quotientEx,
     transcoderErrorHandlingModeEx,
     transcoderEolStyleEx,
     transcoderCodecEx,
     writeCharEx,
     putCharEx,
     putBytevectorEx,
     nativeTranscoderEx,
     portTranscoderEx,
     portPEx,
     textualPortPEx,
     outputPortPEx,
     hostOsEx,
     internalFfiFreeCCallbackTrampolineEx,
     internalFfiMakeCCallbackTrampolineEx,
     internalFfiFreeEx,
     internalFfiMallocEx,
     internalFfiSupportedPEx,
     internalFfiCallEx,
     internalFfiLookupEx,
     internalFfiOpenEx,
     openBytevectorInputPortEx,
     lookaheadU8Ex,
     portEofPEx,
     inputPortPEx,
     binaryPortPEx,
     setCurrentDirectoryDEx,
     currentDirectoryEx,
     internalPipeEx,
     internalWaitpidEx,
     internalExecEx,
     internalForkEx,
     localTzOffsetEx,
     microsecondsEx,
     bufferModePEx,
     nativeEolStyleEx,
     fastEqualPEx,
     printStackEx,
     disasmEx,
     ungensymEx,
     vectorFillDEx,
     stringCopyEx,
     makePolarEx,
     exptEx,
     atanEx,
     angleEx,
     magnitudeEx,
     sqrtEx,
     acosEx,
     asinEx,
     tanEx,
     cosEx,
     sinEx,
     logEx,
     expEx,
     roundEx,
     truncateEx,
     ceilingEx,
     floorEx,
     denominatorEx,
     numeratorEx,
     integerDiv0Ex,
     integerDivEx,
     absEx,
     oddPEx,
     evenPEx,
     bytevectorIeeeDoubleSetDEx,
     bytevectorIeeeDoubleNativeSetDEx,
     bytevectorIeeeSingleSetDEx,
     bytevectorIeeeSingleNativeSetDEx,
     bytevectorIeeeDoubleRefEx,
     bytevectorIeeeDoubleNativeRefEx,
     bytevectorIeeeSingleRefEx,
     bytevectorIeeeSingleNativeRefEx,
     fxreverseBitFieldEx,
     fxrotateBitFieldEx,
     fxarithmeticShiftRightEx,
     fxarithmeticShiftLeftEx,
     fxarithmeticShiftEx,
     fxcopyBitFieldEx,
     fxbitFieldEx,
     fxcopyBitEx,
     fxbitSetPEx,
     fxfirstBitSetEx,
     fxlengthEx,
     fxbitCountEx,
     fxifEx,
     fxxorEx,
     fxiorEx,
     fxandEx,
     fxnotEx,
     fxmod0Ex,
     fxdiv0Ex,
     fxmodEx,
     fxdivEx,
     fxSubEx,
     fxMulEx,
     fxAddEx,
     fxminEx,
     fxmaxEx,
     fxevenPEx,
     fxoddPEx,
     fxnegativePEx,
     fxpositivePEx,
     fxzeroPEx,
     fxLePEx,
     fxGePEx,
     fxLtPEx,
     fxGtPEx,
     fxEqPEx,
     integerValuedPEx,
     rationalValuedPEx,
     realValuedPEx,
     integerPEx,
     rationalPEx,
     realPEx,
     complexPEx,
     bitwiseArithmeticShiftEx,
     bitwiseArithmeticShiftRightEx,
     bitwiseArithmeticShiftLeftEx,
     bitwiseFirstBitSetEx,
     bitwiseLengthEx,
     bitwiseBitCountEx,
     bitwiseXorEx,
     bitwiseIorEx,
     bitwiseAndEx,
     bitwiseNotEx,
     fixnumToflonumEx,
     flexptEx,
     flsqrtEx,
     flatanEx,
     flacosEx,
     flasinEx,
     fltanEx,
     flcosEx,
     flsinEx,
     fllogEx,
     flexpEx,
     flroundEx,
     fltruncateEx,
     flceilingEx,
     flfloorEx,
     fldenominatorEx,
     flnumeratorEx,
     flIntegerMod0Ex,
     flIntegerDiv0Ex,
     flIntegerModEx,
     flIntegerDivEx,
     flabsEx,
     flDivEx,
     flSubEx,
     flMulEx,
     flAddEx,
     flminEx,
     flmaxEx,
     flnanPEx,
     flinfinitePEx,
     flfinitePEx,
     flevenPEx,
     floddPEx,
     flnegativePEx,
     flpositivePEx,
     flzeroPEx,
     flintegerPEx,
     flLePEx,
     flGePEx,
     flGtPEx,
     flLtPEx,
     flEqPEx,
     realToflonumEx,
     finitePEx,
     infinitePEx,
     nanPEx,
     inexactEx,
     exactEx,
     inexactPEx,
     exactPEx,
     imagPartEx,
     realPartEx,
     makeRectangularEx,
     greatestFixnumEx,
     leastFixnumEx,
     fixnumWidthEx,
     bignumPEx,
     fixnumPEx,
     flonumPEx,
     rationalPEx,
     getStringNEx,
     faslReadEx,
     faslWriteEx,
     makeCompilerInstructionEx,
     makeInstructionEx,
     closePortEx,
     utf32TostringEx,
     utf16TostringEx,
     stringToutf32Ex,
     stringToutf16Ex,
     nullTerminatedUtf8TostringEx,
     nullTerminatedBytevectorTostringEx,
     utf8TostringEx,
     stringToutf8Ex,
     stringTobytevectorEx,
     bytevectorTostringEx,
     bytevectorS64NativeSetDEx,
     bytevectorU64NativeSetDEx,
     bytevectorS64SetDEx,
     bytevectorU64SetDEx,
     bytevectorS64NativeRefEx,
     bytevectorU64NativeRefEx,
     bytevectorS64RefEx,
     bytevectorU64RefEx,
     bytevectorS32NativeSetDEx,
     bytevectorU32NativeSetDEx,
     bytevectorS32SetDEx,
     bytevectorU32SetDEx,
     bytevectorS32NativeRefEx,
     bytevectorU32NativeRefEx,
     bytevectorS32RefEx,
     bytevectorU32RefEx,
     bytevectorS16NativeSetDEx,
     bytevectorU16NativeSetDEx,
     bytevectorS16SetDEx,
     bytevectorU16SetDEx,
     bytevectorS16NativeRefEx,
     bytevectorU16NativeRefEx,
     bytevectorS16RefEx,
     bytevectorU16RefEx,
     u8ListTobytevectorEx,
     bytevectorTou8ListEx,
     bytevectorS8SetDEx,
     bytevectorS8RefEx,
     bytevectorU8SetDEx,
     bytevectorU8RefEx,
     bytevectorCopyEx,
     bytevectorCopyDEx,
     bytevectorFillDEx,
     bytevectorEqPEx,
     bytevectorLengthEx,
     makeBytevectorEx,
     makeBytevectorEx,
     nativeEndiannessEx,
     standardLibraryPathEx,
     currentDirectoryEx,
     bytevectorPEx,
     getDatumEx,
     getLineEx,
     getStringAllEx,
     getStringNDEx,
     getStringNEx,
     lookaheadCharEx,
     getCharEx,
     minEx,
     maxEx,
     divideEx,
     mulEx,
     subEx,
     addEx,
     eqEx,
     geEx,
     gtEx,
     leEx,
     ltEx,
     throwEx,
     conditionPredicateEx,
     conditionAccessorEx,
     conditionPEx,
     simpleConditionsEx,
     conditionEx,
     recordTypeDescriptorPEx,
     recordFieldMutablePEx,
     recordTypeFieldNamesEx,
     recordTypeOpaquePEx,
     recordTypeSealedPEx,
     recordTypeGenerativePEx,
     recordTypeUidEx,
     recordTypeParentEx,
     recordTypeNameEx,
     recordRtdEx,
     recordPEx,
     recordMutatorEx,
     recordAccessorEx,
     recordConstructorEx,
     recordPredicateEx,
     makeRecordConstructorDescriptorEx,
     makeRecordTypeDescriptorEx,
     hashtableHashFunctionEx,
     hashtableEquivalenceFunctionEx,
     hashtableKeysEx,
     hashtableClearDEx,
     hashtableMutablePEx,
     hashtableCopyEx,
     hashtableContainsPEx,
     hashtableDeleteDEx,
     hashtableSizeEx,
     hashtablePEx,
     makeHashtableEx,
     setSymbolValueDEx,
     symbolValueEx,
     listTransposeAddEx,
     localRefEx,
     labelEx,
     pass1FindSymbolInLvarsEx,
     pass3CompileReferEx,
     listTovectorEx,
     lengthEx,
     codeBuilderPutInsnArg2DEx,
     codeBuilderPutInsnArg1DEx,
     codeBuilderPutInsnArg0DEx,
     codeBuilderEmitEx,
     codeBuilderAppendDEx,
     codeBuilderPutExtra5DEx,
     codeBuilderPutExtra4DEx,
     codeBuilderPutExtra3DEx,
     codeBuilderPutExtra2DEx,
     codeBuilderPutExtra1DEx,
     makeCodeBuilderEx,
     pass4FixupLabelsEx,
     pass3FindSetsEx,
     pass3FindFreeEx,
     appendDEx,
     append2Ex,
     appendEx,
     internalGetClosureNameEx,
     callProcessEx,
     setSourceInfoDEx,
     vectorTolistEx,
     readEx,
     charGtPEx,
     charGePEx,
     charLtPEx,
     charLePEx,
     symbolPEx,
     loadEx,
     procedurePEx,
     memvEx,
     macroexpand1Ex,
     exitEx,
     assvEx,
     assocEx,
     assqEx,
     applyEx,
     evalCompiledEx,
     evalEx,
     sourceInfoEx,
     regexpReplaceAllEx,
     regexpReplaceEx,
     vectorEx,
     closeInputPortEx,
     openFileInputPortEx,
     openFileOutputPortEx,
     getBytevectorNEx,
     standardErrorPortEx,
     standardOutputPortEx,
     standardInputPortEx,
     bytevectorLengthEx,
     sysGetBytevectorEx,
     sysOpenBytevectorOutputPortEx,
     eofObjectEx,
     makeTranscoderEx,
     utf16CodecEx,
     utf8CodecEx,
     latin1CodecEx,
     transcodedPortEx,
     getBytevectorAllEx,
     getBytevectorSomeEx,
     getBytevectorNDEx,
     setPortPositionDEx,
     portPositionEx,
     portHasSetPortPositionDPEx,
     portHasPortPositionPEx,
     bytevectorU8SetDEx,
     outputPortBufferModeEx,
     flushOutputPortEx,
     putStringEx,
     putU8Ex,
     getU8Ex,
     makeCustomTextualOutputPortEx,
     makeCustomTextualInputPortEx,
     makeCustomBinaryOutputPortEx,
     makeCustomBinaryInputPortEx,
     pairPEx,
     vmApplyEx,
     valuesEx,
     currentErrorPortEx,
     eqHashtableCopyEx,
     equalHashEx,
     symbolHashEx,
     stringCiHashEx,
     eqvHashEx,
     stringHashEx,
     hashtableKeysEx,
     hashtableRefEx,
     hashtableSetDEx,
     makeEqvHashtableEx,
     makeEqHashtableEx,
     getTimeofdayEx,
     assertionViolationEx,
     errorEx,
     stringRefEx,
     symbolTostringEx,
     booleanPEx,
     memberEx,
     eqvPEx,
     eqPEx,
     memqEx,
     listEx,
     listPEx,
     vectorPEx,
     booleanEqPEx,
     symbolEqPEx,
     cddrEx,
     cdddrEx,
     cddddrEx,
     cdddarEx,
     cddarEx,
     cddadrEx,
     cddaarEx,
     cdarEx,
     cdadrEx,
     cdaddrEx,
     cdadarEx,
     cdaarEx,
     cdaadrEx,
     cdaaarEx,
     cadrEx,
     caddrEx,
     cadddrEx,
     caddarEx,
     cadarEx,
     cadadrEx,
     cadaarEx,
     caarEx,
     caadrEx,
     caaddrEx,
     caadarEx,
     caaarEx,
     caaadrEx,
     caaaarEx,
     stringEqPEx,
     gensymEx,
     writeEx,
     charPEx,
     setCurrentOutputPortDEx,
     setCurrentInputPortDEx,
     currentOutputPortEx,
     currentInputPortEx,
     formatEx,
     integerTocharEx,
     charTointegerEx,
     stringToregexpEx,
     getOutputStringEx,
     deleteFileEx,
     fileExistsPEx,
     directoryListEx,
     getRemainingInputStringEx,
     digitTointegerEx,
     closeOutputPortEx,
     sysPortSeekEx,
     openOutputStringEx,
     openStringInputPortEx,
     equalPEx,
     getEnvironmentVariablesEx,
     getEnvironmentVariableEx,
     stringPEx,
     charEqPEx,
     peekCharEx,
     readCharEx,
     eofObjectPEx,
     reverseEx,
     numberTostringEx,
     stringEx,
     stringSplitEx,
     stringAppendEx,
     stringTonumberEx,
     stringTosymbolEx,
     stringLengthEx,
     stringSetDEx,
     makeStringEx,
     rxmatchSubstringEx,
     rxmatchBeforeEx,
     rxmatchAfterEx,
     rxmatchEndEx,
     rxmatchStartEx,
     regexpTostringEx,
     regexpPEx,
     rxmatchEx,
     sysDisplayEx,
     setCdrDEx,
     setCarDEx,
     nullPEx,
     cdrEx,
     carEx,
     consMulEx,
     consEx,
     numberPEx,
};
static const ucs4char* cProcNames[] = {
     UC("current-dynamic-winders"),
     UC("gensym-prefix-set!"),
     UC("join-wraps"),
     UC("id->real-label"),
     UC("same-marks?"),
     UC("same-marks*?"),
     UC("simple-struct-name"),
     UC("simple-struct-set!"),
     UC("simple-struct-ref"),
     UC("make-simple-struct"),
     UC("simple-struct?"),
     UC("shared-errno"),
     UC("pointer-set-c-pointer!"),
     UC("pointer-set-c-double!"),
     UC("pointer-set-c-float!"),
     UC("pointer-set-c-long-long!"),
     UC("pointer-set-c-long!"),
     UC("pointer-set-c-int!"),
     UC("pointer-set-c-short!"),
     UC("pointer-set-c-char!"),
     UC("pointer-set-c-uint64!"),
     UC("pointer-set-c-uint32!"),
     UC("pointer-set-c-uint16!"),
     UC("pointer-set-c-uint8!"),
     UC("pointer-set-c-int64!"),
     UC("pointer-set-c-int32!"),
     UC("pointer-set-c-int16!"),
     UC("pointer-set-c-int8!"),
     UC("pointer-ref-c-pointer"),
     UC("pointer-ref-c-double"),
     UC("pointer-ref-c-float"),
     UC("pointer-ref-c-unsigned-long-long"),
     UC("pointer-ref-c-signed-long-long"),
     UC("pointer-ref-c-unsigned-long"),
     UC("pointer-ref-c-signed-long"),
     UC("pointer-ref-c-unsigned-int"),
     UC("pointer-ref-c-signed-int"),
     UC("pointer-ref-c-unsigned-short"),
     UC("pointer-ref-c-signed-short"),
     UC("pointer-ref-c-unsigned-char"),
     UC("pointer-ref-c-signed-char"),
     UC("pointer-ref-c-int64"),
     UC("pointer-ref-c-int32"),
     UC("pointer-ref-c-int16"),
     UC("pointer-ref-c-int8"),
     UC("pointer-ref-c-uint64"),
     UC("pointer-ref-c-uint32"),
     UC("pointer-ref-c-uint16"),
     UC("pointer-ref-c-uint8"),
     UC("integer->pointer"),
     UC("pointer->integer"),
     UC("pointer?"),
     UC("file-stat-ctime"),
     UC("file-stat-atime"),
     UC("file-stat-mtime"),
     UC("file-size-in-bytes"),
     UC("file-writable?"),
     UC("file-executable?"),
     UC("file-readable?"),
     UC("file-regular?"),
     UC("file-symbolic-link?"),
     UC("file-directory?"),
     UC("create-symbolic-link"),
     UC("rename-file"),
     UC("delete-directory"),
     UC("create-directory"),
     UC("vector-set!"),
     UC("vector-ref"),
     UC("vector-length"),
     UC("make-vector"),
     UC("mutex-unlock!"),
     UC("mutex-try-lock!"),
     UC("mutex-lock!"),
     UC("make-mutex"),
     UC("mutex?"),
     UC("condition-variable-notify-all!"),
     UC("condition-variable-notify!"),
     UC("condition-variable-wait!"),
     UC("make-condition-variable"),
     UC("whereis"),
     UC("register"),
     UC("vm-self"),
     UC("main-vm?"),
     UC("vm-join!"),
     UC("vm-set-value!"),
     UC("vm?"),
     UC("vm-start!"),
     UC("make-vm"),
     UC("socket-port"),
     UC("socket-shutdown"),
     UC("socket-close"),
     UC("socket-send"),
     UC("socket-recv!"),
     UC("socket-recv"),
     UC("os-constant"),
     UC("make-server-socket"),
     UC("make-client-socket"),
     UC("socket-accept"),
     UC("socket?"),
     UC("mosh-executable-path"),
     UC("time-usage"),
     UC("list-tail"),
     UC("list-ref"),
     UC("put-datum"),
     UC("make-custom-textual-input/output-port"),
     UC("make-custom-binary-input/output-port"),
     UC("open-file-input/output-port"),
     UC("modulo"),
     UC("remainder"),
     UC("quotient"),
     UC("transcoder-error-handling-mode"),
     UC("transcoder-eol-style"),
     UC("transcoder-codec"),
     UC("write-char"),
     UC("put-char"),
     UC("put-bytevector"),
     UC("native-transcoder"),
     UC("port-transcoder"),
     UC("port?"),
     UC("textual-port?"),
     UC("output-port?"),
     UC("host-os"),
     UC("%ffi-free-c-callback-trampoline"),
     UC("%ffi-make-c-callback-trampoline"),
     UC("%ffi-free"),
     UC("%ffi-malloc"),
     UC("%ffi-supported?"),
     UC("%ffi-call"),
     UC("%ffi-lookup"),
     UC("%ffi-open"),
     UC("open-bytevector-input-port"),
     UC("lookahead-u8"),
     UC("port-eof?"),
     UC("input-port?"),
     UC("binary-port?"),
     UC("set-current-directory!"),
     UC("current-directory"),
     UC("%pipe"),
     UC("%waitpid"),
     UC("%exec"),
     UC("%fork"),
     UC("local-tz-offset"),
     UC("microseconds"),
     UC("buffer-mode?"),
     UC("native-eol-style"),
     UC("fast-equal?"),
     UC("print-stack"),
     UC("disasm"),
     UC("ungensym"),
     UC("vector-fill!"),
     UC("string-copy"),
     UC("make-polar"),
     UC("expt"),
     UC("atan"),
     UC("angle"),
     UC("magnitude"),
     UC("sqrt"),
     UC("acos"),
     UC("asin"),
     UC("tan"),
     UC("cos"),
     UC("sin"),
     UC("log"),
     UC("exp"),
     UC("round"),
     UC("truncate"),
     UC("ceiling"),
     UC("floor"),
     UC("denominator"),
     UC("numerator"),
     UC("div0"),
     UC("div"),
     UC("abs"),
     UC("odd?"),
     UC("even?"),
     UC("bytevector-ieee-double-set!"),
     UC("bytevector-ieee-double-native-set!"),
     UC("bytevector-ieee-single-set!"),
     UC("bytevector-ieee-single-native-set!"),
     UC("bytevector-ieee-double-ref"),
     UC("bytevector-ieee-double-native-ref"),
     UC("bytevector-ieee-single-ref"),
     UC("bytevector-ieee-single-native-ref"),
     UC("fxreverse-bit-field"),
     UC("fxrotate-bit-field"),
     UC("fxarithmetic-shift-right"),
     UC("fxarithmetic-shift-left"),
     UC("fxarithmetic-shift"),
     UC("fxcopy-bit-field"),
     UC("fxbit-field"),
     UC("fxcopy-bit"),
     UC("fxbit-set?"),
     UC("fxfirst-bit-set"),
     UC("fxlength"),
     UC("fxbit-count"),
     UC("fxif"),
     UC("fxxor"),
     UC("fxior"),
     UC("fxand"),
     UC("fxnot"),
     UC("fxmod0"),
     UC("fxdiv0"),
     UC("fxmod"),
     UC("fxdiv"),
     UC("fx-"),
     UC("fx*"),
     UC("fx+"),
     UC("fxmin"),
     UC("fxmax"),
     UC("fxeven?"),
     UC("fxodd?"),
     UC("fxnegative?"),
     UC("fxpositive?"),
     UC("fxzero?"),
     UC("fx<=?"),
     UC("fx>=?"),
     UC("fx<?"),
     UC("fx>?"),
     UC("fx=?"),
     UC("integer-valued?"),
     UC("rational-valued?"),
     UC("real-valued?"),
     UC("integer?"),
     UC("rational?"),
     UC("real?"),
     UC("complex?"),
     UC("bitwise-arithmetic-shift"),
     UC("bitwise-arithmetic-shift-right"),
     UC("bitwise-arithmetic-shift-left"),
     UC("bitwise-first-bit-set"),
     UC("bitwise-length"),
     UC("bitwise-bit-count"),
     UC("bitwise-xor"),
     UC("bitwise-ior"),
     UC("bitwise-and"),
     UC("bitwise-not"),
     UC("fixnum->flonum"),
     UC("flexpt"),
     UC("flsqrt"),
     UC("flatan"),
     UC("flacos"),
     UC("flasin"),
     UC("fltan"),
     UC("flcos"),
     UC("flsin"),
     UC("fllog"),
     UC("flexp"),
     UC("flround"),
     UC("fltruncate"),
     UC("flceiling"),
     UC("flfloor"),
     UC("fldenominator"),
     UC("flnumerator"),
     UC("flmod0"),
     UC("fldiv0"),
     UC("flmod"),
     UC("fldiv"),
     UC("flabs"),
     UC("fl/"),
     UC("fl-"),
     UC("fl*"),
     UC("fl+"),
     UC("flmin"),
     UC("flmax"),
     UC("flnan?"),
     UC("flinfinite?"),
     UC("flfinite?"),
     UC("fleven?"),
     UC("flodd?"),
     UC("flnegative?"),
     UC("flpositive?"),
     UC("flzero?"),
     UC("flinteger?"),
     UC("fl<=?"),
     UC("fl>=?"),
     UC("fl>?"),
     UC("fl<?"),
     UC("fl=?"),
     UC("real->flonum"),
     UC("finite?"),
     UC("infinite?"),
     UC("nan?"),
     UC("inexact"),
     UC("exact"),
     UC("inexact?"),
     UC("exact?"),
     UC("imag-part"),
     UC("real-part"),
     UC("make-rectangular"),
     UC("greatest-fixnum"),
     UC("least-fixnum"),
     UC("fixnum-width"),
     UC("bignum?"),
     UC("fixnum?"),
     UC("flonum?"),
     UC("rational?"),
     UC("get-string-n"),
     UC("fasl-read"),
     UC("fasl-write"),
     UC("make-compiler-instruction"),
     UC("make-instruction"),
     UC("close-port"),
     UC("utf32->string"),
     UC("utf16->string"),
     UC("string->utf32"),
     UC("string->utf16"),
     UC("null-terminated-utf8->string"),
     UC("null-terminated-bytevector->string"),
     UC("utf8->string"),
     UC("string->utf8"),
     UC("string->bytevector"),
     UC("bytevector->string"),
     UC("bytevector-s64-native-set!"),
     UC("bytevector-u64-native-set!"),
     UC("bytevector-s64-set!"),
     UC("bytevector-u64-set!"),
     UC("bytevector-s64-native-ref"),
     UC("bytevector-u64-native-ref"),
     UC("bytevector-s64-ref"),
     UC("bytevector-u64-ref"),
     UC("bytevector-s32-native-set!"),
     UC("bytevector-u32-native-set!"),
     UC("bytevector-s32-set!"),
     UC("bytevector-u32-set!"),
     UC("bytevector-s32-native-ref"),
     UC("bytevector-u32-native-ref"),
     UC("bytevector-s32-ref"),
     UC("bytevector-u32-ref"),
     UC("bytevector-s16-native-set!"),
     UC("bytevector-u16-native-set!"),
     UC("bytevector-s16-set!"),
     UC("bytevector-u16-set!"),
     UC("bytevector-s16-native-ref"),
     UC("bytevector-u16-native-ref"),
     UC("bytevector-s16-ref"),
     UC("bytevector-u16-ref"),
     UC("u8-list->bytevector"),
     UC("bytevector->u8-list"),
     UC("bytevector-s8-set!"),
     UC("bytevector-s8-ref"),
     UC("bytevector-u8-set!"),
     UC("bytevector-u8-ref"),
     UC("bytevector-copy"),
     UC("bytevector-copy!"),
     UC("bytevector-fill!"),
     UC("bytevector=?"),
     UC("bytevector-length"),
     UC("make-bytevector"),
     UC("make-bytevector"),
     UC("native-endianness"),
     UC("standard-library-path"),
     UC("current-directory"),
     UC("bytevector?"),
     UC("get-datum"),
     UC("get-line"),
     UC("get-string-all"),
     UC("get-string-n!"),
     UC("get-string-n"),
     UC("lookahead-char"),
     UC("get-char"),
     UC("min"),
     UC("max"),
     UC("/"),
     UC("*"),
     UC("-"),
     UC("+"),
     UC("="),
     UC(">="),
     UC(">"),
     UC("<="),
     UC("<"),
     UC("throw"),
     UC("condition-predicate"),
     UC("condition-accessor"),
     UC("condition?"),
     UC("simple-conditions"),
     UC("condition"),
     UC("record-type-descriptor?"),
     UC("record-field-mutable?"),
     UC("record-type-field-names"),
     UC("record-type-opaque?"),
     UC("record-type-sealed?"),
     UC("record-type-generative?"),
     UC("record-type-uid"),
     UC("record-type-parent"),
     UC("record-type-name"),
     UC("record-rtd"),
     UC("record?"),
     UC("record-mutator"),
     UC("record-accessor"),
     UC("record-constructor"),
     UC("record-predicate"),
     UC("make-record-constructor-descriptor"),
     UC("make-record-type-descriptor"),
     UC("hashtable-hash-function"),
     UC("hashtable-equivalence-function"),
     UC("hashtable-keys"),
     UC("hashtable-clear!"),
     UC("hashtable-mutable?"),
     UC("hashtable-copy"),
     UC("hashtable-contains?"),
     UC("hashtable-delete!"),
     UC("hashtable-size"),
     UC("hashtable?"),
     UC("make-hashtable"),
     UC("set-symbol-value!"),
     UC("symbol-value"),
     UC("list-transpose+"),
     UC("$local-ref"),
     UC("$label"),
     UC("pass1/find-symbol-in-lvars"),
     UC("pass3/compile-refer"),
     UC("list->vector"),
     UC("length"),
     UC("code-builder-put-insn-arg2!"),
     UC("code-builder-put-insn-arg1!"),
     UC("code-builder-put-insn-arg0!"),
     UC("code-builder-emit"),
     UC("code-builder-append!"),
     UC("code-builder-put-extra5!"),
     UC("code-builder-put-extra4!"),
     UC("code-builder-put-extra3!"),
     UC("code-builder-put-extra2!"),
     UC("code-builder-put-extra1!"),
     UC("make-code-builder"),
     UC("pass4/fixup-labels"),
     UC("pass3/find-sets"),
     UC("pass3/find-free"),
     UC("append!"),
     UC("append2"),
     UC("append"),
     UC("%get-closure-name"),
     UC("call-process"),
     UC("set-source-info!"),
     UC("vector->list"),
     UC("read"),
     UC("char>?"),
     UC("char>=?"),
     UC("char<?"),
     UC("char<=?"),
     UC("symbol?"),
     UC("load"),
     UC("procedure?"),
     UC("memv"),
     UC("macroexpand-1"),
     UC("exit"),
     UC("assv"),
     UC("assoc"),
     UC("assq"),
     UC("apply"),
     UC("eval-compiled"),
     UC("eval"),
     UC("source-info"),
     UC("regexp-replace-all"),
     UC("regexp-replace"),
     UC("vector"),
     UC("close-input-port"),
     UC("open-file-input-port"),
     UC("open-file-output-port"),
     UC("get-bytevector-n"),
     UC("standard-error-port"),
     UC("standard-output-port"),
     UC("standard-input-port"),
     UC("bytevector-length"),
     UC("sys-get-bytevector"),
     UC("sys-open-bytevector-output-port"),
     UC("eof-object"),
     UC("make-transcoder"),
     UC("utf-16-codec"),
     UC("utf-8-codec"),
     UC("latin-1-codec"),
     UC("transcoded-port"),
     UC("get-bytevector-all"),
     UC("get-bytevector-some"),
     UC("get-bytevector-n!"),
     UC("set-port-position!"),
     UC("port-position"),
     UC("port-has-set-port-position!?"),
     UC("port-has-port-position?"),
     UC("bytevector-u8-set!"),
     UC("output-port-buffer-mode"),
     UC("flush-output-port"),
     UC("put-string"),
     UC("put-u8"),
     UC("get-u8"),
     UC("make-custom-textual-output-port"),
     UC("make-custom-textual-input-port"),
     UC("make-custom-binary-output-port"),
     UC("make-custom-binary-input-port"),
     UC("pair?"),
     UC("vm/apply"),
     UC("values"),
     UC("current-error-port"),
     UC("eq-hashtable-copy"),
     UC("equal-hash"),
     UC("symbol-hash"),
     UC("string-ci-hash"),
     UC("eqv-hash"),
     UC("string-hash"),
     UC("hashtable-keys"),
     UC("hashtable-ref"),
     UC("hashtable-set!"),
     UC("make-eqv-hashtable"),
     UC("make-eq-hashtable"),
     UC("get-timeofday"),
     UC("assertion-violation"),
     UC("error"),
     UC("string-ref"),
     UC("symbol->string"),
     UC("boolean?"),
     UC("member"),
     UC("eqv?"),
     UC("eq?"),
     UC("memq"),
     UC("list"),
     UC("list?"),
     UC("vector?"),
     UC("boolean=?"),
     UC("symbol=?"),
     UC("cddr"),
     UC("cdddr"),
     UC("cddddr"),
     UC("cdddar"),
     UC("cddar"),
     UC("cddadr"),
     UC("cddaar"),
     UC("cdar"),
     UC("cdadr"),
     UC("cdaddr"),
     UC("cdadar"),
     UC("cdaar"),
     UC("cdaadr"),
     UC("cdaaar"),
     UC("cadr"),
     UC("caddr"),
     UC("cadddr"),
     UC("caddar"),
     UC("cadar"),
     UC("cadadr"),
     UC("cadaar"),
     UC("caar"),
     UC("caadr"),
     UC("caaddr"),
     UC("caadar"),
     UC("caaar"),
     UC("caaadr"),
     UC("caaaar"),
     UC("string=?"),
     UC("gensym"),
     UC("write"),
     UC("char?"),
     UC("set-current-output-port!"),
     UC("set-current-input-port!"),
     UC("current-output-port"),
     UC("current-input-port"),
     UC("format"),
     UC("integer->char"),
     UC("char->integer"),
     UC("string->regexp"),
     UC("get-output-string"),
     UC("delete-file"),
     UC("file-exists?"),
     UC("directory-list"),
     UC("get-remaining-input-string"),
     UC("digit->integer"),
     UC("close-output-port"),
     UC("sys-port-seek"),
     UC("open-output-string"),
     UC("open-string-input-port"),
     UC("equal?"),
     UC("get-environment-variables"),
     UC("get-environment-variable"),
     UC("string?"),
     UC("char=?"),
     UC("peek-char"),
     UC("read-char"),
     UC("eof-object?"),
     UC("reverse"),
     UC("number->string"),
     UC("string"),
     UC("string-split"),
     UC("string-append"),
     UC("string->number"),
     UC("string->symbol"),
     UC("string-length"),
     UC("string-set!"),
     UC("make-string"),
     UC("rxmatch-substring"),
     UC("rxmatch-before"),
     UC("rxmatch-after"),
     UC("rxmatch-end"),
     UC("rxmatch-start"),
     UC("regexp->string"),
     UC("regexp?"),
     UC("rxmatch"),
     UC("sys-display"),
     UC("set-cdr!"),
     UC("set-car!"),
     UC("null?"),
     UC("cdr"),
     UC("car"),
     UC("cons*"),
     UC("cons"),
     UC("number?"),
};
