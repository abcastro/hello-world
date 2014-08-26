#include <iostream>
#include <sstream>

// given a number, check if its bit representation is palindrome

int main(int argc, char *argv[]) {
    int num1;
    int num2;

    std::stringstream(argv[1]) >> num1;

    num2 = num1;

    std::bitset<32> bnum(num1);
    std::cout << bnum.to_string() << std::endl;

    for (int i = 0; i < sizeof(int) * 4 ; i++) {
        if (((num1 & 0x80000000) >> 31) == (num2 & 0x1)) {
            num1 <<= 1;
            num2 >>= 1;
        } else {
            std::cout << "non palindrome " << i << std::endl;
            break;
        }
    }

    return 0;
}
