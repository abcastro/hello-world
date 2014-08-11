#include <iostream>
#include <set>
#include <iterator>
#include <cmath>

#include <math.h>

// polymorphism example

class point {
    public:
        float x;
        float y;
        
        point() {
            this->x = 0;
            this->y = 0;
        }

        point(float a, float b) {
            this->set(a, b);
        }

        void set(float a, float b) {
            this->x = a;
            this->y = b;
        }

        float distance(point *p) {
            float res;

            res = sqrt(pow(this->x - p->x, 2) + pow(this->y - p->y, 2));

            // std::cout << "(" << this->x << ", " << this->y << ") -> (" << p->x << ", " << p->y << ") = " << res << std::endl;
            return res;
        }
};

class polygon {
    protected:
        std::set<point *> p;

    public:
        virtual float area() {
            return 0;
        }

        virtual float perimeter() {
            float res = 0.0;

            if (p.size() >= 3) {
                std::set<point *>::iterator it = p.begin();
                std::set<point *>::iterator it2 = p.begin();
                it2++;

                while (it2 != p.end()) {
                    res += (*it)->distance((*it2));
                    it++;
                    it2++;
                }
                it2 = p.begin();
                res += (*it)->distance(*it2);
            }

            return res;
        };

        virtual void addPoint(int x, int y) {
            point *a = new point(x, y);
            p.insert(a);
        }
};

class triangle: public polygon {
    public:
        virtual float calcWidth() {
            float width = -1;

            if (p.size() == 3) {
                std::set<point *>::iterator it = p.begin();
                std::set<point *>::iterator it2 = p.begin();
                it2++;

                width = (*it)->distance((*it2));
                //std::cout << "triangle width " << width << std::endl;
            }

            return width;
        }

        virtual float calcHeight() {
            float height = -1;
            float a, b, c;

            if (p.size() == 3) {
                std::set<point *>::iterator it1 = p.begin();
                std::set<point *>::iterator it2 = p.begin();
                std::set<point *>::iterator it3 = p.begin();
                it2++;
                it3++;
                it3++;

                a = ((*it1)->y - (*it2)->y) / ((*it2)->x - (*it1)->x);
                b = 1;
                c = ((*it1)->x * (*it2)->y - (*it1)->y * (*it2)->x)/((*it2)->x - (*it1)->x);
                
                height = std::abs(a * (*it3)->x + b * (*it3)->y + c) / sqrt(pow(a, 2) + pow(b, 2));
                //std::cout << "triangle height " << height << std::endl;
            }

            return height;
        }

        virtual float area() {
            float res;

            res = this->calcWidth() * this->calcHeight() / 2.0;

            return res;
        }

        void addPoint(int x, int y) {
            if (p.size() < 3) {
                polygon::addPoint(x, y);
            }
        }
};

int main() {
    float tmp;
    polygon p;
    
    p.addPoint(1, -1);
    p.addPoint(0, 1);
    p.addPoint(-1, -1);
    p.addPoint(-8, -4);
    p.addPoint(4, -2);
    p.addPoint(-5, 7);

    tmp = p.area();
    std::cout << "polygon area " << tmp << std::endl;
    tmp = p.perimeter();
    std::cout << "polygon perimeter " << tmp << std::endl;

    triangle t;

    //t.addPoint(1, -1);
    //t.addPoint(0, 1);
    //t.addPoint(-1, -1);
    t.addPoint(-8, -4);
    t.addPoint(4, -2);
    t.addPoint(-5, 7);

    tmp = t.area();
    std::cout << "triangle area " << tmp << std::endl;
    tmp = t.perimeter();
    std::cout << "triangle perimeter " << tmp << std::endl;

    return 0;
}
