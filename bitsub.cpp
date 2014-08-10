#include <iostream>
#include <bitset>

// bit manipulation: put n2 as 'substring' of n1 bitween the positions i and j

int main() {
    //std::string n1 = "10000000000";
    //std::string n2 = "10101";
    std::string n1 = "10101010101";
    std::string n2 = "01010";
    int i = 2;
    int j = 6;
    std::bitset<16> b1(n1);
    std::bitset<16> b2(n2);
    std::bitset<16> m;
    
    for (int a = i; a <= j; a++)
        m.set(a);
    m.flip();

    b2 <<= i;
    b1 &= m;
    b1 |= b2;

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << m << std::endl;
}
