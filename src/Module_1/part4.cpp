#include "part0.h"
#include "part2.h"
#include "part3.h"

char NZER_N_B(const big_N& n) {
    if (n.digits.size() == 1 && n.digits[0] == 0){
        return 0;
    }
    return 1;
}

big_N ADD_1N_N(big_N n){
    int i =0;
    while(i < n.digits.size()){
        if (n.digits[i] == 9){
            n.digits[i] = 0; 
            i++;
        }
        else{
            n.digits[i]+= 1;
            return n;
        }
    }
    n.digits.push_back(1);
    return n;
}

big_N ADD_NN_N(const big_N &n1, const big_N &n2) {
    big_N result;
    result.digits.clear(); 
    
    int overflow = 0;
    int i = 0;
    
    while (i < n1.digits.size() || i < n2.digits.size() || overflow > 0) {
        int sum = overflow;
        
        if (i < n1.digits.size()) sum += n1.digits[i];
        if (i < n2.digits.size()) sum += n2.digits[i];
        
        result.digits.push_back(sum % 10);
        overflow = sum / 10;              
        i++;
    }
    
    return result;
}

big_N SUB_NDN_N(const big_N& n1, const big_N& n2, int k) {
    big_N mul_n2 = MUL_ND_N(n2, k);
    int cmp = COM_NN_D(n1, mul_n2);
    if (cmp != 1) {
        return SUB_NN_N(n1, mul_n2);
    }
    return big_N("");
}
