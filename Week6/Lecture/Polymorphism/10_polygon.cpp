#include <iostream>
using namespace std;

class Polygon {
public:
    void set_values (int a, int b) { width = a; height = b; }
    virtual int area () { return 0; }
protected:
    int width, height;
};

class Rectangle: public Polygon {
public:
    int area () override { return width * height; }
};

class Triangle: public Polygon {
public:
    int area () override { return (width * height / 2); }
};

int main() {
    Rectangle rect;
    Triangle trgl;
    Polygon poly;
    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;
    Polygon * ppoly3 = &poly;
    ppoly1->set_values (4, 5);
    ppoly2->set_values (4, 5);
    ppoly3->set_values (4, 5);
    cout << ppoly1->area() << '\n';
    cout << ppoly2->area() << '\n';
    cout << ppoly3->area() << '\n';
    return 0;
}

// OUTPUT
// 20
// 10
// 0
