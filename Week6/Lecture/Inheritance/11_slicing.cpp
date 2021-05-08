#include <iostream>
using namespace std;
 
class Base {
public:
    Base(int a) { i = a; }
    void display() { 
        cout << "I am Base class object, i = " << i << endl; 
    }
protected:
    int i;
};
 
class Derived : public Base {
public:
    Derived(int a, int b) : Base(a) { j = b; }
    void display() { 
        cout << "I am Derived class object, i = " << i << ", j = " << j << endl;  
    }
private:
    int j;
};
 
// Global method, Base class object is passed by value
void somefunc (Base obj) {
    obj.display();
}
 
int main() {
    Base b(33);
    Derived d(45, 54);
    somefunc(b);
    somefunc(d);  // Object Slicing, the member j of d is sliced off
    return 0;
}

// OUTPUT
// I am Base class object, i = 33
// I am Base class object, i = 45
