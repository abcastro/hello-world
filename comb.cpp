#include <iostream>

class combination {
    std::string in;
    std::string out;

    void comb(int l) {
        for (int i = l ; i < in.length(); i++) {
            out += in[i];
            std::cout << out << std::endl;
            comb(i + 1);
            out.resize(out.length() - 1);
        }
    }

    public:
        void print_all(std::string s) {
            in = s;
            comb(0);
        }
};

int main(int argc, char *argv[]) {
    combination comb;

    comb.print_all(argv[1]);

    return 0;
}
