//CPP program to illustrate 
//concept of Virtual Functions
#include<iostream>
using namespace std;

class base {
public:
    virtual void print () { cout << "print base class" << endl; }
    void show () { cout << "show base class" << endl; }
};

class derived:public base {
public:
    //void print () override { cout << "print derived class" << endl; }
    void show () { cout << "show derived class" << endl; }  // why can't this use override keyword? 
};

int main() {
    base *bptr;
    derived d;
    bptr = &d;
    
    //virtual function, binded at runtime
    bptr->print(); 
    
    //Non-virtual function, binded at compile time
    bptr->show(); 

    base b;
    b.print();
    b.show();

    // Do you need to delete pointer?
}

// OUTPUT
// print derived class
// show base class
// print base class
// show base class
