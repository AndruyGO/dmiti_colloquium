/*
    Разработчик: Лысенко Артём 5385
*/

#include "part0.h"
#include "part1.h"
#include "part3.h"
#include "../Module_3/part3.h"
#include <algorithm>



big_Q LED_P_Q(const big_P &p) {
    monomial m = *max_element(p.monomials.begin(), p.monomials.end());
    return m.val;
}

big_P MUL_PQ_P(big_P p, const big_Q &q) {
    for (unsigned long i=0; i < p.monomials.size(); i++) {
        p.monomials[i].val = MUL_QQ_Q(p.monomials[i].val, q);
    }
    return p;
}

// type отвечает за операцию 1 - деление, 0 - остаток
big_P DIV_MOD_PP(big_P p, const big_P &d, char type) {
    big_P tmp;
    big_N deg;
    big_Q multiplicator;
    vector<monomial> res;
    // Цикл пока степень первого мноогочлена больше или равна степени второго
    while (COM_NN_D(DEG_P_N(p), DEG_P_N(d)) != 1) {
        // разница степеней
        deg = SUB_NN_N(DEG_P_N(p), DEG_P_N(d));
        // Нахождение множителя коэффициентов
        multiplicator = big_Q(LED_P_Q(d).sign, LED_P_Q(d).down, LED_P_Q(d).up);
        multiplicator = MUL_QQ_Q(multiplicator, LED_P_Q(p));
        res.push_back({deg, multiplicator});

        // Создание промежуточного многочлена который вычитается из основного
        tmp = MUL_PQ_P(d, multiplicator);
        tmp = MUL_Pxk_P(tmp, deg);

        // Вычитание из основного многочлена промежуточного
        p = SUB_PP_P(p, tmp);
    }
    if (type == 1)  return big_P(res); // Частное
    if (type == 0) return p;  //Остаток
}

big_P DIV_PP_P(big_P p, const big_P &d) {
    return DIV_MOD_PP(p, d, 1);
}

big_P MOD_PP_P(big_P p, const big_P &d) {
    return DIV_MOD_PP(p, d, 0);
}

