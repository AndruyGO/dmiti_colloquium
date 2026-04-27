#include "../Module_1/part0.h"
#include "part0.h"
#include "part1.h"
#include "part2.h"

big_Z MUL_ZM_Z (big_Z z){
    z.sign = (z.sign == 1) ? 0 : 1;
    return z;
}
big_Z MUL_ZZ_Z(const big_Z& z1,const big_Z& z2){
    big_Z res;
    if (SGN_Z_D(z1) == 0 || SGN_Z_D(z2) == 0){
        res.sign = 0;
        res.digits.push_back(0);
        return res;
    }
    else{
        res.sign = (SGN_Z_D(z1) == SGN_Z_D(z2)) ? 0 : 1;
        big_N mul = MUL_NN_N(big_N(z1.digits), big_N(z2.digits));
        res.digits = mul.digits;
        return res;
    }
}