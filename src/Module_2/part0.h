#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "../Module_1/part4.h"
#ifndef _INTEGER_PART0
#define _INTEGER_PART0
using namespace std;

extern bool ALWAYS_PRINT_SIGN;

class big_Z{
    public:
    char sign;
    vector<char> digits; /// "123" -> 1, [3] [2] [1] | +123 -> 1 [3] [2] [1] | -123 -> 0 [3] [2] [1]
    friend ostream& operator<<(ostream& os, const big_Z& obj);

	big_Z(){}

    big_Z(char _sign, const vector<char> &_digits){
        sign = _sign;
        digits.resize(_digits.size());
        for(int i = 0; i < digits.size(); i++){
            digits[i] = _digits[i];
        }
    }

    big_Z(const string &_digits){
        int start;
        unsigned long size = _digits.size();
        if(_digits[0] == '-'){
            sign = -1;
            start = 1;
            size--;
        }else if(_digits[0] == '+'){
            sign = 1;
            start = 1;
            size--;
        }else{
            sign = 1;
            start = 0;
        }
        digits.resize(size); 
        for (int i=start; i < size+start; i++) {
            digits[size-1-i+start] = _digits[i] - '0';
        }
    }
};
ostream& operator << (ostream& os, const big_Z& n);
char NZER_Z_B(const big_Z &z);

#endif