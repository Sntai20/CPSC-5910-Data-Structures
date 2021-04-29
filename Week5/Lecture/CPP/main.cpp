#include <iostream>
#include <string>
#include "SmartPtr.h"

void test() {
    SmartPtr<std::string> pstr(new std::string("fcn call"));
    std::cout << "In function " << *pstr << std::endl;
}

int main() {
    SmartPtr<std::string> pstr(new std::string("hello"));
    std::cout << "Dereference " << *pstr << std::endl;
    pstr->append(" world");
    std::cout << "After append " << *pstr << std::endl;

    std::cout << std::endl;
    test();
    std::cout << std::endl;

    return 0;
}
