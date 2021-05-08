#include <iostream> 
using namespace std;
 
class Shape {     
public:
    Shape(int a = 0, int b = 0){
        width = a;
        height = b;
    }
    virtual int area() { return 0; }
protected:
    int width, height;
};

class Rectangle: public Shape {
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) { }      
    int area () { return (width * height); }
};

class Triangle: public Shape {
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) { }  
    int area () { return (width * height / 2); }
};

// Main function for the program
int main() {
    Shape *shape;
    Rectangle rec(4, 5);
    Triangle  tri(4, 5);

    // store the address of Rectangle
    shape = &rec;
   
    // call rectangle area.
    cout << "Rectangle area: " << shape->area() << endl;

    // store the address of Triangle
    shape = &tri;
   
    // call triangle area.
    cout << "Triangle area: " << shape->area() << endl;
   
    return 0;
}

// OUTPUT
// Rectangle area: 20
// Triangle area: 10
