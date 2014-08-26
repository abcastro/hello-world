#include <iostream>

// find the only non duplicate number

int main() {
    int arr[] = { 0, 44, 42, 18, 42, 24, 44, 48, 38, 38, 43, 1, 48, 33, 32, 4, 9, 46, 33, 46, 43, 10, 19, 4, 32, 9, 5, 5, 19, 1, 40, 0, 18, 40, 24 };

    int num = 0;

    for (int i = 0; i < 35; i++)
        num ^= arr[i];

    std::cout << num << std::endl;

    return 0;
}
