#include <iostream>
#include <set>

// all permutations of a string - recursive

std::set<std::string> *recursive(std::string str) {
    std::set<std::string> *ss = new std::set<std::string>();

    if (str.length() == 0) {
        return ss;
    }

    if (str.length() == 1) {
        ss->insert(str);
        return ss;
    }

    std::set<std::string> *tmp = NULL;
    tmp = recursive(str.substr(0, str.length() - 1));

    std::string n;
    n  = str[str.length()-1];

    for (std::set<std::string>::iterator it = tmp->begin(); it != tmp->end(); ++it) {
        for (int i = 0; i <= (*it).length(); i++) {
            std::string aux = (*it);
            aux.insert(i, n);
            ss->insert(aux);
        }
    }

    delete tmp;
    return ss;
}

int main(int argc, char *argv[]) {

    if (argc >= 2) {
        std::string str(argv[1]);
        
        std::set<std::string> *tmp = recursive(str);

        for (std::set<std::string>::iterator it = tmp->begin(); it != tmp->end(); ++it) {
            std::cout << (*it) << std::endl;
        }
        
        delete tmp;
    }

    return 0;
}
