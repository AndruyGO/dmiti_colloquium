#include "part0.h"
#include "../Module_1/part0.h"
#include "../Module_1/part1.h"
#include "../Module_1/part3.h"
#include "../Module_1/part4.h"


big_Z TRANS_N_Z(const big_N &n) {
    // Перевод натурального числа в целое
    if (NZER_N_B(n)) 
        return big_Z("0");
    return big_Z(1, n.digits);
}

big_N TRANS_Z_N(const big_Z &z) {
    // Перевод целого неотрицательного числа в натуральное
    if (SGN_Z_D(z) == -1) return big_N();
    return big_N(z.digits);
}

big_Z MOD_ZZ_Z(const big_Z &a, const big_Z &b) {
    // Остаток от деления целых чисел
    // Делитель 0
    if (SGN_Z_D(b) == 0) return big_Z("");
    // Делимое 0
    if (SGN_Z_D(a) == 0) return big_Z("0");

    big_Z k = DIV_ZZ_Z(a, b);

    // Делимое больше 0
    if (SGN_Z_D(a) == 1) 
        return SUB_ZZ_Z(a, MUL_ZZ_Z(b, k));

    // Делимое меньше 0
    return ADD_ZZ_Z(ABS_Z_Z(MUL_ZZ_Z(b, k)), a);


}
