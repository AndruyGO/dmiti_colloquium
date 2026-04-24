#include "part0.h"

ostream& operator << (ostream& os, const big_N& n) {
    unsigned long size = n.digits.size();
    for (int i = 0; i < size; i++) {
        os << (int) n.digits[size-1-i];
    }
    return os;
}


