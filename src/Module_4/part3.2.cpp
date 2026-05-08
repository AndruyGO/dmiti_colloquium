#include "part0.h"
#include "part2.h"
#include "part1.h"
#include "part3.2.h"
#include "../Module_1/natural.h"
#include "../Module_2/integer.h"
#include "../Module_3/rational.h"

big_P MUL_Pxk_P(const big_P& p, const big_N& k) {
    big_P result = p;
    for (size_t i = 0; i < result.monomials.size(); i++) {
        result.monomials[i].degree = ADD_NN_N(result.monomials[i].degree, k);
    }
    return result;
}

big_P MUL_PP_P(const big_P& p1, const big_P& p2) {
    big_P result;
    for (size_t i = 0; i < p1.monomials.size(); i++) {
        big_P tmp = MUL_Pxk_P(MUL_PQ_P(p2,p1.monomials[i].val),p1.monomials[i].degree);
        result = ADD_PP_P(result,tmp);
    }
    return result;
}