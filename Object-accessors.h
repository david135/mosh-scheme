// Do not edit, this file is generated from accessors.scm
GenericHashTable* toGenericHashTable() const
{
    MOSH_ASSERT(isGenericHashTable());
    return reinterpret_cast<GenericHashTable*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isGenericHashTable() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::GenericHashTable;
}

Vector* toVector() const
{
    MOSH_ASSERT(isVector());
    return reinterpret_cast<Vector*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isVector() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Vector;
}

Closure* toClosure() const
{
    MOSH_ASSERT(isClosure());
    return reinterpret_cast<Closure*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isClosure() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Closure;
}

CProcedure* toCProcedure() const
{
    MOSH_ASSERT(isCProcedure());
    return reinterpret_cast<CProcedure*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isCProcedure() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::CProcedure;
}

String* toString() const
{
    MOSH_ASSERT(isString());
    return reinterpret_cast<String*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isString() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::String;
}

Symbol* toSymbol() const
{
    MOSH_ASSERT(isSymbol());
    return reinterpret_cast<Symbol*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isSymbol() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Symbol;
}

Stack* toStack() const
{
    MOSH_ASSERT(isStack());
    return reinterpret_cast<Stack*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isStack() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Stack;
}

Box* toBox() const
{
    MOSH_ASSERT(isBox());
    return reinterpret_cast<Box*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isBox() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Box;
}

EqHashTable* toEqHashTable() const
{
    MOSH_ASSERT(isEqHashTable());
    return reinterpret_cast<EqHashTable*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isEqHashTable() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::EqHashTable;
}

EqvHashTable* toEqvHashTable() const
{
    MOSH_ASSERT(isEqvHashTable());
    return reinterpret_cast<EqvHashTable*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isEqvHashTable() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::EqvHashTable;
}

ByteVector* toByteVector() const
{
    MOSH_ASSERT(isByteVector());
    return reinterpret_cast<ByteVector*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isByteVector() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::ByteVector;
}

TextualInputPort* toTextualInputPort() const
{
    MOSH_ASSERT(isTextualInputPort());
    return reinterpret_cast<TextualInputPort*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isTextualInputPort() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::TextualInputPort;
}

TextualOutputPort* toTextualOutputPort() const
{
    MOSH_ASSERT(isTextualOutputPort());
    return reinterpret_cast<TextualOutputPort*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isTextualOutputPort() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::TextualOutputPort;
}

Regexp* toRegexp() const
{
    MOSH_ASSERT(isRegexp());
    return reinterpret_cast<Regexp*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isRegexp() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Regexp;
}

RegMatch* toRegMatch() const
{
    MOSH_ASSERT(isRegMatch());
    return reinterpret_cast<RegMatch*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isRegMatch() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::RegMatch;
}

BinaryInputPort* toBinaryInputPort() const
{
    MOSH_ASSERT(isBinaryInputPort());
    return reinterpret_cast<BinaryInputPort*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isBinaryInputPort() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::BinaryInputPort;
}

BinaryOutputPort* toBinaryOutputPort() const
{
    MOSH_ASSERT(isBinaryOutputPort());
    return reinterpret_cast<BinaryOutputPort*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isBinaryOutputPort() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::BinaryOutputPort;
}

Codec* toCodec() const
{
    MOSH_ASSERT(isCodec());
    return reinterpret_cast<Codec*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isCodec() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Codec;
}

Transcoder* toTranscoder() const
{
    MOSH_ASSERT(isTranscoder());
    return reinterpret_cast<Transcoder*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isTranscoder() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Transcoder;
}

CodeBuilder* toCodeBuilder() const
{
    MOSH_ASSERT(isCodeBuilder());
    return reinterpret_cast<CodeBuilder*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isCodeBuilder() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::CodeBuilder;
}

Callable* toCallable() const
{
    MOSH_ASSERT(isCallable());
    return reinterpret_cast<Callable*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isCallable() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Callable;
}

Record* toRecord() const
{
    MOSH_ASSERT(isRecord());
    return reinterpret_cast<Record*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isRecord() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Record;
}

RecordTypeDescriptor* toRecordTypeDescriptor() const
{
    MOSH_ASSERT(isRecordTypeDescriptor());
    return reinterpret_cast<RecordTypeDescriptor*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isRecordTypeDescriptor() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::RecordTypeDescriptor;
}

RecordConstructorDescriptor* toRecordConstructorDescriptor() const
{
    MOSH_ASSERT(isRecordConstructorDescriptor());
    return reinterpret_cast<RecordConstructorDescriptor*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isRecordConstructorDescriptor() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::RecordConstructorDescriptor;
}

CompoundCondition* toCompoundCondition() const
{
    MOSH_ASSERT(isCompoundCondition());
    return reinterpret_cast<CompoundCondition*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isCompoundCondition() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::CompoundCondition;
}

Ratnum* toRatnum() const
{
    MOSH_ASSERT(isRatnum());
    return reinterpret_cast<Ratnum*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isRatnum() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Ratnum;
}

Flonum* toFlonum() const
{
    MOSH_ASSERT(isFlonum());
    return reinterpret_cast<Flonum*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isFlonum() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Flonum;
}

Bignum* toBignum() const
{
    MOSH_ASSERT(isBignum());
    return reinterpret_cast<Bignum*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isBignum() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Bignum;
}

Compnum* toCompnum() const
{
    MOSH_ASSERT(isCompnum());
    return reinterpret_cast<Compnum*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isCompnum() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Compnum;
}

Gloc* toGloc() const
{
    MOSH_ASSERT(isGloc());
    return reinterpret_cast<Gloc*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isGloc() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Gloc;
}

BinaryInputOutputPort* toBinaryInputOutputPort() const
{
    MOSH_ASSERT(isBinaryInputOutputPort());
    return reinterpret_cast<BinaryInputOutputPort*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isBinaryInputOutputPort() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::BinaryInputOutputPort;
}

TextualInputOutputPort* toTextualInputOutputPort() const
{
    MOSH_ASSERT(isTextualInputOutputPort());
    return reinterpret_cast<TextualInputOutputPort*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isTextualInputOutputPort() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::TextualInputOutputPort;
}

Socket* toSocket() const
{
    MOSH_ASSERT(isSocket());
    return reinterpret_cast<Socket*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isSocket() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Socket;
}

VM* toVM() const
{
    MOSH_ASSERT(isVM());
    return reinterpret_cast<VM*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isVM() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::VM;
}

ConditionVariable* toConditionVariable() const
{
    MOSH_ASSERT(isConditionVariable());
    return reinterpret_cast<ConditionVariable*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isConditionVariable() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::ConditionVariable;
}

Mutex* toMutex() const
{
    MOSH_ASSERT(isMutex());
    return reinterpret_cast<Mutex*>(reinterpret_cast<HeapObject*>(val)->obj);
}

bool isMutex() const
{
    return isHeapObject()
    && reinterpret_cast<HeapObject*>(val)->type == HeapObject::Mutex;
}

