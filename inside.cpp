#include <iostream>

// check if a point is inside a polygon

class Point {
    public:
        int x;
        int y;
    
    Point() {
        this->x = 0;
        this->y = 0;
    }
    
    Point(int a, int b) {
        this->x = a;
        this->y = b;
    }

    // using cross product
    int sign(Point a, Point b) {
        return ((this->x - b.x) * (a.y - b.y) - (a.x - b.x) * (this->y - b.y));
    }

    // using barycentric coordinates
    float alpha(Point a, Point b, Point c) {
        int t1;
        int t2;

        t1 = (b.y - c.y) * (this->x - c.x) + (c.x - b.x) * (this->y - c.y);
        t2 = (b.y - c.y) * (a.x     - c.x) + (c.x - b.x) * (a.y     - c.y);

        return (float) t1/t2;
    }

    float beta(Point a, Point b, Point c) {
        int t1;
        int t2;
        
        t1 = (c.y - a.y) * (this->x - c.x) + (a.x - c.x) * (this->y - c.y);
        t2 = (b.y - c.y) * (a.x     - c.x) + (c.x - b.x) * (a.y     - c.y);

        return (float) t1/t2;
    }

    float gamma(float a, float b) {
        return 1.0 - a - b;
    }
};

int main() {
    float a, b, g;
    Point p1(-8, -4);
    Point p2(4, -2);
    Point p3(-5, 7);

    Point x(-4, 2);
    Point y(4, 9);

    std::cout << "cross product x" << std::endl;
    std::cout << x.sign(p1, p2) << std::endl;
    std::cout << x.sign(p2, p3) << std::endl;
    std::cout << x.sign(p3, p1) << std::endl;

    std::cout << "cross product y" << std::endl;
    std::cout << y.sign(p1, p2) << std::endl;
    std::cout << y.sign(p2, p3) << std::endl;
    std::cout << y.sign(p3, p1) << std::endl;

    std::cout << "barycentric coordinates x" << std::endl;
    a = x.alpha(p1, p2, p3);
    b = x.beta(p1, p2, p3);
    g = x.gamma(a, b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << g << std::endl;

    std::cout << "barycentric coordinates y" << std::endl;
    a = y.alpha(p1, p2, p3);
    b = y.beta(p1, p2, p3);
    g = y.gamma(a, b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << g << std::endl;

    return 0;
}
