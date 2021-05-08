#include<iostream>
using namespace std;

class Base {
public:
    Base() { cout << "In base constructor\n"; }
    virtual ~Base() { cout << "Destructor of base\n"; }
    virtual void show() = 0;
};

class Derived: public Base {
public:
    Derived() { cout << "In derived constructor\n"; }
    ~Derived() { cout << "Destructor of derived\n"; }
    void show() override { cout << "In derived \n"; }
    void fxnA() { cout << "In fxnA\n"; }
};

int main() {
    Base *bp = new Derived();
    bp->show();
    //bp->fxnA();       // this will cause issues; why?
    delete bp;

    cout << "non-pointer" << endl;
    Derived d;
    d.show();
    d.fxnA();

    return 0;
}

// OUTPUT
// In base constructor
// In derived constructor
// In derived 
// Destructor of derived
// Destructor of base
// non-pointer
// In base constructor
// In derived constructor
// In derived 
// In fxnA
// Destructor of derived
// Destructor of base
