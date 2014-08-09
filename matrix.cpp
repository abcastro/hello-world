#include <iostream>
#include <queue>

// find a char path in a char matrix

bool tryPath(char m[10][10], int x, int y, int i, int j, char *a, int n) {
    int k = i;
    int l = j;
    int p = 1; // a[0] already equal
    std::queue<std::pair<int, int> > path;

    path.push(std::make_pair<int, int>(i, j));

    std::cout << k << "x" << l << " ";
    while (p < n) {
        if (k < x and m[k+1][l] == a[p]) {
            k++;
            p++;
            path.push(std::make_pair<int, int>(k, l));
            std::cout << k << "x" << l << " ";
        } else if (l < y and m[k][l+1] == a[p]) {
            l++;
            p++;
            path.push(std::make_pair<int, int>(k, l));
            std::cout << k << "x" << l << " ";
        } else if (k > 0 and m[k-1][l] == a[p]) {
            k--;
            p++;
            path.push(std::make_pair<int, int>(k, l));
            std::cout << k << "x" << l << " ";
        } else if (l > 0 and m[k][l-1] == a[p]) {
            l--;
            p++;
            path.push(std::make_pair<int, int>(k, l));
            std::cout << k << "x" << l << " ";
        } else {
            std::cout << "break";
            break;
        }
    }
    std::cout << std::endl;

    return false;
}

void hasPath(char m[10][10], int x, int y, char *a, int n) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (m[i][j] == a[0]) {
                if (tryPath(m, x, y, i, j, a, n)) {
                    break;
                }
            }
        }
    }
}

int main() {
    char mat[10][10] = {
        { 'x', 'w', 'b', 'c', 'r', 'a', 'k', 'f', 'z', 'u' },
        { 'h', 'n', 'i', 'w', 'u', 'f', 'k', 'e', 'j', 'e' },
        { 'h', 'h', 'r', 'n', 'p', 'g', 'o', 'y', 'h', 'o' },
        { 's', 'j', 'a', 'k', 'b', 'm', 'b', 'n', 'k', 'j' },
        { 'o', 'q', 'r', 'e', 'g', 'j', 'w', 'p', 'k', 't' },
        { 'i', 't', 'm', 'f', 'n', 'x', 'n', 'y', 'f', 'a' },
        { 'r', 'a', 'c', 'q', 's', 'v', 'b', 'f', 'l', 'a' },
        { 'g', 'm', 'p', 'r', 'b', 'i', 'q', 'r', 'e', 'k' },
        { 'c', 's', 'l', 'm', 'l', 'i', 'q', 'x', 'r', 'c' },
        { 'u', 'r', 'b', 'k', 'j', 'i', 'z', 's', 'w', 'c' }
    };

    char arr[5] = { 'g', 'n', 'x', 'n', 'w' };

    hasPath(mat, 10, 10, arr, 5);

    //for (int i = 0; i < 10; i++) {
    //    for (int j = 0; j < 10; j++) {
    //        std::cout << mat[i][j] << " ";
    //    }
    //    std::cout << std::endl;
    //}

    return 0;
}
