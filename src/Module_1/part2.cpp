/*
    Разработчик: Лысенко Артём 5385
*/

#include "part0.h"
#include "part1.h"
#include "part3.h"
#include "part4.h"


big_N MUL_ND_N(big_N n, char digit) {
    if (digit < 0 || digit > 9) return big_N("");
    unsigned long size = n.digits.size();
    char remn = 0;
    char num;

    for (unsigned long i=0; i < size; i ++) {
        num = n.digits[i]*digit + remn;
        remn = num / 10;
        n.digits[i] = num % 10;
    }
    if (remn != 0) {
        n.digits.resize(size+1);
        n.digits[size] = remn;
    }
    return n;
}

big_N MUL_Nk_N(big_N n, unsigned long k) {
    if (k == 0) return n;
    unsigned long size = n.digits.size();
    n.digits.resize(size + k);
    // Сдвигаем все цифры вправо на k позиций
    for (unsigned long i = size; i > 0; --i) {
        n.digits[i + k - 1] = n.digits[i - 1];
    }
    // Заполняем младшие k разрядов нулями
    for (unsigned long i = 0; i < k; ++i) {
        n.digits[i] = 0;
    }
    return n;
}

big_N MUL_NN_N(const big_N &n, const big_N &m) {
    big_N res = big_N("0");
    // Перебираем цифры второго числа от младших к старшим
    for (unsigned long i = 0; i < m.digits.size(); ++i) {
        char digit = m.digits[i];               // цифра разряда 10^i
        big_N tmp = n;                           // копируем n
        tmp = MUL_Nk_N(tmp, i);                  // умножаем на 10^i
        tmp = MUL_ND_N(tmp, digit);              // умножаем на цифру
        res = ADD_NN_N(res, tmp);                // добавляем к результату
    }
    return res;
}
