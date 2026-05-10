#ifndef _RATIONAL_PART0
#define _RATIONAL_PART0

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "../Module_1/part0.h"
#include "../Module_2/part0.h"

using namespace std;


extern bool ALWAYS_PRINT_DENOMINATOR;
extern bool ALWAYS_REDUCE;

class big_Q{
    public:
    char sign;
    big_N up;    // числитель
    big_N down;  // знаменатель (всегда > 0)

    friend ostream& operator<<(ostream& os, const big_Q& obj);

    big_Q(){}
    
    big_Q(char _sign, const big_N &_up, const big_N &_down){
        sign = _sign; up = _up; down = _down;
    }

    big_Q(const string &_digits){
        // Ищем разделитель '/'
        size_t slash_pos = _digits.find('/');
        
        // Определяем знак и начало числителя
        int start;
        unsigned long size;
        
        if(slash_pos == string::npos){
            // Нет знаменателя - целое число
            down = big_N("1");
            string num_str = _digits;
            
            if(num_str[0] == '-'){
                sign = -1;
                start = 1;
                size = num_str.size() - 1;
            }else if(num_str[0] == '+'){
                sign = 1;
                start = 1;
                size = num_str.size() - 1;
            }else{
                sign = 1;
                start = 0;
                size = num_str.size();
            }
            
            up = big_N(num_str.substr(start, size));
        }else{
            // Есть знаменатель
            string num_str = _digits.substr(0, slash_pos);
            string den_str = _digits.substr(slash_pos + 1);
            
            // Обрабатываем знак числителя
            if(num_str[0] == '-'){
                sign = -1;
                start = 1;
                size = num_str.size() - 1;
            }else if(num_str[0] == '+'){
                sign = 1;
                start = 1;
                size = num_str.size() - 1;
            }else{
                sign = 1;
                start = 0;
                size = num_str.size();
            }
            
            up = big_N(num_str.substr(start, size));
            down = big_N(den_str);  // знаменатель всегда положительный
        }
    }
};

ostream& operator << (ostream& os, const big_Q& q);

#endif
