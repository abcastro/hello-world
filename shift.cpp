#include <iostream>
#include <bitset>

int main() {
    unsigned int a;
    std::bitset<32> x;

    a = -1;
    x = std::bitset<32>(a);
    std::cout << a << " " << x << std::endl;
    a <<= 1;
    x = std::bitset<32>(a);
    std::cout << a << " " << x << std::endl;
    a >>= 1;
    x = std::bitset<32>(a);
    std::cout << a << " " << x << std::endl;

    return 0;
}
