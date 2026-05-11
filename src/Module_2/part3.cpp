/*
    Разработчик: Лысенко Денис 5385
*/

#include "integer.h"
#include "../Module_1/part1.h"
#include "../Module_1/part3.h"
#include "../Module_1/part4.h"


big_Z ABS_Z_Z (const big_Z& x) {
    return big_Z(1, x.digits);
}

big_Z ADD_ZZ_Z(const big_Z& x, const big_Z& y) {
    big_Z res;
    big_N nat_x, nat_y;
    if (SGN_Z_D(x) == 0) return y;
    if (SGN_Z_D(y) == 0) return x;
    if (SGN_Z_D(x) == 1 && SGN_Z_D(y) == 1) { // Оба больше 0
        res = TRANS_N_Z(ADD_NN_N(TRANS_Z_N(x), TRANS_Z_N(y)));
        return res;
    }
    nat_x = TRANS_Z_N(ABS_Z_Z(x));
    nat_y = TRANS_Z_N(ABS_Z_Z(y)); 
    if (SGN_Z_D(x) == -1 && SGN_Z_D(y) == -1) {
        res.sign = 1;
        res = MUL_ZM_Z(TRANS_N_Z(ADD_NN_N(nat_x, nat_y)));
        return res;
    }
    if (COM_NN_D(nat_x, nat_y) == 0) {
        res = big_Z("+0");
        return res;
    }
    if (COM_NN_D(nat_x, nat_y) == 1){
        res = TRANS_N_Z(SUB_NN_N(nat_y, nat_x));
        if (SGN_Z_D(y) == -1) {
            res = MUL_ZM_Z(res);
        }
        return res;
    }
    res = TRANS_N_Z(SUB_NN_N(nat_x, nat_y));
    if (SGN_Z_D(x) == -1) {
        res = MUL_ZM_Z(res);
    }
    return res;
}

big_Z SUB_ZZ_Z(const big_Z& x, const big_Z& y) {
    return ADD_ZZ_Z(x, MUL_ZM_Z(y));
}