#include <iostream>
#include <iterator>

int checkPal(std::string s, std::string::iterator it1, std::string::iterator it2) {
    int d = 0;
    while ((*(it1-d)) == (*(it2+d))) {
        if ((it1-d) == s.begin())
            break;
        d++;
        if ((it2+d) == s.end())
            break;
    }

    for (std::string::iterator it = (it1-d+1); it != (it2+d) ; ++it)
        std::cout << *it;
    std::cout << std::endl;

    return 2*d;
}

int main() {
    std::string s = "HYTBCABADEFGHABCDEDCBAGHTFYW1234567887654321ZWETYGDE";
    int max = 0;

    for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
        int size;
        if ((it+1) != s.end() and (*it) == (*(it+1))) {
            size = checkPal(s, it, it+1);
        }
        if (it != s.begin() and (it+1) != s.end() and (*(it-1)) == (*(it+1))) {
            size = checkPal(s, it-1, it+1) + 1;
        }
        if (size > max)
            max = size;
    }

    std::cout << max << std::endl;

    return 0;
}
