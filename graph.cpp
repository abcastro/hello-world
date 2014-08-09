#include <iostream>
#include <map>
#include <list>
#include <queue>

// transverse directed graph

class Node {
    public:
    int id;
    int weight;
    bool visited;
    std::map<Node *, int> vertices;

    Node() {
        this->id = -1;
        this->weight = -1;
        this->visited = false;
    }

    Node(int id, int weight) {
        this->id = id;
        this->weight = weight;
        this->visited = false;
    }

    void addVertex(Node *to, int weight) {
        this->vertices.insert(std::make_pair<Node *, int>(to, weight));
    }

    void print() {
        std::cout << "ID " << this->id << " (" << this->weight << ") ->";
        for (std::map<Node *, int>::iterator it = this->vertices.begin(); it != this->vertices.end(); ++it)
            std::cout << " " << (*it).first->id << " (" << (*it).second << ")";
        std::cout << std::endl;
    }

    void print_depth() {
        if (this->visited)
            return;
        this->visited = true;
        std::cout << this->id << " ";
        for (std::map<Node *, int>::iterator it = this->vertices.begin(); it != this->vertices.end(); ++it) {
            (*it).first->print_depth();
        }
    }
};

class Graph {
    public:
    std::list<Node *> nodes;

    void addNode(int id, int weight) {
        Node *n = new Node(id, weight);
        this->nodes.push_back(n);
    }

    void delNode(int id) {
        for (std::list<Node *>::iterator it = this->nodes.begin(); it != this->nodes.end(); ++it)
            if ((*it)->id == id) {
                this->nodes.erase(it);
                break;
            }
    }

    void addVertex(int from, int to, int weight) {
        Node *nfrom = NULL;
        Node *nto = NULL;

        for (std::list<Node *>::iterator it = this->nodes.begin(); it != this->nodes.end(); ++it) {
            if ((*it)->id == from)
                nfrom = (*it);
            if ((*it)->id == to)
                nto = (*it);
        }

        if (nfrom and nto) {
            nfrom->addVertex(nto, weight);
        }
    }

    void print() {
        for (std::list<Node *>::iterator it = this->nodes.begin(); it != this->nodes.end(); ++it)
            (*it)->print();
    }

    void print_depth(int id) {
        std::cout << "depth ";
        for (std::list<Node *>::iterator it = this->nodes.begin(); it != this->nodes.end(); ++it) {
            if ((*it)->id == id) {
                (*it)->print_depth();
                break;
            }
        }
        std::cout << std::endl;
        for (std::list<Node *>::iterator it = this->nodes.begin(); it != this->nodes.end(); ++it)
            (*it)->visited = false;
    }

    void print_breadth(int id) {
        std::cout << "breadth ";
        std::queue<Node *> q;
        for (std::list<Node *>::iterator it = this->nodes.begin(); it != this->nodes.end(); ++it) {
            if ((*it)->id == id) {
                q.push((*it));
                break;
            }
        }

        while (not q.empty()) {
            Node *tmp;
            tmp = q.front();
            q.pop();
            if (tmp->visited)
                continue;
            tmp->visited = true;
            std::cout << tmp->id << " ";
            for (std::map<Node*, int>::iterator it = tmp->vertices.begin(); it != tmp->vertices.end(); ++it) {
                q.push((*it).first);
            }
        }

        std::cout << std::endl;
        for (std::list<Node *>::iterator it = this->nodes.begin(); it != this->nodes.end(); ++it)
            (*it)->visited = false;
    }
};

int main() {
    Graph g;
    
    g.addNode(0, 37);
    g.addNode(1, 55);
    g.addNode(2, 67);
    g.addNode(3, 95);
    g.addNode(4, 29);
    g.addNode(5, 51);

    g.addVertex(0, 1, 49);
    g.addVertex(0, 5, 57);
    g.addVertex(1, 2, 73);
    g.addVertex(2, 3, 10);
    g.addVertex(3, 5, 35);
    g.addVertex(3, 4, 79);
    g.addVertex(4, 0, 77);
    g.addVertex(5, 2, 43);
    g.addVertex(5, 4, 93);

    g.print();

    g.print_depth(0);
    g.print_depth(1);
    g.print_depth(2);
    g.print_depth(3);
    g.print_depth(4);
    g.print_depth(5);

    g.print_breadth(0);
    g.print_breadth(1);
    g.print_breadth(2);
    g.print_breadth(3);
    g.print_breadth(4);
    g.print_breadth(5);

    return 0;
}
