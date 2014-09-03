#include <iostream>

int isEndian() {
    union {
        int num;
        char c;
    } test;

    test.num = 1;
    return test.c;
}

int main() {
    std::cout << isEndian() << std::endl;
    return 0;
}
