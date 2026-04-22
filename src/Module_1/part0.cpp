#include <iostream>
#include <vector>

using namespace std;

class Big_N{
    public:

    vector<char> digits; /// "123" -> [3] [2] [1]
    friend ostream& operator<<(ostream& os, const Big_N& obj);

    Big_N(vector<char> _digits){
        digits.resize(_digits.size());
        for(int i = 0; i < digits.size(); i++){
            digits[i] = _digits[i];
        }
    }

    Big_N(string _digits){
        unsigned long size = _digits.size();
        digits.resize(size);
        for (int i=0; i < size; i++) {
            digits[size-1-i] = _digits[i] - '0';
        }
    }
};
ostream& operator << (ostream& os, const Big_N& n) {
    unsigned long size = n.digits.size();
    for (int i = 0; i < size; i++) {
        os << (int) n.digits[size-1-i];
    }
    return os;
}
int main() {
    vector<char> ds = {1, 2, 3};
    Big_N bn = Big_N("12322345678998653456789");
    cout << bn << endl;

}
