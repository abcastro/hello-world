#include <iostream>
#include <queue>

class Node {
    private:
        Node *left;
        Node *right;
        int value;

    public:
        Node() {
            this->value = 0;
            this->left = NULL;
            this->right = NULL;
        }
        Node(int v) {
            this->value = v;
            this->left = NULL;
            this->right = NULL;
        }
        virtual ~Node() {
            if (this->left)
                delete this->left;
            if (this->right)
                delete this->right;
        }

        void set_value(int v) {
            this->value = v;
        }
        int get_value() {
            return this->value;
        }

        void insert(int v) {
            if (this->value > v) {
                if (this->left) {
                    this->left->insert(v);
                } else {
                    this->left = new Node(v);
                }
            }
            if (this->value < v) {
                if (this->right) {
                    this->right->insert(v);
                } else {
                    this->right = new Node(v);
                }
            }
        }

        int maxDepth() {
            int l = 0;
            int r = 0;

            if (this->left) {
                l = this->left->maxDepth();
            }
            if (this->right) {
                r = this->right->maxDepth();
            }
            return std::max(l, r) + 1;
        }

        int minDepth() {
            int l = 0;
            int r = 0;

            if (this->left) {
                l = this->left->minDepth();
            }
            if (this->right) {
                r = this->right->minDepth();
            }
            return ((r == 0 or l == 0) ? l + r : std::min(l, r)) + 1;
        }

        void print_pre() {
            std::cout << this->value << " ";
            if (this->left)
                this->left->print_pre();
            if (this->right)
                this->right->print_pre();
        }

        void print_rev_in() {
            if (this->right)
                this->right->print_rev_in();
            std::cout << this->value << " ";
            if (this->left)
                this->left->print_rev_in();
        }

        void print_in() {
            if (this->left)
                this->left->print_in();
            std::cout << this->value << " ";
            if (this->right)
                this->right->print_in();
        }

        void print_post() {
            if (this->left)
                this->left->print_post();
            if (this->right)
                this->right->print_post();
            std::cout << this->value << " ";
        }

        void print_breadth() {
            std::queue<Node*> q;
            q.push(this);

            while (not q.empty()) {
                Node *aux;
                aux = q.front(); q.pop();
                if (aux->left)
                    q.push(aux->left);
                if (aux->right)
                    q.push(aux->right);
                std::cout << aux->get_value() << " ";
            }
        }
};

int main() {
    Node n(20);

    n.insert(24);
    n.insert(12);
    n.insert(27);
    n.insert(11);
    n.insert(16);
    n.insert(26);
    n.insert(14);
    n.insert(18);
    n.insert(23);
    n.insert(22);
    n.insert(29);
    n.insert(13);
    n.insert(17);
    n.insert(10);
    n.insert(30);
    n.insert(19);
    n.insert(25);
    n.insert(15);
    n.insert(21);
    n.insert(28);

    std::cout << "pre ";
    n.print_pre();
    std::cout << std::endl;

    std::cout << "inr ";
    n.print_rev_in();
    std::cout << std::endl;

    std::cout << "ino ";
    n.print_in();
    std::cout << std::endl;

    std::cout << "pos ";
    n.print_post();
    std::cout << std::endl;

    std::cout << "bth ";
    n.print_breadth();
    std::cout << std::endl;

    std::cout << "max " << n.maxDepth() << std::endl;

    std::cout << "min " << n.minDepth() << std::endl;

    return 0;
}
