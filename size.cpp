#include <iostream>

// checking some sizes

int main() {
    std::cout << "char " << sizeof(char) << std::endl;
    std::cout << "short " << sizeof(short) << std::endl;
    std::cout << "int " << sizeof(int) << std::endl;
    std::cout << "long " << sizeof(long) << std::endl;
    std::cout << "float " << sizeof(float) << std::endl;
    std::cout << "double " << sizeof(double) << std::endl;
    std::cout << "int * " << sizeof(int *) << std::endl;
    return 0;
}
