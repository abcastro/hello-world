#include <iostream>
#include <bitset>

#include <math.h>

// float bit manipulation

int main() {
    float a;
    std::bitset<32> x;

    a = 1;
    x = std::bitset<32>(*reinterpret_cast<unsigned long*>(&a));
    std::cout << a << " " << x << std::endl;
    a = ldexpf(a, 1);
    x = std::bitset<32>(*reinterpret_cast<unsigned long*>(&a));
    std::cout << a << " " << x << std::endl;
    a = ldexpf(a, -2);
    x = std::bitset<32>(*reinterpret_cast<unsigned long*>(&a));
    std::cout << a << " " << x << std::endl;

    return 0;
}
