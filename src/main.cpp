#include "Module_1/natural.h"
#include "Module_2/integer.h"
#include "Module_3/rational.h"
#include "Module_4/part0.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    ALWAYS_PRINT_DENOMINATOR = 0;
    while (1)
    {
        string str;
        cin >> str;
        cout << big_P(str) << endl;
    }
    
    return 0;
}