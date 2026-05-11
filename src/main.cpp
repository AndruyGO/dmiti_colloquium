#include <iostream>
#include <string>
#include "Module_1/natural.h"
#include "Module_2/integer.h"
#include "Module_3/rational.h"
#include "Module_4/polynomial.h"

using namespace std;



void help1(){
    cout << "\n========== МОДУЛЬ 1: НАТУРАЛЬНЫЕ ЧИСЛА ==========" << endl;
    cout << "COM_NN_D (a b)     - сравнение: 0=равны,1=меньше,2=больше" << endl;
    cout << "NZER_N_B (a)       - проверка на ноль: 0=ноль,1=не ноль" << endl;
    cout << "ADD_1N_N (a)       - добавление 1" << endl;
    cout << "ADD_NN_N (a b)     - сложение" << endl;
    cout << "SUB_NN_N (a b)     - вычитание (a>=b)" << endl;
    cout << "MUL_ND_N (a d)     - умножение на цифру d" << endl;
    cout << "MUL_Nk_N (a k)     - умножение на 10^k" << endl;
    cout << "MUL_NN_N (a b)     - умножение" << endl;
    cout << "SUB_NDN_N (a b k)  - вычитание b*k из a" << endl;
    cout << "DIV_NN_Dk (a b k)  - первая цифра деления a/(b*10^k)" << endl;
    cout << "DIV_NN_N (a b)     - деление (частное)" << endl;
    cout << "MOD_NN_N (a b)     - деление (остаток)" << endl;
    cout << "GCF_NN_N (a b)     - НОД" << endl;
    cout << "LCM_NN_N (a b)     - НОК" << endl;
}

void help2(){
    cout << "\n========== МОДУЛЬ 2: ЦЕЛЫЕ ЧИСЛА ==========" << endl;
    cout << "ABS_Z_Z (a)        - абсолютная величина" << endl;
    cout << "SGN_Z_D (a)        - знак: -1,0,1" << endl;
    cout << "MUL_ZM_Z (a)       - умножение на -1" << endl;
    cout << "TRANS_N_Z (a)      - N -> Z" << endl;
    cout << "TRANS_Z_N (a)      - Z -> N (a>=0)" << endl;
    cout << "ADD_ZZ_Z (a b)     - сложение" << endl;
    cout << "SUB_ZZ_Z (a b)     - вычитание" << endl;
    cout << "MUL_ZZ_Z (a b)     - умножение" << endl;
    cout << "DIV_ZZ_Z (a b)     - деление (частное)" << endl;
    cout << "MOD_ZZ_Z (a b)     - деление (остаток, неотрицательный)" << endl;
}

void help3(){
    cout << "\n========== МОДУЛЬ 3: РАЦИОНАЛЬНЫЕ ЧИСЛА ==========" << endl;
    cout << "RED_Q_Q (a)        - сокращение дроби" << endl;
    cout << "INT_Q_B (a)        - проверка на целое: 1=да,0=нет" << endl;
    cout << "TRANS_Z_Q (a)      - Z -> Q" << endl;
    cout << "TRANS_Q_Z (a)      - Q -> Z (если знаменатель 1)" << endl;
    cout << "ADD_QQ_Q (a b)     - сложение" << endl;
    cout << "SUB_QQ_Q (a b)     - вычитание" << endl;
    cout << "MUL_QQ_Q (a b)     - умножение" << endl;
    cout << "DIV_QQ_Q (a b)     - деление" << endl;
}

void help4(){
    cout << "\n========== МОДУЛЬ 4: ПОЛИНОМЫ ==========" << endl;
    cout << "ADD_PP_P (a b)     - сложение" << endl;
    cout << "SUB_PP_P (a b)     - вычитание" << endl;
    cout << "MUL_PQ_P (a q)     - умножение на рациональное число" << endl;
    cout << "MUL_Pxk_P (a k)    - умножение на x^k" << endl;
    cout << "LED_P_Q (a)        - старший коэффициент" << endl;
    cout << "DEG_P_N (a)        - степень многочлена" << endl;
    cout << "FAC_P_Q (a)        - вынесение НОК/НОД коэффициентов" << endl;
    cout << "MUL_PP_P (a b)     - умножение" << endl;
    cout << "DIV_PP_P (a b)     - деление (частное)" << endl;
    cout << "MOD_PP_P (a b)     - деление (остаток)" << endl;
    cout << "GCF_PP_P (a b)     - НОД" << endl;
    cout << "DER_P_P (a)        - производная" << endl;
    cout << "NMR_P_P (a)        - кратные корни в простые" << endl;
}

