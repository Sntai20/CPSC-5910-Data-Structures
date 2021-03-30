#include <iostream>

int main() {
    int myInt = 5;
    double myDbl = 3.14;
    bool myBool = true;

    //myInt = 3.3;      // is a warning
    //myInt = false;    // what about this?

    std::cout << "Int: " << myInt << std::endl;
    std::cout << "Double: " << myDbl<< std::endl;
    std::cout << "Bool: " << myBool << std::endl;
    return 0;
}
