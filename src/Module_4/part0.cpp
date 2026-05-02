#include "../Module_1/natural.h"
#include "../Module_2/integer.h"
#include "../Module_3/rational.h"
#include "part0.h"

ostream& operator<<(ostream& os, const big_P& p) {
    if (p.monomials.empty() || (p.monomials.size() == 1 && p.monomials[0].val.up.digits[0] == 0)) {
        os << "0";
        return os;
    }
    bool prew_presset = ALWAYS_PRINT_SIGN;
    ALWAYS_PRINT_SIGN = 1;
    for (size_t i = 0; i < p.monomials.size(); i++) {
        const monomial& m = p.monomials[i];
        
        // Пропускаем нулевые коэффициенты
        if (m.val.up.digits.size() == 1 && m.val.up.digits[0] == 0) continue;
        
        // Вывод коэффициента
        os << m.val;
        
        
        // Вывод x и степени
        bool degree_is_zero = (!NZER_N_B(m.degree));
        bool degree_is_one = (COM_NN_D(m.degree, big_N("1")) == 0);
        
        if (!degree_is_zero) {
            os << "x";
            if (!degree_is_one) {
                os << "^" << m.degree;
            }
        }
    }
    ALWAYS_PRINT_SIGN = prew_presset;
    return os;
}