void basic_help(){
    cout << "\n========== Длинная арифметика ==========" << endl;
    cout << "EXIT               - выход" << endl;
    cout << "HELP 1             - Функции модуля 1 - Натуральные числа" << endl;
    cout << "HELP 2             - Функции модуля 2 - Целые числа" << endl;
    cout << "HELP 3             - Функции модуля 3 - Дроби" << endl;
    cout << "HELP 4             - Функции модуля 4 - Полиномы" << endl;
    cout << "HELP 0             - Дополнительные функции" << endl;
    cout << "HELP 5             - Вывод всех функций модулей" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Введите функцию, а затем введите аргументы" << endl;
    cout << "Пример:" << endl;
    cout << "> SUB_NN_N 123 45 \n" << endl;
}

void help0(){ // в раззработке
        cout << "\n========== Дополнительные функции ==========" << endl;
    cout << "EXIT               - выход" << endl;
    cout << "PRINT_SIGN             - Функции модуля 1 - Натуральные числа" << endl;
    cout << "HELP 2             - Функции модуля 2 - Целые числа" << endl;
    cout << "HELP 3             - Функции модуля 3 - Дроби" << endl;
    cout << "HELP 4             - Функции модуля 4 - Полиномы" << endl;
    cout << "HELP 0             - Дополнительные функции" << endl;
    cout << "HELP 5             - Вывод всех функций модулей" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Введите функцию, а затем введите аргументы" << endl;
    cout << "Пример:" << endl;
    cout << "> SUB_NN_N 123 45 \n" << endl;
}


void help(){
    help1();
    help2();
    help3();
    help4();   
}

bool is_empty_N(const big_N& n) {
    return n.digits.empty();
}

bool is_zero_N(const big_N& n) {
    return n.digits.size() == 1 && n.digits[0] == 0;
}

bool is_empty_Z(const big_Z& z) {
    return z.digits.empty();
}

bool is_empty_P(const big_P& p) {
    return p.monomials.empty();
}

