#include "part0.h"
#include "../Module_1/part0.h"
#include "../Module_2/part0.h"



ostream& operator << (ostream& os, const big_Q& q) {
    bool is_zero = (q.up.digits.size() == 1 && q.up.digits[0] == 0);
    
    // Вывод знака
    if (q.sign == -1) {
        os << '-';
    } else if (ALWAYS_PRINT_SIGN && !is_zero) {
        os << '+';
    }
    
    // Вывод числителя
    unsigned long up_size = q.up.digits.size();
    for (int i = 0; i < up_size; i++) {
        os << (int) q.up.digits[up_size-1-i];
    }
    
    // Вывод знаменателя (если не 1)
    if (!(q.down.digits.size() == 1 && q.down.digits[0] == 1)) {
        os << '/';
        unsigned long down_size = q.down.digits.size();
        for (int i = 0; i < down_size; i++) {
            os << (int) q.down.digits[down_size-1-i];
        }
    }
    
    return os;
}