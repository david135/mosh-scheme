// Do not edit this file generated by gen-cproc.scm
const int cProcNum = 113;
static const Object cProcs[] = {
     Object::makeCProcedure(exitEx),
     Object::makeCProcedure(assqEx),
     Object::makeCProcedure(modEx),
     Object::makeCProcedure(applyEx),
     Object::makeCProcedure(typedVectorTypeEx),
     Object::makeCProcedure(typedVectorPEx),
     Object::makeCProcedure(typedVectorSetNthEx),
     Object::makeCProcedure(typedVectorGetNthEx),
     Object::makeCProcedure(makeTypedVectorEx),
     Object::makeCProcedure(vectorTypeInstanceOfPEx),
     Object::makeCProcedure(vectorTypeDataEx),
     Object::makeCProcedure(vectorTypePEx),
     Object::makeCProcedure(makeVectorTypeEx),
     Object::makeCProcedure(withExceptionHandlerEx),
     Object::makeCProcedure(raiseContinuableEx),
     Object::makeCProcedure(raiseEx),
     Object::makeCProcedure(evalEx),
     Object::makeCProcedure(errorfEx),
     Object::makeCProcedure(sourceInfoEx),
     Object::makeCProcedure(regexpReplaceAllEx),
     Object::makeCProcedure(regexpReplaceEx),
     Object::makeCProcedure(vectorEx),
     Object::makeCProcedure(closeInputPortEx),
     Object::makeCProcedure(openFileInputPortEx),
     Object::makeCProcedure(openFileOutputPortEx),
     Object::makeCProcedure(utf8TostringEx),
     Object::makeCProcedure(getBytevectorNEx),
     Object::makeCProcedure(standardInputPortEx),
     Object::makeCProcedure(bytevectorU8RefEx),
     Object::makeCProcedure(bytevectorLengthEx),
     Object::makeCProcedure(sysGetBytevectorEx),
     Object::makeCProcedure(sysOpenBytevectorOutputPortEx),
     Object::makeCProcedure(eofObjectEx),
     Object::makeCProcedure(makeTranscoderEx),
     Object::makeCProcedure(utf8CodecEx),
     Object::makeCProcedure(transcodedPortEx),
     Object::makeCProcedure(bytevectorU8SetEx),
     Object::makeCProcedure(getU8Ex),
     Object::makeCProcedure(makeCustomBinaryInputPortEx),
     Object::makeCProcedure(find10Ex),
     Object::makeCProcedure(map10Ex),
     Object::makeCProcedure(initLibraryTableEx),
     Object::makeCProcedure(pairPEx),
     Object::makeCProcedure(vmApplyEx),
     Object::makeCProcedure(valuesEx),
     Object::makeCProcedure(currentErrorPortEx),
     Object::makeCProcedure(hashtableKeysEx),
     Object::makeCProcedure(hashtableRefEx),
     Object::makeCProcedure(hashtableSetEx),
     Object::makeCProcedure(makeEqHashtableEx),
     Object::makeCProcedure(getTimeofdayEx),
     Object::makeCProcedure(errorEx),
     Object::makeCProcedure(stringRefEx),
     Object::makeCProcedure(symbolTostringEx),
     Object::makeCProcedure(booleanPEx),
     Object::makeCProcedure(memberEx),
     Object::makeCProcedure(eqPEx),
     Object::makeCProcedure(memqEx),
     Object::makeCProcedure(listPEx),
     Object::makeCProcedure(vectorPEx),
     Object::makeCProcedure(stringEqPEx),
     Object::makeCProcedure(gensymEx),
     Object::makeCProcedure(writeEx),
     Object::makeCProcedure(charPEx),
     Object::makeCProcedure(setCurrentOutputPortEx),
     Object::makeCProcedure(setCurrentInputPortEx),
     Object::makeCProcedure(currentOutputPortEx),
     Object::makeCProcedure(currentInputPortEx),
     Object::makeCProcedure(formatEx),
     Object::makeCProcedure(integerTocharEx),
     Object::makeCProcedure(charTointegerEx),
     Object::makeCProcedure(stringToregexpEx),
     Object::makeCProcedure(sysGetOutputStringEx),
     Object::makeCProcedure(fileExistsPEx),
     Object::makeCProcedure(sysReaddirEx),
     Object::makeCProcedure(getRemainingInputStringEx),
     Object::makeCProcedure(digitTointegerEx),
     Object::makeCProcedure(closeOutputPortEx),
     Object::makeCProcedure(openOutputFileEx),
     Object::makeCProcedure(sysPortSeekEx),
     Object::makeCProcedure(sysOpenOutputStringEx),
     Object::makeCProcedure(openStringInputPortEx),
     Object::makeCProcedure(equalPEx),
     Object::makeCProcedure(sysGetenvEx),
     Object::makeCProcedure(stringPEx),
     Object::makeCProcedure(charEqPEx),
     Object::makeCProcedure(readCharEx),
     Object::makeCProcedure(eofObjectPEx),
     Object::makeCProcedure(reverseEx),
     Object::makeCProcedure(numberTostringEx),
     Object::makeCProcedure(stringSplitEx),
     Object::makeCProcedure(stringAppendEx),
     Object::makeCProcedure(stringTonumberEx),
     Object::makeCProcedure(stringTosymbolEx),
     Object::makeCProcedure(stringLengthEx),
     Object::makeCProcedure(stringSetEx),
     Object::makeCProcedure(makeStringEx),
     Object::makeCProcedure(rxmatchSubstringEx),
     Object::makeCProcedure(rxmatchBeforeEx),
     Object::makeCProcedure(rxmatchAfterEx),
     Object::makeCProcedure(rxmatchEndEx),
     Object::makeCProcedure(rxmatchStartEx),
     Object::makeCProcedure(regexpTostringEx),
     Object::makeCProcedure(regexpPEx),
     Object::makeCProcedure(rxmatchEx),
     Object::makeCProcedure(sysDisplayEx),
     Object::makeCProcedure(setCdrEx),
     Object::makeCProcedure(setCarEx),
     Object::makeCProcedure(nullPEx),
     Object::makeCProcedure(cdrEx),
     Object::makeCProcedure(carEx),
     Object::makeCProcedure(consEx),
     Object::makeCProcedure(numberPEx),
};
#ifdef ENABLE_PROFILER
static const ucs4char* cProcNames[] = {
     UC("exit"),
     UC("assq"),
     UC("mod"),
     UC("apply"),
     UC("typed-vector-type"),
     UC("typed-vector?"),
     UC("typed-vector-set-nth"),
     UC("typed-vector-get-nth"),
     UC("make-typed-vector"),
     UC("vector-type-instance-of?"),
     UC("vector-type-data"),
     UC("vector-type?"),
     UC("make-vector-type"),
     UC("with-exception-handler"),
     UC("raise-continuable"),
     UC("raise"),
     UC("eval"),
     UC("errorf"),
     UC("source-info"),
     UC("regexp-replace-all"),
     UC("regexp-replace"),
     UC("vector"),
     UC("close-input-port"),
     UC("open-file-input-port"),
     UC("open-file-output-port"),
     UC("utf8->string"),
     UC("get-bytevector-n"),
     UC("standard-input-port"),
     UC("bytevector-u8-ref"),
     UC("bytevector-length"),
     UC("sys-get-bytevector"),
     UC("sys-open-bytevector-output-port"),
     UC("eof-object"),
     UC("make-transcoder"),
     UC("utf-8-codec"),
     UC("transcoded-port"),
     UC("bytevector-u8-set!"),
     UC("get-u8"),
     UC("make-custom-binary-input-port"),
     UC("find10"),
     UC("map10"),
     UC("init-library-table"),
     UC("pair?"),
     UC("vm/apply"),
     UC("values"),
     UC("current-error-port"),
     UC("hashtable-keys"),
     UC("hashtable-ref"),
     UC("hashtable-set!"),
     UC("make-eq-hashtable"),
     UC("get-timeofday"),
     UC("error"),
     UC("string-ref"),
     UC("symbol->string"),
     UC("boolean?"),
     UC("member"),
     UC("eq?"),
     UC("memq"),
     UC("list?"),
     UC("vector?"),
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
     UC("sys-get-output-string"),
     UC("file-exists?"),
     UC("sys-readdir"),
     UC("get-remaining-input-string"),
     UC("digit->integer"),
     UC("close-output-port"),
     UC("open-output-file"),
     UC("sys-port-seek"),
     UC("sys-open-output-string"),
     UC("open-string-input-port"),
     UC("equal?"),
     UC("sys-getenv"),
     UC("string?"),
     UC("char=?"),
     UC("read-char"),
     UC("eof-object?"),
     UC("reverse"),
     UC("number->string"),
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
     UC("cons"),
     UC("number?"),
};
#endif