int main() {
    ALWAYS_PRINT_DENOMINATOR = 0;
    ALWAYS_PRINT_SIGN = 0;
    ALWAYS_REDUCE = 1;
    string cmd, s1, s2, s3, s4;
    help();
    while (true) {
        cmd = ""; s1 = ""; s2 = ""; s3 = ""; s4 = "";
        
        cout << "> ";
        cin >> cmd;
        
        if (cmd == "EXIT") break;
        cin.ignore();  // <- игнорируем символ новой строки после команды
        cin >> ws;     // <- пропускаем пробелы
        
        if(cmd == "HELP"){
            cin >> s1;

            help();
        }

        // ========== МОДУЛЬ 1: НАТУРАЛЬНЫЕ ЧИСЛА ==========
        else if (cmd == "COM_NN_D") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            if (is_empty_N(a) || is_empty_N(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << (int)COM_NN_D(a, b) << endl;
        }
        else if (cmd == "NZER_N_B") {
            cin >> s1;
            big_N a(s1);
            if (is_empty_N(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << (int)NZER_N_B(a) << endl;
        }
        else if (cmd == "ADD_1N_N") {
            cin >> s1;
            big_N a(s1);
            if (is_empty_N(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_N res = ADD_1N_N(a);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "ADD_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            if (is_empty_N(a) || is_empty_N(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_N res = ADD_NN_N(a, b);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "SUB_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            if (is_empty_N(a) || is_empty_N(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_N res = SUB_NN_N(a, b);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MUL_ND_N") {
            cin >> s1 >> s2;
            big_N a(s1);
            if (is_empty_N(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            char d = s2[0];
            big_N res = MUL_ND_N(a, d);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MUL_Nk_N") {
            cin >> s1 >> s2;
            big_N a(s1);
            if (is_empty_N(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            unsigned long k = stoul(s2);
            big_N res = MUL_Nk_N(a, k);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MUL_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            if (is_empty_N(a) || is_empty_N(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_N res = MUL_NN_N(a, b);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "SUB_NDN_N") {
            cin >> s1 >> s2 >> s3;
            big_N a(s1), b(s2);
            if (is_empty_N(a) || is_empty_N(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            int k = stoi(s3);
            big_N res = SUB_NDN_N(a, b, k);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "DIV_NN_Dk") {
            cin >> s1 >> s2 >> s3;
            big_N a(s1), b(s2);
            if (is_empty_N(a) || is_empty_N(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            long long k = stoll(s3);
            cout << (int)DIV_NN_Dk(a, b, k) << endl;
        }
        else if (cmd == "DIV_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            if (is_empty_N(a) || is_empty_N(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_N res = DIV_NN_N(a, b);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MOD_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            if (is_empty_N(a) || is_empty_N(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_N res = MOD_NN_N(a, b);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "GCF_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            if (is_empty_N(a) || is_empty_N(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_N res = GCF_NN_N(a, b);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "LCM_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            if (is_empty_N(a) || is_empty_N(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_N res = LCM_NN_N(a, b);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        
        // ========== МОДУЛЬ 2: ЦЕЛЫЕ ЧИСЛА ==========
        
        else if (cmd == "ABS_Z_Z") {
            cin >> s1;
            big_Z a(s1);
            if (is_empty_Z(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Z res = ABS_Z_Z(a);
            if (is_empty_Z(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "SGN_Z_D") {
            cin >> s1;
            big_Z a(s1);
            if (is_empty_Z(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << (int)SGN_Z_D(a) << endl;
        }
        else if (cmd == "MUL_ZM_Z") {
            cin >> s1;
            big_Z a(s1);
            if (is_empty_Z(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Z res = MUL_ZM_Z(a);
            if (is_empty_Z(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "TRANS_N_Z") {
            cin >> s1;
            big_N a(s1);
            if (is_empty_N(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Z res = TRANS_N_Z(a);
            if (is_empty_Z(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "TRANS_Z_N") {
            cin >> s1;
            big_Z a(s1);
            if (is_empty_Z(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_N res = TRANS_Z_N(a);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "ADD_ZZ_Z") {
            cin >> s1 >> s2;
            big_Z a(s1), b(s2);
            if (is_empty_Z(a) || is_empty_Z(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Z res = ADD_ZZ_Z(a, b);
            if (is_empty_Z(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "SUB_ZZ_Z") {
            cin >> s1 >> s2;
            big_Z a(s1), b(s2);
            if (is_empty_Z(a) || is_empty_Z(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Z res = SUB_ZZ_Z(a, b);
            if (is_empty_Z(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MUL_ZZ_Z") {
            cin >> s1 >> s2;
            big_Z a(s1), b(s2);
            if (is_empty_Z(a) || is_empty_Z(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Z res = MUL_ZZ_Z(a, b);
            if (is_empty_Z(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "DIV_ZZ_Z") {
            cin >> s1 >> s2;
            big_Z a(s1), b(s2);
            if (is_empty_Z(a) || is_empty_Z(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Z res = DIV_ZZ_Z(a, b);
            if (is_empty_Z(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MOD_ZZ_Z") {
            cin >> s1 >> s2;
            big_Z a(s1), b(s2);
            if (is_empty_Z(a) || is_empty_Z(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Z res = MOD_ZZ_Z(a, b);
            if (is_empty_Z(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        
        // ========== МОДУЛЬ 3: РАЦИОНАЛЬНЫЕ ЧИСЛА ==========
        
        else if (cmd == "RED_Q_Q") {
            cin >> s1;
            big_Q a(s1);
            big_Q res = RED_Q_Q(a);
            if (res.up.digits.empty() || res.down.digits.empty()) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "INT_Q_B") {
            cin >> s1;
            big_Q a(s1);
            cout << (int)INT_Q_B(a) << endl;
        }
        else if (cmd == "TRANS_Z_Q") {
            cin >> s1;
            big_Z a(s1);
            if (is_empty_Z(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Q res = TRANS_Z_Q(a);
            if (res.up.digits.empty() || res.down.digits.empty()) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "TRANS_Q_Z") {
            cin >> s1;
            big_Q a(s1);
            big_Z res = TRANS_Q_Z(a);
            if (is_empty_Z(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "ADD_QQ_Q") {
            cin >> s1 >> s2;
            big_Q a(s1), b(s2);
            big_Q res = ADD_QQ_Q(a, b);
            if (res.up.digits.empty() || res.down.digits.empty()) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "SUB_QQ_Q") {
            cin >> s1 >> s2;
            big_Q a(s1), b(s2);
            big_Q res = SUB_QQ_Q(a, b);
            if (res.up.digits.empty() || res.down.digits.empty()) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MUL_QQ_Q") {
            cin >> s1 >> s2;
            big_Q a(s1), b(s2);
            big_Q res = MUL_QQ_Q(a, b);
            if (res.up.digits.empty() || res.down.digits.empty()) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "DIV_QQ_Q") {
            cin >> s1 >> s2;
            big_Q a(s1), b(s2);
            big_Q res = DIV_QQ_Q(a, b);
            if (res.up.digits.empty() || res.down.digits.empty()) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        
        // ========== МОДУЛЬ 4: ПОЛИНОМЫ ==========
        
        else if (cmd == "ADD_PP_P") {
            cin >> s1 >> s2;
            big_P a(s1), b(s2);
            if (is_empty_P(a) || is_empty_P(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_P res = ADD_PP_P(a, b);
            if (is_empty_P(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "SUB_PP_P") {
            cin >> s1 >> s2;
            big_P a(s1), b(s2);
            if (is_empty_P(a) || is_empty_P(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_P res = SUB_PP_P(a, b);
            if (is_empty_P(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MUL_PQ_P") {
            cin >> s1 >> s2;
            big_P a(s1);
            big_Q b(s2);
            if (is_empty_P(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_P res = MUL_PQ_P(a, b);
            if (is_empty_P(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MUL_Pxk_P") {
            cin >> s1 >> s2;
            big_P a(s1);
            big_N k(s2);
            if (is_empty_P(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_P res = MUL_Pxk_P(a, k);
            if (is_empty_P(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "LED_P_Q") {
            cin >> s1;
            big_P a(s1);
            if (is_empty_P(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Q res = LED_P_Q(a);
            if (res.up.digits.empty() || res.down.digits.empty()) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "DEG_P_N") {
            cin >> s1;
            big_P a(s1);
            if (is_empty_P(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_N res = DEG_P_N(a);
            if (is_empty_N(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "FAC_P_Q") {
            cin >> s1;
            big_P a(s1);
            if (is_empty_P(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_Q res = FAC_P_Q(a);
            if (res.up.digits.empty() || res.down.digits.empty()) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MUL_PP_P") {
            cin >> s1 >> s2;
            big_P a(s1), b(s2);
            if (is_empty_P(a) || is_empty_P(b)) {
                cout << "Некорректные Аргументы\n";
                cout << a << " " << b << "\n";
                continue;
            }
            big_P res = MUL_PP_P(a, b);
            if (is_empty_P(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "DIV_PP_P") {
            cin >> s1 >> s2;
            big_P a(s1), b(s2);
            if (is_empty_P(a) || is_empty_P(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_P res = DIV_PP_P(a, b);
            if (is_empty_P(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "MOD_PP_P") {
            cin >> s1 >> s2;
            big_P a(s1), b(s2);
            if (is_empty_P(a) || is_empty_P(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_P res = MOD_PP_P(a, b);
            if (is_empty_P(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "GCF_PP_P") {
            cin >> s1 >> s2;
            big_P a(s1), b(s2);
            if (is_empty_P(a) || is_empty_P(b)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_P res = GCF_PP_P(a, b);
            if (is_empty_P(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "DER_P_P") {
            cin >> s1;
            big_P a(s1);
            if (is_empty_P(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_P res = DER_P_P(a);
            if (is_empty_P(res)) {
                cout << "0\n";
                continue;
            }
            cout << res << endl;
        }
        else if (cmd == "NMR_P_P") {
            cin >> s1;
            big_P a(s1);
            if (is_empty_P(a)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            big_P res = NMR_P_P(a);
            if (is_empty_P(res)) {
                cout << "Некорректные Аргументы\n";
                continue;
            }
            cout << res << endl;
        }
        else {
            cout << "Unknown command: " << cmd << endl;
        }
    }
    
    return 0;
}