#include "part0.h"
#include "part2.h"
#include "part3.h"
#include "../Module_1/part3.h"
#include "../Module_1/part2.h"


big_P DER_P_P(const big_P& p) {
    if (p.monomials.size() == 0) return p;
    big_P res;
    for (int i = 0; i < (int)p.monomials.size(); i++) {
        big_N deg = p.monomials[i].degree;
        big_Q val = p.monomials[i].val;

        if (!NZER_N_B(deg)) continue; // Если степень монома 0

        val.up = MUL_NN_N(val.up, deg);
        if(ALWAYS_REDUCE) val = RED_Q_Q(val);
        
        deg = SUB_NN_N(deg, big_N("1"));
        if (NZER_N_B(val.up)) {
            monomial m;
            m.degree = deg;
            m.val = val;
            res.monomials.push_back(m);
        }
    }
    return res;
}

big_P GCF_PP_P(big_P a, big_P b) {

    if (!NZER_P_B(a)) return b;
    if (!NZER_P_B(b)) return a;

    int iteration = 0;
    while (NZER_P_B(b) && NZER_P_B(a) && iteration < 100) {
        iteration++;

        // Проверка на константу
        {
            int is_const = 1;
            for (int i = 0; i < (int)b.monomials.size(); i++) {
                if (NZER_N_B(b.monomials[i].degree)) {
                    is_const = 0;
                    break;
                }
            }
            if (is_const) {
                big_P one;
                monomial m;
                m.degree = big_N("0");
                m.val = big_Q(1, big_N("1"), big_N("1"));
                one.monomials.push_back(m);
                return one;
            }
        }

        big_P r = MOD_PP_P(a, b);
        a = b;
        b = r;
    }

    big_P res = a;
    if (res.monomials.size() != 0 && NZER_P_B(res)) {
        res = DIV_PQ_P(res, res.monomials[0].val);
    }
    return res;
}

// НОРМИРОВКА (NMR)
big_P NMR_P_P(const big_P& p) {
    big_P der = DER_P_P(p);

    if (der.monomials.empty() || 
    (der.monomials.size() == 1 && !NZER_N_B(der.monomials[0].degree))) 
        return p;

    der = DIV_PQ_P(der, LED_P_Q(der));
    big_P gcd = GCF_PP_P(p, der);
    
    // Если gcd пустой или ноль, возвращаем p
    if (gcd.monomials.empty() || 
        (gcd.monomials.size() == 1 && gcd.monomials[0].val.up.digits[0] == 0)) {
        return p;
    }
    
    return DIV_PP_P(p, gcd);
}