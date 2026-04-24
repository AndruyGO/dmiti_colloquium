#include "part0.h"
#include "part1.h"
#include "part2.h"
#include "part4.h"

int COM_NN_D(const big_N& x,const big_N& y){
    if (x.digits.size() > y.digits.size())
        return 2;
    if (x.digits.size() < y.digits.size())
        return 1;
    for (int i = x.digits.size() - 1; i >= 0; --i) {
        if (x.digits[i] > y.digits[i])
            return 2;
        if (x.digits[i] < y.digits[i])
            return 1;
    }
    return 0;
}

big_N SUB_NN_N(const big_N& x, const big_N& y) {
    big_N big = y;
    big_N small = x;
    int tmp = 0,res = 0, resize = 0;
    if (COM_NN_D(x,y) == 2) {
        big = x;
        small = y;
    }
    big_N result = big;
    for (int i = 0; i < big.digits.size(); i ++) {
        int big_i = big.digits[i];
        int small_i;
        if (i<small.digits.size())
            small_i = small.digits[i];
        else
            small_i = 0;
        res = big_i - small_i;
        res -= tmp;
        if (res < 0) {
            res += 10;
            tmp = 1;
        }
        else
            tmp = 0;
        result.digits[i] = res;
    }
    for (int i = big.digits.size() - 1; result.digits[i] ==0 && i > 0; i--)
        resize += 1;
    result.digits.resize(result.digits.size() - resize);
    return result;
}

big_N GCF_NN_N(big_N x, big_N y) {
    if (!NZER_N_B(x))
        return y;
    if (!NZER_N_B(y))
        return x;
    while (NZER_N_B(y)) {
        big_N r = MOD_NN_N(x, y);
        x = y;
        y = r;
    }
    return x;
}

big_N LCM_NN_N(big_N x, big_N y) {
    if( !NZER_N_B(x) || !NZER_N_B(y))
        return big_N("0");
    big_N gcf = GCF_NN_N(x, y);
    return MUL_NN_N(DIV_NN_N(x, gcf), y);
}
