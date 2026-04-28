#include "Module_2/integer.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int choice;
    string s1, s2;
    
    cout << "\n1-ABS 2-SGN 3-MUL_ZM 4-N->Z 5-Z->N 6-ADD 7-SUB 8-MUL 9-DIV 10-MOD 0-EXIT: ";
    while (1) {
        cin >> choice;
        
        if (choice == 0) break;
        
        switch (choice) {
            case 1:
                cin >> s1;
                cout << ABS_Z_Z(big_Z(s1)) << endl;
                break;
            case 2:
                cin >> s1;
                cout << (int)SGN_Z_D(big_Z(s1)) << endl;
                break;
            case 3:
                cin >> s1;
                cout << MUL_ZM_Z(big_Z(s1)) << endl;
                break;
            case 4:
                cin >> s1;
                cout << TRANS_N_Z(big_N(s1)) << endl;
                break;
            case 5:
                cin >> s1;
                cout << TRANS_Z_N(big_Z(s1)) << endl;
                break;
            case 6:
                cin >> s1 >> s2;
                cout << ADD_ZZ_Z(big_Z(s1), big_Z(s2)) << endl;
                break;
            case 7:
                cin >> s1 >> s2;
                cout << SUB_ZZ_Z(big_Z(s1), big_Z(s2)) << endl;
                break;
            case 8:
                cin >> s1 >> s2;
                cout << MUL_ZZ_Z(big_Z(s1), big_Z(s2)) << endl;
                break;
            case 9:
                cin >> s1 >> s2;
                cout << DIV_ZZ_Z(big_Z(s1), big_Z(s2)) << endl;
                break;
            case 10:
                cin >> s1 >> s2;
                cout << MOD_ZZ_Z(big_Z(s1), big_Z(s2)) << endl;
                break;
        }
    }
    return 0;
}