#include <iostream>
#include <queue>
#include <stack>
#include <iterator>
#include <sstream>

// convert a infix expression to RPN

int hasPrec(char a) {
    int res;

    if (a == '+' or a == '-')
        res = 1;
    if (a == '*' or a == '/')
        res = 2;
    if (a == '^')
        res = 3;
    if (a == '(' or a == ')')
        res = 4;

    return res;
}

std::string conv2RPN(std::string expr) {
    std::string out;
    std::stack<char> ops;

    for (std::string::iterator it = expr.begin(); it != expr.end(); ++it) {
        switch (*it) {
            case '+':
            case '-':
            case '*':
            case '/':
                if (not ops.empty()) {
                    if (hasPrec(*it) == hasPrec(ops.top())) {
                        out += ops.top();
                        out += ' ';
                        ops.pop();
                    }
                }
            case '^':
            case '(':
                ops.push(*it);
                break;
            case ')':
                while (ops.top() != '(') {
                    out += ops.top();
                    out += ' ';
                    ops.pop();
                }
                ops.pop();
                break;
            case ' ':
                break;
            default: 
                out += *it;
                out += ' ';
        }
    }

    while (not ops.empty()) {
        out += ops.top();
        out += ' ';
        ops.pop();
    }

    return out;
}

int main(int argc, char *argv[]) {
    std::string expr;

    expr = argv[1];

    std::cout << conv2RPN(expr) << std::endl;

    return 0;
}
