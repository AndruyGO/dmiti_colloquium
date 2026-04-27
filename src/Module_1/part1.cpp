#include "part0.h"
#include "part1.h"
#include "part2.h"
#include "part3.h"
#include "part4.h"

char DIV_NN_Dk(const big_N& n, const big_N& m, long long k) {
    // Вычисление m * 10^k
    big_N shifted = MUL_Nk_N(m, k);
    // Если делимое меньше сдвинутого делителя, первая цифра 0
    if (COM_NN_D(n, shifted) == 1) {
        return 0;
    }
    // Поиск наибольшей цифры d (1..9), такой что d * (m*10^k) <= n
    for (char d = 9; d >= 1; --d) {
        big_N product = MUL_ND_N(shifted, d);
        if (COM_NN_D(n, product) != 1) { // n >= product
            return d;
        }
    }
    return 0;
}

big_N DIV_NN_N(const big_N& n, const big_N& m) {
    // Если n < m, частное 0
    if (COM_NN_D(n, m) == 1) {
        return big_N("0");
    }
    big_N remainder = n;
    big_N quotient = big_N("0");
    // Максимальный порядок k, на который можно сдвинуть делитель
    int max_k = remainder.digits.size() - m.digits.size();
    if (max_k < 0) max_k = 0;
    for (long long k = max_k; k >= 0; --k) {
        char d = DIV_NN_Dk(remainder, m, k);
        if (d != 0) {
            // Добавляем d * 10^k к частному
            big_N digit_num = big_N(std::string(1, d + '0'));
            big_N term = MUL_Nk_N(digit_num, k);
            quotient = ADD_NN_N(quotient, term);
            // Вычитаем d * (m * 10^k) из остатка
            big_N m_shifted = MUL_Nk_N(m, k);
            big_N to_sub = MUL_ND_N(m_shifted, d);
            remainder = SUB_NN_N(remainder, to_sub);
        }
    }
    return quotient;
}

big_N MOD_NN_N(const big_N& n, const big_N& m) {
    if (COM_NN_D(n, m) == 1)
        return n;
    big_N q = DIV_NN_N(n, m);
    big_N product = MUL_NN_N(m, q);
    return SUB_NN_N(n, product);
}