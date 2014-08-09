#include <iostream>
#include <stack>

// hanoi tower - structured version

void PrintHanoi(std::stack<int> t1, std::stack<int> t2, std::stack<int> t3) {
    int s1 = t1.size();
    int s2 = t2.size();
    int s3 = t3.size();

    int max = s1 > s2 ? s1 : s2;
    max = s3 > max ? s3 : max;

    while (max > 0) {
        if (max == t1.size()) {
            std::cout << t1.top() << "	";
            t1.pop();
        } else {
            std::cout << " 	";
        }

        if (max == t2.size()) {
            std::cout << t2.top() << "	";
            t2.pop();
        } else {
            std::cout << " 	";
        }

        if (max == t3.size()) {
            std::cout << t3.top() << "	";
            t3.pop();
        } else {
            std::cout << " 	";
        }

        std::cout << std::endl;
        max--;
    }
    std::cout << "t1	t2	t3" << std::endl;
    std::cout << "==	==	==" << std::endl;
}

void MoveHanoi(int disks, std::stack<int> &from, std::stack<int> &tmp, std::stack<int> &to) {
    int d;

    if (disks == 0)
        return;

    MoveHanoi(disks - 1, from, to, tmp);
    d = from.top();
    from.pop();
    to.push(d);
    //std::cout << "moving " << d << std::endl;
    PrintHanoi(from, tmp, to);
    MoveHanoi(disks - 1, tmp, from, to);
}

int main() {
    std::stack<int> t1;
    std::stack<int> t2;
    std::stack<int> t3;

    int disks = 5;

    for (int i = disks; i > 0; i--)
        t1.push(i);

    PrintHanoi(t1, t2, t3);
    MoveHanoi(t1.size(), t1, t2, t3);
    PrintHanoi(t1, t2, t3);

    return 0;
}
