#include <iostream>
using namespace std;

class Polygon {
public:
    void set_values (int a, int b) { width = a; height = b; }
    virtual int area (void) = 0;   // void parameter means function w no params
                                   // same as "virtual int area () = 0;"
protected:
    int width, height;
};

class Rectangle: public Polygon {
public:
    int area (void) override { return (width * height); }
};

class Triangle: public Polygon {
public:
    int area (void) override { return (width * height / 2); }
};

int main() {
    Rectangle rect;
    Triangle trgl;
    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;
    ppoly1->set_values (4, 5);
    ppoly2->set_values (4, 5);
    cout << ppoly1->area() << '\n';
    cout << ppoly2->area() << '\n';
    return 0;
}

// OUTPUT
// 20
// 10
