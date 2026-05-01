#include "part3.h"
#include "part0.h"
#include "../Module_1/natural.h"

big_Q MUL_QQ_Q(const big_Q& x, const big_Q& y) {
    big_Q result = big_Q(x.sign * y.sign, MUL_NN_N(x.up, y.up), MUL_NN_N(x.down, y.down));
    if (NZER_N_B(result.up) == 0)
        result.sign = 1;
    return result;
}

big_Q DIV_QQ_Q(const big_Q& x, const big_Q& y) {
    big_Q result = big_Q(x.sign * y.sign, MUL_NN_N(x.up, y.down), MUL_NN_N(x.down, y.up));
    if (NZER_N_B(result.up) == 0)
        result.sign = 1;
    return result;
}
