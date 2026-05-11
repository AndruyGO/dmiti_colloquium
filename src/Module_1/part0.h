/*
    Разработчик: Лысенко Артём 5385
*/



#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#ifndef _NATURAL_PART0
#define _NATURAL_PART0

using namespace std;

class big_N{
    public:

    vector<char> digits; /// "123" -> [3] [2] [1]
    friend ostream& operator<<(ostream& os, const big_N& obj);
	big_N(){}
    big_N(const vector<char> &_digits){
        digits.resize(_digits.size());
        for(int i = 0; i < digits.size(); i++){
            digits[i] = _digits[i];
        }
    }

    big_N(const string &_digits){
        regex pattern("^[1-9][0-9]*$|^0$");
        if (!regex_match(_digits, pattern)) {
            cerr << "DEBUG: Invalid number format: '" << _digits << "' (length: " << _digits.size() << ")" << endl;
            return;
        }
        unsigned long size = _digits.size();
        digits.resize(size);
        for (int i=0; i < size; i++) {
            digits[size-1-i] = _digits[i] - '0';
        }
    }
};
ostream& operator << (ostream& os, const big_N& n);

#endif

