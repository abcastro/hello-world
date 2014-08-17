#include <iostream>
#include <vector>
#include <sstream>

// all permutations of a binary number

void pv(std::vector<bool> v) {
    for (int i = 0; i < v.size(); i++)
        std::cout << (v[i] ? 1 : 0);
    std::cout << std::endl;
}

void gv(std::vector<bool> v, int s) {
    if (v.size() == 0)
        return;
    if (v.size() == s) {
        pv(v);
        return;
    }

    gv(v, s+1);
    v[s] = true;
    gv(v, s+1);
}

int main(int argc, char *argv[]) {
    std::vector<bool> v;
    int size;

    std::stringstream(argv[1]) >> size;

    for (int i = 0; i < size; i++)
        v.push_back(false);

    gv(v, 0);
    
    return 0;
}
