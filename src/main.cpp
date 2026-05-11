#include <iostream>
#include <string>
#include <Module_1/natural.h>
#include <Module_2/integer.h>
#include <Module_3/rational.h>
#include <Module_4/polynomial.h>

using namespace std;

void help(){
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
    
    cout << "\n========== МОДУЛЬ 3: РАЦИОНАЛЬНЫЕ ЧИСЛА ==========" << endl;
    cout << "RED_Q_Q (a)        - сокращение дроби" << endl;
    cout << "INT_Q_B (a)        - проверка на целое: 1=да,0=нет" << endl;
    cout << "TRANS_Z_Q (a)      - Z -> Q" << endl;
    cout << "TRANS_Q_Z (a)      - Q -> Z (если знаменатель 1)" << endl;
    cout << "ADD_QQ_Q (a b)     - сложение" << endl;
    cout << "SUB_QQ_Q (a b)     - вычитание" << endl;
    cout << "MUL_QQ_Q (a b)     - умножение" << endl;
    cout << "DIV_QQ_Q (a b)     - деление" << endl;
    
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
    
    cout << "\n========== УПРАВЛЕНИЕ ==========" << endl;
    cout << "HELP               - показать справку" << endl;
    cout << "EXIT               - выход" << endl;
    
    cout << "\nФОРМАТ ВВОДА:" << endl;
    cout << "  N: 123" << endl;
    cout << "  Z: +123 или -123 или 123" << endl;
    cout << "  Q: 1/2 или -3/4 или 5" << endl;
    cout << "  P: x^2+2x+1 или 5x^5-3x^3+2" << endl;
    cout << endl;
}

