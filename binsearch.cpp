#include <iostream>
#include <sstream>

void binsearch(int *arr, int i, int j, int v) {
    int m;
    int a = i;
    int b = j;
    int res = -1;

    while (b >= a) {
        m = (a + b) / 2;
        if (arr[m] < v) {
            std::cout << "<" << std::endl;
            a = m + 1;
        } else if (arr[m] > v) {
            std::cout << ">" << std::endl;
            b = m - 1;
        } else {
            std::cout << "=" << std::endl;
            res = m;
            break;
        }
    }

    std::cout << "result = " << res << std::endl;
}

int main(int argc, char *argv[]) {
    int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int val;

    std::stringstream(argv[1]) >> val;

    binsearch(arr, 0, 8, val);

    return 0;
}
