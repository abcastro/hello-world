#include <iostream>
#include <vector>

char map[10][3] = {
    { '0', '0', '0' },
    { '1', '1', '1' },
    { 'A', 'B', 'C' },
    { 'D', 'E', 'F' },
    { 'G', 'H', 'I' },
    { 'J', 'K', 'L' },
    { 'M', 'N', 'O' },
    { 'P', 'R', 'S' },
    { 'T', 'U', 'V' },
    { 'W', 'X', 'Y' },
};

class telephone {
    std::vector<int> in;
    std::vector<int> used;
    std::string out;

    void print_cur() {
        for (int i = 0; i < in.size(); i++)
            std::cout << map[in[i]][used[i]];
        std::cout << std::endl;
    }

    bool next() {
        int i = 0;

        while (i < used.size()) {
            if (in[i] == 0 or in[i] == 1) {
                i++;
                continue;
            }
            used[i]++;
            if (used[i] == 3) {
                used[i] = 0;
                i++;
            } else {
                break;
            }
        }

        return (i < used.size());
    }

    void letter() {
        do {
            print_cur();
        } while (next());
    }

    public:
        void print_all(std::string s) {
            for (int i = 0; i < s.length(); i++) {
                in.push_back(s[i] - '0');
                used.push_back(0);
            }
            letter();
        }
};

int main(int argc, char *argv[]) {
    telephone phone;

    phone.print_all(argv[1]);

    return 0;
}
