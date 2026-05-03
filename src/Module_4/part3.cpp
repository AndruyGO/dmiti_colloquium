#include "part 3.h"
#include "part0.h"
#include "../Module_1/natural.h"
#include "../Module_2/integer.h"

big_N DEG_P_N(const big_P& p) {
    if (p.monomials.empty()) {
        return big_N("0");
    }
    return p.monomials[0].degree;
}

big_Q FAC_P_Q(big_P& p) {
    if (p.monomials.empty()) {
        return big_Q("0");
    }
    big_N up = ABS_Z_N(p.monomials[0].val.up);
    big_N down = p.monomials[0].val.down;
    for (size_t i = 1; i < p.monomials.size(); i++) {
        up = GCF_NN_N(up, ABS_Z_N(p.monomials[i].val.up));
        down = LCM_NN_N(down, p.monomials[i].val.down);
    }
    big_Q div = big_Q(TRANS_N_Z(up), TRANS_N_Z(down));
    for (size_t i = 0; i < p.monomials.size(); i++) {
        p.monomials[i].val = DIV_QQ_Q(p.monomials[i].val, div);
    }

    return div;
}