int main() {
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
            help();
        }

        // ========== МОДУЛЬ 1: НАТУРАЛЬНЫЕ ЧИСЛА ==========
        else if (cmd == "COM_NN_D") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            cout << (int)COM_NN_D(a, b) << endl;
        }
        else if (cmd == "NZER_N_B") {
            cin >> s1;
            big_N a(s1);
            cout << (int)NZER_N_B(a) << endl;
        }
        else if (cmd == "ADD_1N_N") {
            cin >> s1;
            big_N a(s1);
            cout << ADD_1N_N(a) << endl;
        }
        else if (cmd == "ADD_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            cout << ADD_NN_N(a, b) << endl;
        }
        else if (cmd == "SUB_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            cout << SUB_NN_N(a, b) << endl;
        }
        else if (cmd == "MUL_ND_N") {
            cin >> s1 >> s2;
            big_N a(s1);
            char d = s2[0];
            cout << MUL_ND_N(a, d) << endl;
        }
        else if (cmd == "MUL_Nk_N") {
            cin >> s1 >> s2;
            big_N a(s1);
            unsigned long k = stoul(s2);
            cout << MUL_Nk_N(a, k) << endl;
        }
        else if (cmd == "MUL_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            cout << MUL_NN_N(a, b) << endl;
        }
        else if (cmd == "SUB_NDN_N") {
            cin >> s1 >> s2 >> s3;
            big_N a(s1), b(s2);
            int k = stoi(s3);
            cout << SUB_NDN_N(a, b, k) << endl;
        }
        else if (cmd == "DIV_NN_Dk") {
            cin >> s1 >> s2 >> s3;
            big_N a(s1), b(s2);
            long long k = stoll(s3);
            cout << (int)DIV_NN_Dk(a, b, k) << endl;
        }
        else if (cmd == "DIV_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            cout << DIV_NN_N(a, b) << endl;
        }
        else if (cmd == "MOD_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            cout << MOD_NN_N(a, b) << endl;
        }
        else if (cmd == "GCF_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            cout << GCF_NN_N(a, b) << endl;
        }
        else if (cmd == "LCM_NN_N") {
            cin >> s1 >> s2;
            big_N a(s1), b(s2);
            cout << LCM_NN_N(a, b) << endl;
        }
        
        // ========== МОДУЛЬ 2: ЦЕЛЫЕ ЧИСЛА ==========
        
        else if (cmd == "ABS_Z_Z") {
            cin >> s1;
            big_Z a(s1);
            cout << ABS_Z_Z(a) << endl;
        }
        else if (cmd == "SGN_Z_D") {
            cin >> s1;
            big_Z a(s1);
            cout << (int)SGN_Z_D(a) << endl;
        }
        else if (cmd == "MUL_ZM_Z") {
            cin >> s1;
            big_Z a(s1);
            cout << MUL_ZM_Z(a) << endl;
        }
        else if (cmd == "TRANS_N_Z") {
            cin >> s1;
            big_N a(s1);
            cout << TRANS_N_Z(a) << endl;
        }
        else if (cmd == "TRANS_Z_N") {
            cin >> s1;
            big_Z a(s1);
            cout << TRANS_Z_N(a) << endl;
        }
        else if (cmd == "ADD_ZZ_Z") {
            cin >> s1 >> s2;
            big_Z a(s1), b(s2);
            cout << ADD_ZZ_Z(a, b) << endl;
        }
        else if (cmd == "SUB_ZZ_Z") {
            cin >> s1 >> s2;
            big_Z a(s1), b(s2);
            cout << SUB_ZZ_Z(a, b) << endl;
        }
        else if (cmd == "MUL_ZZ_Z") {
            cin >> s1 >> s2;
            big_Z a(s1), b(s2);
            cout << MUL_ZZ_Z(a, b) << endl;
        }
        else if (cmd == "DIV_ZZ_Z") {
            cin >> s1 >> s2;
            big_Z a(s1), b(s2);
            cout << DIV_ZZ_Z(a, b) << endl;
        }
        else if (cmd == "MOD_ZZ_Z") {
            cin >> s1 >> s2;
            big_Z a(s1), b(s2);
            cout << MOD_ZZ_Z(a, b) << endl;
        }
        
        // ========== МОДУЛЬ 3: РАЦИОНАЛЬНЫЕ ЧИСЛА ==========
        
        else if (cmd == "RED_Q_Q") {
            cin >> s1;
            big_Q a(s1);
            cout << RED_Q_Q(a) << endl;
        }
        else if (cmd == "INT_Q_B") {
            cin >> s1;
            big_Q a(s1);
            cout << (int)INT_Q_B(a) << endl;
        }
        else if (cmd == "TRANS_Z_Q") {
            cin >> s1;
            big_Z a(s1);
            cout << TRANS_Z_Q(a) << endl;
        }
        else if (cmd == "TRANS_Q_Z") {
            cin >> s1;
            big_Q a(s1);
            cout << TRANS_Q_Z(a) << endl;
        }
        else if (cmd == "ADD_QQ_Q") {
            cin >> s1 >> s2;
            big_Q a(s1), b(s2);
            cout << ADD_QQ_Q(a, b) << endl;
        }
        else if (cmd == "SUB_QQ_Q") {
            cin >> s1 >> s2;
            big_Q a(s1), b(s2);
            cout << SUB_QQ_Q(a, b) << endl;
        }
        else if (cmd == "MUL_QQ_Q") {
            cin >> s1 >> s2;
            big_Q a(s1), b(s2);
            cout << MUL_QQ_Q(a, b) << endl;
        }
        else if (cmd == "DIV_QQ_Q") {
            cin >> s1 >> s2;
            big_Q a(s1), b(s2);
            cout << DIV_QQ_Q(a, b) << endl;
        }
        
        // ========== МОДУЛЬ 4: ПОЛИНОМЫ ==========
        
        else if (cmd == "ADD_PP_P") {
            cin >> ws;
            getline(cin, s1);
            getline(cin, s2);
            big_P a(s1), b(s2);
            cout << ADD_PP_P(a, b) << endl;
        }
        else if (cmd == "SUB_PP_P") {
            cin >> ws;
            getline(cin, s1);
            getline(cin, s2);
            big_P a(s1), b(s2);
            cout << SUB_PP_P(a, b) << endl;
        }
        else if (cmd == "MUL_PQ_P") {
            cin >> ws;
            getline(cin, s1);
            cin >> s2;
            big_P a(s1);
            big_Q b(s2);
            cout << MUL_PQ_P(a, b) << endl;
        }
        else if (cmd == "MUL_Pxk_P") {
            cin >> ws;
            getline(cin, s1);
            cin >> s2;
            big_P a(s1);
            big_N k(s2);
            cout << MUL_Pxk_P(a, k) << endl;
        }
        else if (cmd == "LED_P_Q") {
            cin >> ws;
            getline(cin, s1);
            big_P a(s1);
            cout << LED_P_Q(a) << endl;
        }
        else if (cmd == "DEG_P_N") {
            cin >> ws;
            getline(cin, s1);
            big_P a(s1);
            cout << DEG_P_N(a) << endl;
        }
        else if (cmd == "FAC_P_Q") {
            cin >> ws;
            getline(cin, s1);
            big_P a(s1);
            cout << FAC_P_Q(a) << endl;
        }
        else if (cmd == "MUL_PP_P") {
            cin >> ws;
            getline(cin, s1);
            getline(cin, s2);
            big_P a(s1), b(s2);
            cout << MUL_PP_P(a, b) << endl;
        }
        else if (cmd == "DIV_PP_P") {
            cin >> ws;
            getline(cin, s1);
            getline(cin, s2);
            big_P a(s1), b(s2);
            cout << DIV_PP_P(a, b) << endl;
        }
        else if (cmd == "MOD_PP_P") {
            cin >> ws;
            getline(cin, s1);
            getline(cin, s2);
            big_P a(s1), b(s2);
            cout << MOD_PP_P(a, b) << endl;
        }
        else if (cmd == "GCF_PP_P") {
            cin >> ws;
            getline(cin, s1);
            getline(cin, s2);
            big_P a(s1), b(s2);
            cout << GCF_PP_P(a, b) << endl;
        }
        else if (cmd == "DER_P_P") {
            cin >> ws;
            getline(cin, s1);
            big_P a(s1);
            cout << DER_P_P(a) << endl;
        }
        else if (cmd == "NMR_P_P") {
            cin >> ws;
            getline(cin, s1);
            big_P a(s1);
            cout << NMR_P_P(a) << endl;
        }
        else {
            cout << "Unknown command: " << cmd << endl;
        }
    }
    
    return 0;
}