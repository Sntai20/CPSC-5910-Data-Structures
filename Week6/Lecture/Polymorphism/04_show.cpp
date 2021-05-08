#include<iostream>
using namespace std;

class Base {
public:
    virtual void show() = 0;
};

class Derived : public Base { };

int main() {
    Derived d;      // why compile errors?
    return 0;
}

// OUTPUT
//4_show.cpp: In function ‘int main()’:
//4_show.cpp:13:11: error: cannot declare variable ‘d’ to be of abstract type ‘Derived’
//   Derived d;
//           ^
//4_show.cpp:9:7: note:   because the following virtual functions are pure within ‘Derived’:
// class Derived : public Base { };
//       ^
//4_show.cpp:6:18: note:    virtual void Base::show()
//     virtual void show() = 0;
//                  ^
