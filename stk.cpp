#include <iostream>

#include "stack.h"

int main() {
    mystack<int> ms;

    ms.push(1);
    ms.push(2);

    try {
        std::cout << ms.size() << std::endl;
        std::cout << ms.pop() << std::endl;
        std::cout << ms.size() << std::endl;
        std::cout << ms.pop() << std::endl;
        std::cout << ms.size() << std::endl;
        std::cout << ms.pop() << std::endl;
    } catch (char const *e) {
        std::cout << e << std::endl;
    }

    return 0;
}
