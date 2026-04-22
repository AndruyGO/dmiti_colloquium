#include <iostream>
#include <vector>

class Big_N {
public:
    std::vector<char> digits;
    Big_N(const std::vector<char>& _digits);
    Big_N(const std::string& _digits);
    friend std::ostream& operator<<(std::ostream& os, const Big_N& obj);
};

std::ostream& operator<<(std::ostream& os, const Big_N& obj);
