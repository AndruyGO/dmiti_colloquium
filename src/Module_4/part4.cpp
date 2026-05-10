#include "part0.h"
#include "part2.h"
#include "part3.h"
#include "../Module_1/part3.h"
#include "../Module_1/part2.h"

// ─────────────────────────────────────────────────────
// ВСПОМОГАТЕЛЬНЫЕ
// ─────────────────────────────────────────────────────

int IS_ZERO_P(const big_P& p) {
    if (p.monomials.size() == 0) return 1;
    for (int i = 0; i < (int)p.monomials.size(); i++) {
        if (p.monomials[i].val.up.digits.size() != 1 ||
            p.monomials[i].val.up.digits[0] != 0) {
            return 0;
        }
    }
    return 1;
}

big_P CLEAN_P(big_P p) {
    big_P res;
    for (int i = 0; i < (int)p.monomials.size(); i++) {
        if (p.monomials[i].val.up.digits.size() != 1 ||
            p.monomials[i].val.up.digits[0] != 0) {
            res.monomials.push_back(p.monomials[i]);
        }
    }
    sort(res.monomials.begin(), res.monomials.end());
    return res;
}

// ─────────────────────────────────────────────────────
// ПРОИЗВОДНАЯ
// ─────────────────────────────────────────────────────

big_P DER_P_P(const big_P& p) {
    if (p.monomials.size() == 0) return p;
    big_P res;
    for (int i = 0; i < (int)p.monomials.size(); i++) {
        big_N deg = p.monomials[i].degree;
        big_Q val = p.monomials[i].val;
        if (deg.digits.size() == 1 && deg.digits[0] == 0) continue;
        val.up = MUL_NN_N(val.up, deg);
        deg = SUB_NN_N(deg, big_N("1"));
        if (val.up.digits.size() != 1 || val.up.digits[0] != 0) {
            monomial m;
            m.degree = deg;
            m.val = val;
            res.monomials.push_back(m);
        }
    }
    return res;
}

// ─────────────────────────────────────────────────────
// НОД (GCF)
// ─────────────────────────────────────────────────────

big_P GCF_PP_P(const big_P& p1, const big_P& p2) {
    big_P a = CLEAN_P(p1);
    big_P b = CLEAN_P(p2);

    if (IS_ZERO_P(a)) return CLEAN_P(b);
    if (IS_ZERO_P(b)) return CLEAN_P(a);

    int iteration = 0;
    while (!IS_ZERO_P(b) && iteration < 100) {
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

        big_P r = CLEAN_P(MOD_PP_P(a, b));
        a = b;
        b = r;
    }

    big_P res = CLEAN_P(a);
    if (res.monomials.size() != 0 && !IS_ZERO_P(res)) {
        res = DIV_PQ_P(res, res.monomials[0].val);
    }
    return res;
}

// ─────────────────────────────────────────────────────
// НОРМИРОВКА (NMR)
// ─────────────────────────────────────────────────────

big_P NMR_P_P(const big_P& p) {
    if (p.monomials.size() == 0) return p;
    if (IS_ZERO_P(p)) return p;

    big_P der = DER_P_P(p);
    if (IS_ZERO_P(der)) return p;

    big_P nod = GCF_PP_P(p, der);
    if (IS_ZERO_P(nod)) return p;

    // Проверка на константу
    {
        int is_const = 1;
        for (int i = 0; i < (int)nod.monomials.size(); i++) {
            if (NZER_N_B(nod.monomials[i].degree)) {
                is_const = 0;
                break;
            }
        }
        if (is_const) {
            return CLEAN_P(DIV_PQ_P(p, nod.monomials[0].val));
        }
    }
    return CLEAN_P(DIV_PP_P(p, nod));

}