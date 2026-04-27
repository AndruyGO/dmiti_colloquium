#include "part0.h"
#include "../Module_1/part4.h"

char NZER_Z_B(const big_Z &n){
    return NZER_N_B(n.digits);
}

ostream& operator << (ostream& os, const big_Z& n) {
    unsigned long size = n.digits.size();
    if(ALWAYS_PRINT_SIGN && n.sign == 1 && NZER_Z_B(n)) os << '+';
    for (int i = 0; i < size; i++) {
        os << (int) n.digits[size-1-i];
    }
    return os;
}


