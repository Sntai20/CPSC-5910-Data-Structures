// pure virtual functions make a class abstract
#include<iostream>
using namespace std;

class Test {
public:
    virtual void show() = 0;
    int getX() { return x; }
private:
    int x;
};

int main() {
    Test t;         // why compile error?
    return 0;
}

// OUTPUT
//2_show.cpp: In function ‘int main()’:
//2_show.cpp:14:10: error: cannot declare variable ‘t’ to be of abstract type ‘Test’
//     Test t;			// why compile error?
//          ^
//2_show.cpp:5:7: note:   because the following virtual functions are pure within ‘Test’:
// class Test
//       ^
//2_show.cpp:7:18: note:    virtual void Test::show()
//     virtual void show() = 0;
//                  ^
