// Do not edit this file generated by gen-insn.scm
#ifndef __SCHEME_INSTRUCTION_H__
#define __SCHEME_INSTRUCTION_H__

#include "scheme.h"

namespace scheme {

class Instruction EXTEND_GC
{
public:
    enum {
        APPEND = 14,
        CALL = 46,
        APPLY = 78,
        PUSH = 110,
        ASSIGN_FREE = 142,
        ASSIGN_GLOBAL = 174,
        ASSIGN_LOCAL = 206,
        BOX = 238,
        CAAR = 270,
        CADR = 302,
        CAR = 334,
        CDAR = 366,
        CDDR = 398,
        CDR = 430,
        CLOSURE = 462,
        CONS = 494,
        CONSTANT = 526,
        DEFINE_GLOBAL = 558,
        DISPLAY = 590,
        ENTER = 622,
        EQ = 654,
        EQV = 686,
        EQUAL = 718,
        FRAME = 750,
        IMPORT = 782,
        INDIRECT = 814,
        LEAVE = 846,
        LET_FRAME = 878,
        LIBRARY = 910,
        LIST = 942,
        LOCAL_JMP = 974,
        MAKE_CONTINUATION = 1006,
        MAKE_VECTOR = 1038,
        NOP = 1070,
        NOT = 1102,
        NULL_P = 1134,
        NUMBER_ADD = 1166,
        NUMBER_EQUAL = 1198,
        NUMBER_GE = 1230,
        NUMBER_GT = 1262,
        NUMBER_LE = 1294,
        NUMBER_LT = 1326,
        NUMBER_MUL = 1358,
        NUMBER_DIV = 1390,
        NUMBER_SUB = 1422,
        PAIR_P = 1454,
        READ = 1486,
        READ_CHAR = 1518,
        REDUCE = 1550,
        REFER_FREE = 1582,
        REFER_GLOBAL = 1614,
        REFER_LOCAL = 1646,
        RESTORE_CONTINUATION = 1678,
        RETURN = 1710,
        SET_CAR = 1742,
        SET_CDR = 1774,
        SHIFT = 1806,
        SYMBOL_P = 1838,
        TEST = 1870,
        UNDEF = 1902,
        VECTOR_LENGTH = 1934,
        VECTOR_P = 1966,
        VECTOR_REF = 1998,
        VECTOR_SET = 2030,
        CONSTANT_PUSH = 2062,
        REFER_LOCAL0 = 2094,
        REFER_LOCAL1 = 2126,
        REFER_LOCAL2 = 2158,
        REFER_LOCAL3 = 2190,
        REFER_FREE0 = 2222,
        REFER_FREE1 = 2254,
        REFER_FREE2 = 2286,
        REFER_FREE3 = 2318,
        REFER_LOCAL0_PUSH = 2350,
        REFER_LOCAL0_PUSH_CONSTANT = 2382,
        REFER_LOCAL1_PUSH_CONSTANT = 2414,
        REFER_LOCAL1_PUSH = 2446,
        NUMBER_SUB_PUSH = 2478,
        PUSH_ENTER = 2510,
        HALT = 2542,
        LEAVE1 = 2574,
        CALL1 = 2606,
        NUMBER_LE_TEST = 2638,
        NUMBER_ADD_PUSH = 2670,
        RETURN1 = 2702,
        RETURN2 = 2734,
        RETURN3 = 2766,
        CALL2 = 2798,
        REFER_LOCAL0_EQV_TEST = 2830,
        PUSH_CONSTANT = 2862,
        PUSH_FRAME = 2894,
        REFER_FREE0_PUSH = 2926,
        REFER_FREE1_PUSH = 2958,
        REFER_FREE2_PUSH = 2990,
        CAR_PUSH = 3022,
        CDR_PUSH = 3054,
        REFER_FREE0_INDIRECT = 3086,
        REFER_FREE1_INDIRECT = 3118,
        REFER_LOCAL2_PUSH = 3150,
        SHIFT_CALL = 3182,
        CALL3 = 3214,
        NOT_TEST = 3246,
        REFER_GLOBAL_CALL = 3278,
        REFER_LOCAL0_NUMBER_ADD_PUSH = 3310,
        REFER_LOCAL0_VECTOR_SET = 3342,
        REFER_LOCAL0_VECTOR_REF = 3374,
        REFER_FREE_PUSH = 3406,
        REFER_LOCAL_PUSH = 3438,
        VALUES = 3470,
        RECEIVE = 3502,
    };
};
}; // namespace scheme

#endif // __SCHEME_INSTRUCTION_H__