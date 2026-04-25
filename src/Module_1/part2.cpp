#include "part0.h"
#include "part1.h"


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

big_N MUL_Nk_N(big_N n, long long k) {
    if (k < 0) return big_N("");
    unsigned long size = n.digits.size()+k;
    n.digits.resize(size);
    for (unsigned long i = size-k; i > 0; i--) {
        n.digits[i+k-1] = n.digits[i-1];
        n.digits[i-1] = 0;
    }
    return n;
}

big_N MUL_NN_N(big_N n, big_N m) {
    big_N res = big_N("0");
    for (unsigned long i=0; i < m.digits.size(); i++) {
        big_N tmp = big_N(n.digits);
        tmp = MUL_Nk_N(tmp, i);
        tmp = MUL_ND_N(tmp, m.digits[m.digits.size()-i-1]);
        res = ADD_NN_N(res, tmp);
    }
    return res;
}
