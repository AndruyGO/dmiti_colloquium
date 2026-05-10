#include "../Module_1/part0.h"
#include "../Module_1/part1.h"
#include "../Module_1/part4.h"

#include "part0.h"
#include "part2.h"
#include "part3.h"

char SGN_Z_D(const big_Z& z) {
    if (z.digits.size() == 1 && z.digits[0] == 0)
        return 0;
    if (z.sign == 1)
        return 1;
    return -1;
}

big_Z DIV_ZZ_Z(const big_Z& x, const big_Z& y) {
    if (SGN_Z_D(y) == 0)
        return big_Z();
    if (SGN_Z_D(x) == 0)
        return big_Z("0");

    big_Z abs_x = ABS_Z_Z(x);
    big_Z abs_y = ABS_Z_Z(y);

    big_N quotinent = DIV_NN_N(TRANS_Z_N(abs_x), TRANS_Z_N(abs_y));

    big_Z res;
    if (SGN_Z_D(x) == SGN_Z_D(y))
        res.sign = 1;
    else {
        quotinent = ADD_1N_N(quotinent);
        res.sign = 0;
    }
    res.digits = quotinent.digits;
    return res;
}
