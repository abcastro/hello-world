#include <iostream>
#include <vector>

// all permutations of a vector of char

void print_vector(std::vector<char> v) {
    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void swap(char &a, char &b) {
    char tmp;

    tmp = a;
    a = b;
    b = tmp;
}

void gen_perm(std::vector<char> v, int l) {
    if (v.size() == 0)
        return;
    if (v.size() < l)
        return;

    gen_perm(v, l+1);

    for (int i = l + 1; i < v.size(); i++) {
        swap(v[l], v[i]);
        print_vector(v);
        gen_perm(v, l+1);
        swap(v[i], v[l]);
    }
}

int main(int argc, char *argv[]) {
    std::vector<char> v;

    for (int i = 1; i < argc; i++) {
        v.push_back(argv[i][0]);
    }

    print_vector(v);
    gen_perm(v, 0);

    return 0;
}
