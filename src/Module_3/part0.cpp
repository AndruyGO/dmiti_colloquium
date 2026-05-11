/*
    Разработчик: Зейбель Андрей 5385
*/

#include "part0.h"
#include "../Module_1/part0.h"
#include "../Module_1/part3.h"
#include "../Module_2/part0.h"


bool ALWAYS_PRINT_DENOMINATOR = 1;
bool ALWAYS_REDUCE = 1;

ostream& operator << (ostream& os, const big_Q& q) {
    if(!NZER_N_B(q.up)) { os << "0"; return os; }
    // Вывод знака
    if (q.sign == -1) {
        os << '-';
    } else if (ALWAYS_PRINT_SIGN) {
        os << '+';
    }
    
    // Вывод числителя
    unsigned long up_size = q.up.digits.size();
    for (int i = 0; i < up_size; i++) {
        os << (int) q.up.digits[up_size-1-i];
    }
    
    // Вывод знаменателя (если не 1)
    if(COM_NN_D(q.down, big_N("1")) != 0 || ALWAYS_PRINT_DENOMINATOR){
        os << '/';
        unsigned long down_size = q.down.digits.size();
        for (int i = 0; i < down_size; i++) {
            os << (int) q.down.digits[down_size-1-i];
        }
    }
    
    return os;
}