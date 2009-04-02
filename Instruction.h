// Do not edit this file generated by gen-insn.scm
#ifndef __SCHEME_INSTRUCTION_H__
#define __SCHEME_INSTRUCTION_H__

#include "scheme.h"

namespace scheme {

class Instruction EXTEND_GC
{
public:
    enum {
        COMPILE_ERROR = 14,
        BRANCH_NOT_LE = 46,
        BRANCH_NOT_GE = 78,
        BRANCH_NOT_LT = 110,
        BRANCH_NOT_GT = 142,
        BRANCH_NOT_NULL = 174,
        BRANCH_NOT_NUMBER_EQUAL = 206,
        BRANCH_NOT_EQ = 238,
        BRANCH_NOT_EQV = 270,
        BRANCH_NOT_EQUAL = 302,
        APPEND2 = 334,
        CALL = 366,
        APPLY = 398,
        PUSH = 430,
        ASSIGN_FREE = 462,
        ASSIGN_GLOBAL = 494,
        ASSIGN_LOCAL = 526,
        BOX = 558,
        CAAR = 590,
        CADR = 622,
        CAR = 654,
        CDAR = 686,
        CDDR = 718,
        CDR = 750,
        CLOSURE = 782,
        CONS = 814,
        CONSTANT = 846,
        DEFINE_GLOBAL = 878,
        DISPLAY = 910,
        ENTER = 942,
        EQ = 974,
        EQV = 1006,
        EQUAL = 1038,
        FRAME = 1070,
        INDIRECT = 1102,
        LEAVE = 1134,
        LET_FRAME = 1166,
        LIST = 1198,
        LOCAL_JMP = 1230,
        MAKE_CONTINUATION = 1262,
        MAKE_VECTOR = 1294,
        NOP = 1326,
        NOT = 1358,
        NULL_P = 1390,
        NUMBER_ADD = 1422,
        NUMBER_EQUAL = 1454,
        NUMBER_GE = 1486,
        NUMBER_GT = 1518,
        NUMBER_LE = 1550,
        NUMBER_LT = 1582,
        NUMBER_MUL = 1614,
        NUMBER_DIV = 1646,
        NUMBER_SUB = 1678,
        PAIR_P = 1710,
        READ = 1742,
        READ_CHAR = 1774,
        REDUCE = 1806,
        REFER_FREE = 1838,
        REFER_GLOBAL = 1870,
        REFER_LOCAL = 1902,
        RESTORE_CONTINUATION = 1934,
        RETURN = 1966,
        SET_CAR = 1998,
        SET_CDR = 2030,
        SHIFT = 2062,
        SYMBOL_P = 2094,
        TEST = 2126,
        VALUES = 2158,
        RECEIVE = 2190,
        UNFIXED_JUMP = 2222,
        STOP = 2254,
        CONTINUATION_VALUES = 2286,
        SHIFTJ = 2318,
        UNDEF = 2350,
        VECTOR_LENGTH = 2382,
        VECTOR_P = 2414,
        VECTOR_REF = 2446,
        VECTOR_SET = 2478,
        PUSH_ENTER = 2510,
        HALT = 2542,
        CONSTANT_PUSH = 2574,
        NUMBER_SUB_PUSH = 2606,
        NUMBER_ADD_PUSH = 2638,
        PUSH_CONSTANT = 2670,
        PUSH_FRAME = 2702,
        CAR_PUSH = 2734,
        CDR_PUSH = 2766,
        SHIFT_CALL = 2798,
        NOT_TEST = 2830,
        REFER_GLOBAL_CALL = 2862,
        REFER_FREE_PUSH = 2894,
        REFER_LOCAL_PUSH = 2926,
        REFER_LOCAL_PUSH_CONSTANT = 2958,
        REFER_LOCAL_PUSH_CONSTANT_BRANCH_NOT_LE = 2990,
        REFER_LOCAL_PUSH_CONSTANT_BRANCH_NOT_GE = 3022,
        REFER_LOCAL_PUSH_CONSTANT_BRANCH_NOT_NUMBER_EQUAL = 3054,
        REFER_LOCAL_BRANCH_NOT_NULL = 3086,
        REFER_LOCAL_BRANCH_NOT_LT = 3118,
        REFER_FREE_CALL = 3150,
        REFER_GLOBAL_PUSH = 3182,
        REFER_LOCAL_CALL = 3214,
        LOCAL_CALL = 3246,
        VECTOR = 3278,
        INSTRUCTION_COUNT = 103,
    };
    static const ucs4char* toString(int val) {
        switch(val) {
        case COMPILE_ERROR:
           return UC("COMPILE_ERROR");
           break;
        case BRANCH_NOT_LE:
           return UC("BRANCH_NOT_LE");
           break;
        case BRANCH_NOT_GE:
           return UC("BRANCH_NOT_GE");
           break;
        case BRANCH_NOT_LT:
           return UC("BRANCH_NOT_LT");
           break;
        case BRANCH_NOT_GT:
           return UC("BRANCH_NOT_GT");
           break;
        case BRANCH_NOT_NULL:
           return UC("BRANCH_NOT_NULL");
           break;
        case BRANCH_NOT_NUMBER_EQUAL:
           return UC("BRANCH_NOT_NUMBER_EQUAL");
           break;
        case BRANCH_NOT_EQ:
           return UC("BRANCH_NOT_EQ");
           break;
        case BRANCH_NOT_EQV:
           return UC("BRANCH_NOT_EQV");
           break;
        case BRANCH_NOT_EQUAL:
           return UC("BRANCH_NOT_EQUAL");
           break;
        case APPEND2:
           return UC("APPEND2");
           break;
        case CALL:
           return UC("CALL");
           break;
        case APPLY:
           return UC("APPLY");
           break;
        case PUSH:
           return UC("PUSH");
           break;
        case ASSIGN_FREE:
           return UC("ASSIGN_FREE");
           break;
        case ASSIGN_GLOBAL:
           return UC("ASSIGN_GLOBAL");
           break;
        case ASSIGN_LOCAL:
           return UC("ASSIGN_LOCAL");
           break;
        case BOX:
           return UC("BOX");
           break;
        case CAAR:
           return UC("CAAR");
           break;
        case CADR:
           return UC("CADR");
           break;
        case CAR:
           return UC("CAR");
           break;
        case CDAR:
           return UC("CDAR");
           break;
        case CDDR:
           return UC("CDDR");
           break;
        case CDR:
           return UC("CDR");
           break;
        case CLOSURE:
           return UC("CLOSURE");
           break;
        case CONS:
           return UC("CONS");
           break;
        case CONSTANT:
           return UC("CONSTANT");
           break;
        case DEFINE_GLOBAL:
           return UC("DEFINE_GLOBAL");
           break;
        case DISPLAY:
           return UC("DISPLAY");
           break;
        case ENTER:
           return UC("ENTER");
           break;
        case EQ:
           return UC("EQ");
           break;
        case EQV:
           return UC("EQV");
           break;
        case EQUAL:
           return UC("EQUAL");
           break;
        case FRAME:
           return UC("FRAME");
           break;
        case INDIRECT:
           return UC("INDIRECT");
           break;
        case LEAVE:
           return UC("LEAVE");
           break;
        case LET_FRAME:
           return UC("LET_FRAME");
           break;
        case LIST:
           return UC("LIST");
           break;
        case LOCAL_JMP:
           return UC("LOCAL_JMP");
           break;
        case MAKE_CONTINUATION:
           return UC("MAKE_CONTINUATION");
           break;
        case MAKE_VECTOR:
           return UC("MAKE_VECTOR");
           break;
        case NOP:
           return UC("NOP");
           break;
        case NOT:
           return UC("NOT");
           break;
        case NULL_P:
           return UC("NULL_P");
           break;
        case NUMBER_ADD:
           return UC("NUMBER_ADD");
           break;
        case NUMBER_EQUAL:
           return UC("NUMBER_EQUAL");
           break;
        case NUMBER_GE:
           return UC("NUMBER_GE");
           break;
        case NUMBER_GT:
           return UC("NUMBER_GT");
           break;
        case NUMBER_LE:
           return UC("NUMBER_LE");
           break;
        case NUMBER_LT:
           return UC("NUMBER_LT");
           break;
        case NUMBER_MUL:
           return UC("NUMBER_MUL");
           break;
        case NUMBER_DIV:
           return UC("NUMBER_DIV");
           break;
        case NUMBER_SUB:
           return UC("NUMBER_SUB");
           break;
        case PAIR_P:
           return UC("PAIR_P");
           break;
        case READ:
           return UC("READ");
           break;
        case READ_CHAR:
           return UC("READ_CHAR");
           break;
        case REDUCE:
           return UC("REDUCE");
           break;
        case REFER_FREE:
           return UC("REFER_FREE");
           break;
        case REFER_GLOBAL:
           return UC("REFER_GLOBAL");
           break;
        case REFER_LOCAL:
           return UC("REFER_LOCAL");
           break;
        case RESTORE_CONTINUATION:
           return UC("RESTORE_CONTINUATION");
           break;
        case RETURN:
           return UC("RETURN");
           break;
        case SET_CAR:
           return UC("SET_CAR");
           break;
        case SET_CDR:
           return UC("SET_CDR");
           break;
        case SHIFT:
           return UC("SHIFT");
           break;
        case SYMBOL_P:
           return UC("SYMBOL_P");
           break;
        case TEST:
           return UC("TEST");
           break;
        case VALUES:
           return UC("VALUES");
           break;
        case RECEIVE:
           return UC("RECEIVE");
           break;
        case UNFIXED_JUMP:
           return UC("UNFIXED_JUMP");
           break;
        case STOP:
           return UC("STOP");
           break;
        case CONTINUATION_VALUES:
           return UC("CONTINUATION_VALUES");
           break;
        case SHIFTJ:
           return UC("SHIFTJ");
           break;
        case UNDEF:
           return UC("UNDEF");
           break;
        case VECTOR_LENGTH:
           return UC("VECTOR_LENGTH");
           break;
        case VECTOR_P:
           return UC("VECTOR_P");
           break;
        case VECTOR_REF:
           return UC("VECTOR_REF");
           break;
        case VECTOR_SET:
           return UC("VECTOR_SET");
           break;
        case PUSH_ENTER:
           return UC("PUSH_ENTER");
           break;
        case HALT:
           return UC("HALT");
           break;
        case CONSTANT_PUSH:
           return UC("CONSTANT_PUSH");
           break;
        case NUMBER_SUB_PUSH:
           return UC("NUMBER_SUB_PUSH");
           break;
        case NUMBER_ADD_PUSH:
           return UC("NUMBER_ADD_PUSH");
           break;
        case PUSH_CONSTANT:
           return UC("PUSH_CONSTANT");
           break;
        case PUSH_FRAME:
           return UC("PUSH_FRAME");
           break;
        case CAR_PUSH:
           return UC("CAR_PUSH");
           break;
        case CDR_PUSH:
           return UC("CDR_PUSH");
           break;
        case SHIFT_CALL:
           return UC("SHIFT_CALL");
           break;
        case NOT_TEST:
           return UC("NOT_TEST");
           break;
        case REFER_GLOBAL_CALL:
           return UC("REFER_GLOBAL_CALL");
           break;
        case REFER_FREE_PUSH:
           return UC("REFER_FREE_PUSH");
           break;
        case REFER_LOCAL_PUSH:
           return UC("REFER_LOCAL_PUSH");
           break;
        case REFER_LOCAL_PUSH_CONSTANT:
           return UC("REFER_LOCAL_PUSH_CONSTANT");
           break;
        case REFER_LOCAL_PUSH_CONSTANT_BRANCH_NOT_LE:
           return UC("REFER_LOCAL_PUSH_CONSTANT_BRANCH_NOT_LE");
           break;
        case REFER_LOCAL_PUSH_CONSTANT_BRANCH_NOT_GE:
           return UC("REFER_LOCAL_PUSH_CONSTANT_BRANCH_NOT_GE");
           break;
        case REFER_LOCAL_PUSH_CONSTANT_BRANCH_NOT_NUMBER_EQUAL:
           return UC("REFER_LOCAL_PUSH_CONSTANT_BRANCH_NOT_NUMBER_EQUAL");
           break;
        case REFER_LOCAL_BRANCH_NOT_NULL:
           return UC("REFER_LOCAL_BRANCH_NOT_NULL");
           break;
        case REFER_LOCAL_BRANCH_NOT_LT:
           return UC("REFER_LOCAL_BRANCH_NOT_LT");
           break;
        case REFER_FREE_CALL:
           return UC("REFER_FREE_CALL");
           break;
        case REFER_GLOBAL_PUSH:
           return UC("REFER_GLOBAL_PUSH");
           break;
        case REFER_LOCAL_CALL:
           return UC("REFER_LOCAL_CALL");
           break;
        case LOCAL_CALL:
           return UC("LOCAL_CALL");
           break;
        case VECTOR:
           return UC("VECTOR");
           break;
        default:
           return UC("Unkown Instruction");
           break;
        }
        return UC("");
    }


};
}; // namespace scheme

#endif // __SCHEME_INSTRUCTION_H__
