#pragma once
#include <cstddef>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class big_N{
    public:

    vector<char> digits; /// "123" -> [3] [2] [1]
    friend ostream& operator<<(ostream& os, const big_N& obj);

    big_N(): digits{} {}

    big_N(const vector<char> &_digits){
        digits.resize(_digits.size());
        for(int i = 0; i < digits.size(); i++){
            digits[i] = _digits[i];
        }
    }

    big_N(const string &_digits){
        unsigned long size = _digits.size();
        digits.resize(size);
        for (int i=0; i < size; i++) {
            digits[size-1-i] = _digits[i] - '0';
        }
    }

    static big_N from_reverse_vec(const vector<char>& _digits) {
        big_N res;
        size_t size = _digits.size();
        res.digits.resize(size);
        for (size_t i = 0; i < size; ++i) {
            res.digits[size-1-i] = _digits[i];
        }
        return res;
    }

    // если part3.h  импортировать циклическая зависимость образует так что так 
    bool operator==(const big_N &other) {
        if (digits.size() != other.digits.size())
            return false;

        bool equal = true;
        for (size_t i = 0; i < digits.size(); ++i) {
            if (digits[i] != other.digits[i]) {
                equal = false;
                break;
            }
        }
        return equal;
    }
};
ostream& operator << (ostream& os, const big_N& n);
