#include <iostream>

// binary search

int main(int argc, char *argv[]) {
    char arr[13] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm' };

    char aux = argv[1][0];

    int i = 0;
    int j = 12;

    int m = (i + j) / 2;
    
    int c = 0;
    while (i <= j) {
        if (arr[m] == aux) {
            std::cout << "FOUND: " << m << std::endl;
            break;
        }
        if (arr[m] > aux)
            j = m - 1;
        if (arr[m] < aux)
            i = m + 1;
        m = (i + j) / 2;
        c++;
        if (c > 13) {
            std::cout << i << " " << m << " " << j << std::endl;
            break;
        }
    }

    return 0;
}
