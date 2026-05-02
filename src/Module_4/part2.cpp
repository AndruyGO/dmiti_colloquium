#include "part0.h"
#include "../Module_3/part0.cpp"
#include <algorithm>



big_Q LED_P_Q(const big_P &p) {
    monomial m = *max_element(p.monomials.begin(), p.monomials.end());
    return m.val;
}

big_P MUL_PQ_P(big_P p, const big_Q &q) {
    for (unsigned long i=0; i < p.monomials.size(); i++) {
        p.monomials[i].val = MUL_QQ_Q(p.monomials[i].val, q);
    }
    return p;
}
