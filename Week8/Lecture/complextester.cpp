//
// Created by Scott McMaster on 5/16/2021.
//

#include <iostream>
#include "Complex.h"

int main() {
    Complex c1(5.0, 10.0);
    Complex c2(2.0, -1.5);

    std::cout << "Equal? " << (c1 == c2) << std::endl;

    c1 = c2;

    std::cout << "Equal? " << (c1 == c2) << std::endl;
}