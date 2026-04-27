#include "part0.h"
#include "../Module_1/part0.h"
#include "part1.h"
#include "../Module_1/part1.h"
#include "part3.h"
#include "../Module_1/part4.h"

char POZ_Z_D(const big_Z& z) {
    if (z.digits.size() == 1 && z.digits[0] == 0)
        return 0;
    if (z.sign == 1)
        return 1;
    return -1;
}

big_Z DIV_ZZ_Z(const big_Z& x, const big_Z& y) {
    if (POZ_Z_D(y) == 0)
        return big_Z {};
    if (POZ_Z_D(x) == 0)
        return big_Z {"0"};

    big_N abs_x {ABS_Z_N(x)};
    big_N abs_y {ABS_Z_N(y)};

    big_N quotinent {DIV_NN_N(abs_x, abs_y)};

    if (POZ_Z_D(x) == POZ_Z_D(y)) {
        big_Z res;
        res.sign = 1;
        res.digits = quotinent.digits;
        return res;
    } else {
        quotinent = ADD_1N_N(quotinent);
        big_Z res;
        res.sign = 0;
        res.digits = quotinent.digits;
        return res;
    }
}
