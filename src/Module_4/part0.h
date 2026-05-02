#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cmath>
#include <sstream>
#include <regex>
#include <algorithm>
#include <map>

#include "../Module_1/natural.h"
#include "../Module_2/integer.h"
#include "../Module_3/rational.h"

using namespace std;

// ... предыдущий код big_Z, big_Q ...

struct monomial {
    big_N degree;
    big_Q val;
    
    monomial() {}
    monomial(const big_N& d, const big_Q& v) : degree(d), val(v) {}
    const bool operator < (const monomial &other) const {
        signed char a = COM_NN_D(degree, other.degree);
        if(a == 1) return 1;
        return 0;
    }
};

class big_P {
public:
    vector<monomial> monomials;
    
    friend ostream& operator<<(ostream& os, const big_P& p);
    
    big_P() {}
    big_P(const vector<monomial> &_m){
        monomials = _m;
    }
    big_P(const string &str) {
        // Убираем пробелы
        string s = str;
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
        
        // Добавляем + в начало, если первый член без знака
        if (s[0] != '+' && s[0] != '-') {
            s = "+" + s;
        }
        
        // Разбиваем на члены
        vector<string> terms;
        int start = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '+' || s[i] == '-') {
                terms.push_back(s.substr(start, i - start));
                start = i;
            }
        }
        terms.push_back(s.substr(start));
        
        // Парсим каждый член
        for (const string& term : terms) {
            monomial m = parse_term(term);
            if (m.val.up.digits.size() == 1 && m.val.up.digits[0] == 0) continue;
            monomials.push_back(m);
        }
        
        // Сортируем по степени (убывание)
        sort(monomials.begin(), monomials.end());
        combine_monoms();
    }

    void combine_monoms() {
        // Сортируем по степени (убывание)
        vector<monomial> combined;
        
        for (const auto& m : monomials) {
            if (combined.empty() || !(COM_NN_D(combined.back().degree, m.degree) == 0)) {
                combined.push_back(m);
            } else {
                // Складываем коэффициенты
                big_Q sum = ADD_QQ_Q(combined.back().val, m.val);
                combined.back().val = sum;
                
                // Если сумма стала нулём, удаляем моном
                if (sum.up.digits.size() == 1 && sum.up.digits[0] == 0) {
                    combined.pop_back();
                }
            }
        }
        
        monomials = combined;
    }
private:
    monomial parse_term(const string& term) {
        // term = "+5x^5" или "-3x^3" или "+2" или "-x" или "+x^2"
        char sign = term[0];
        string rest = term.substr(1);
        
        size_t x_pos = rest.find('x');
        
        big_Q coeff;
        big_N degree("0");
        
        if (x_pos == string::npos) {
            // Свободный член
            string coeff_str = rest;
            if (coeff_str.empty()) coeff_str = "1";
            coeff = big_Q(sign + coeff_str);
            degree = big_N("0");
        } else {
            // Есть x
            string coeff_str = rest.substr(0, x_pos);
            if (coeff_str.empty()) coeff_str = "1";
            coeff = big_Q(sign + coeff_str);
            
            // Проверяем степень
            if (x_pos + 1 < rest.length() && rest[x_pos + 1] == '^') {
                string degree_str = rest.substr(x_pos + 2);
                degree = big_N(degree_str);
            } else {
                degree = big_N("1");
            }
        }

        return monomial(degree, coeff);
    }
};

ostream& operator<<(ostream& os, const big_P& p);