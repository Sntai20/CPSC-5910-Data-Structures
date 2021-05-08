#include<iostream>
using namespace std;

// An abstract class with constructor
class Base {
public:
    Base(int i) { x = i; }
    virtual void fun() = 0;
protected:
    int x;
};

class Derived: public Base {
public:
    Derived(int i, int j):Base(i) { y = j; }
    void fun() override { cout << "x = " << x << ", y = " << y << endl; }
private:
    int y;
};

int main() {
    Derived d(4, 5);
    d.fun();
    return 0;
}

// OUTPUT
// x = 4, y = 5
