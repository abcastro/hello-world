#include <iostream>
#include <vector>

// all subsets that sum to a number

int calc_sum(std::vector<int> v, std::vector<bool> p) {
    int sum = 0;

    for (int i = 0; i < p.size(); i++) {
        if (p[i]) {
            sum += v[i];
        }
    }

    return sum;
}

void print_vector(std::vector<int> v, std::vector<bool> p, int s) {
    for (int i = 0; i < p.size(); i++) {
        std::cout << (p[i] ? 1 : 0);
    }
    std::cout << " ";

    for (int i = 0; i < v.size(); i++) {
        if (p[i]) {
            std::cout << v[i] << " ";
        }
    }

    std::cout << " = " << s << std::endl;
}

void gen_perm(std::vector<int> v, int s, std::vector<bool> p, int l) {
    if (v.size() == 0)
        return;

    if (v.size() <= l) {
        if (calc_sum(v, p) == s) {
            print_vector(v, p, s);
        }
        return;
    }

    p[l] = false;
    gen_perm(v, s, p, l+1);
    p[l] = true;
    gen_perm(v, s, p, l+1);
}

void findSum(std::vector<int> v, int s) {
    std::vector<bool> p;
    
    for (int i = 0; i < v.size(); i++)
        p.push_back(false);

    gen_perm(v, s, p, 0);
}

int main() {
    std::vector<int> values;
    int sum;

    values.push_back(9);
    values.push_back(1);
    values.push_back(7);
    values.push_back(-1);
    values.push_back(-7);
    values.push_back(-2);
    values.push_back(3);
    values.push_back(6);
    values.push_back(-4);
    values.push_back(-5);

    sum = -10;

    findSum(values, sum);

    return 0;
}
