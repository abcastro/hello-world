#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
#include <iomanip>

// binary heap tree

void swap(int &a, int &b) {
    int t;
    t = a;
    a = b;
    b = t;
}

void print_heap(std::vector<int> v) {
    int height;

    height = log2(v.size()) + 1;

    for (int level = 1; level <= height; level++) {
        int before = 5 * (pow(2, height - level) - 1);
        int between = 5 * pow(2, height - level);
        int nodes = pow(2, level - 1);
        int last_node = (2 * nodes <= v.size() ? 2 * nodes : v.size() + 1);

        for (int n = nodes - 1; n < last_node - 1; n++) {
            for (int i = 0; i < before; i++)
                std::cout << std::setw(1) << " ";
            std::cout << "(" << std::setw(3) << std::setfill('0') << v[n] << ")";
            if (n < 2 * nodes - 2)
                for (int i = 0; i < between; i++)
                    std::cout << std::setw(1) << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0 ; i < 5 * (pow(2, height) - 1); i++)
        std::cout << "=";
    std::cout << std::endl;
}

void heapify(std::vector<int> &v) {
    if (v.size() <= 1)
        return;
    
    int i, p;

    i = v.size() - 1;
    p = (i - 1) / 2;
    while (v[i] > v[p] and i > 0) {
        swap(v[i], v[p]);
        i = p;
        p = (i - 1) / 2;
    }
}

std::vector<int> heap(std::vector<int> v) {
    std::vector<int> res;

    for (int i = 0; i < v.size(); i++) {
        res.push_back(v[i]);
        heapify(res);
        print_heap(res);
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> values;
    std::vector<int> res;

    for (int i = 1; i < argc; i++) {
        int aux;
        std::stringstream(argv[i]) >> aux;
        values.push_back(aux);
    }

    res = heap(values);

    return 0;
}
