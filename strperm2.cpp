#include <iostream>
#include <vector>

class permutation {
    std::vector<bool> used;
    std::string in;
    std::string out;

    void perm() {
        int j = 0;

        while (j < in.length()) {
            if (not used[j]) {
                used[j] = true;
                out += in[j];
                //std::cout << "parcial " << out << std::endl;
                perm();
                used[j] = false;
                out.resize(out.length() - 1);
            }
            j++;
        }
        if (out.length() == in.length())
            std::cout << "result " << out << std::endl;
    }

    public:
        void print_all(std::string s) {
            in = s;
            std::sort(in.begin(), in.end());
            out.clear();

            for (int i = 0; i < in.length(); i++)
                used.push_back(false);
            perm();
        }
};

int main(int argc, char *argv[]) {
    permutation perm;

    perm.print_all(argv[1]);

    return 0;
}
