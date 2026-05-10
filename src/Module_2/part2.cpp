#include "integer.h"
#include "../Module_1/natural.h"


big_Z TRANS_N_Z(const big_N &n) {
    if (!NZER_N_B(n)) 
        return big_Z("0");
    return big_Z(1, n.digits);
}

big_N TRANS_Z_N(const big_Z &z) {
    if (SGN_Z_D(z) == -1) return big_N();
    return big_N(z.digits);
}

// Переписать потом под норм модуль
big_Z MOD_ZZ_Z(const big_Z &a, const big_Z &b) {
    if (SGN_Z_D(b) == 0) return big_Z();
    if (SGN_Z_D(a) == 0) return big_Z("0");

    big_Z k = DIV_ZZ_Z(a, b);
    
    // 1. УБРАЛ условный оператор if/else
    // 2. ВСЕГДА вычисляем r = a - b*k (это работает для любых знаков)
    big_Z r = SUB_ZZ_Z(a, MUL_ZZ_Z(b, k));
    
    // 3. ДОБАВИЛ проверку и коррекцию отрицательного остатка
    if (SGN_Z_D(r) == -1) {
        big_Z abs_b = ABS_Z_Z(b);
        r = ADD_ZZ_Z(r, abs_b);
    }
    
    return r;
}
