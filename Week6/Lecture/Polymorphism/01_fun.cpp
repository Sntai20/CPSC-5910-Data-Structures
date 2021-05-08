#include<iostream>
using namespace std;

class Base {
public:
    virtual void fun() = 0;
    int getX() { return x; }
private:
    int x;
};

// This class ingerits from Base and implements fun()
class Derived: public Base {
public:
    void fun() override { cout << "fun() called\n"; }
private:
    int y;
};

int main() {
    Derived d;
    d.fun();
    return 0;
}

// OUTPUT
// fun() called
