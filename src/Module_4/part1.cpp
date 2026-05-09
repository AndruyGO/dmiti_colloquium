#include "part0.h"
#include "part1.h"
#include "part2.h"
#include "../Module_2/integer.h"
#include "../Module_3/rational.h"

big_P ADD_PP_P(big_P p, big_P q) {
    
    big_P res;
    
    sort(p.monomials.begin(), p.monomials.end());
    sort(q.monomials.begin(), q.monomials.end());
    
    auto p_it = p.monomials.begin();
    auto q_it = q.monomials.begin();
    
    // Итерируем по мономам многочленов
    while (p_it != p.monomials.end() && q_it != q.monomials.end()) {
        char comp = COM_NN_D((*p_it).degree, (*q_it).degree);
        if (comp == 0) {
            big_Q addition = ADD_QQ_Q((*p_it).val, (*q_it).val);
            if (NZER_N_B(addition.up)) {
                monomial mn {(*p_it).degree, addition};
                res.monomials.push_back(mn);
            }
            p_it++;
            q_it++;
        } else if (comp == 1) {
            // Если степень первого меньше добавляем его
            res.monomials.push_back((*p_it++));
        } else if (comp == 2) {
            // Иначе добавляем другой
            res.monomials.push_back((*q_it++));
        }
    }
    // Добавляем оставшиеся мономы
    while (p_it != p.monomials.end()) {
        res.monomials.push_back((*p_it++));
    }
    while (q_it != q.monomials.end()) {
        res.monomials.push_back((*q_it++));
    }
    return res;
}

big_P SUB_PP_P(const big_P& p, const big_P& q) {
    big_P temp = MUL_PQ_P(q, big_Q("-1"));
    return ADD_PP_P(p, temp);
}