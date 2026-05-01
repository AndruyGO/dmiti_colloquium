#include "Module_1/natural.h"
#include "Module_2/integer.h"
#include "Module_3/rational.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int choice;
    string s1, s2;
    
    while (1) {
        cout << "\n1-RED 2-INT 3-Z->Q 4-Q->Z 5-ADD 6-SUB 7-MUL 8-DIV 0-EXIT: ";
        cin >> choice;
        
        if (choice == 0) break;
        
        switch (choice) {
            case 1: // RED_Q_Q - сокращение
                cin >> s1;
                cout << RED_Q_Q(big_Q(s1)) << endl;
                break;
            case 2: // INT_Q_B - проверка на целое (1 - да, 0 - нет)
                cin >> s1;
                cout << (int)INT_Q_B(big_Q(s1)) << endl;
                break;
            case 3: // TRANS_Z_Q - целое -> дробь
                cin >> s1;
                cout << TRANS_Z_Q(big_Z(s1)) << endl;
                break;
            case 4: // TRANS_Q_Z - дробь -> целое (если знаменатель 1)
                cin >> s1;
                cout << TRANS_Q_Z(big_Q(s1)) << endl;
                break;
            case 5: // ADD_QQ_Q - сложение
                cin >> s1 >> s2;
                cout << ADD_QQ_Q(big_Q(s1), big_Q(s2)) << endl;
                break;
            case 6: // SUB_QQ_Q - вычитание
                cin >> s1 >> s2;
                cout << SUB_QQ_Q(big_Q(s1), big_Q(s2)).up << " " << SUB_QQ_Q(big_Q(s1), big_Q(s2)).down << endl;
                break;
            case 7: // MUL_QQ_Q - умножение
                cin >> s1 >> s2;
                cout << MUL_QQ_Q(big_Q(s1), big_Q(s2)) << endl;
                break;
            case 8: // DIV_QQ_Q - деление
                cin >> s1 >> s2;
                cout << DIV_QQ_Q(big_Q(s1), big_Q(s2)) << endl;
                break;
        }
    }
    return 0;
}