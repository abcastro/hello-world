#include <iostream>
#include <sstream>

// rotaded binary search

void print_arr(char *a, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
}

int main(int argc, char *argv[]) {
    char arr[13] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm' };
    int n = 13;
    int d;
    char tmp;
    char aux;

    std::stringstream(argv[1]) >> d;

    std::cout << "rodar " << d << std::endl;

    aux = arr[0];
    for (int i = 0; i < n; i++) {
        tmp = arr[(i * d + d) % n];
        arr[(i * d + d) % n] = aux;
        aux = tmp;

        // print_arr(arr, n);
        // std::cout << "(" << aux << ")" << std::endl;
    }

    print_arr(arr, n);
    std::cout << std::endl;

    int i = (d % n);
    int j = (n + d - 1) % n;

    int m = ((i > j) ? (((i + j + n) / 2) % n) : ((i + j) / 2));

    aux = argv[2][0];

    bool isDone = false;
    int c = 0;
    while (not isDone) {
        std::cout << i << " " << m << " " << j << std::endl;
        if (arr[m] == aux) {
            std::cout << "FOUND: " << m << std::endl;
            isDone = true;
        } else if (m == i && m == j) {
            std::cout << "NOT found!" << std::endl;
            isDone = true;
        }
        if (arr[m] > aux) {
            j = m - 1;
        }
        if (arr[m] < aux) {
            i = m + 1;
        }

        m = ((i > j) ? (((i + j + n) / 2) % n) : ((i + j) / 2));
    }

    return 0;
}
