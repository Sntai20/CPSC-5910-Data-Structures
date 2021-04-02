#include <iostream>

// Prototype - forward declaration
int multNumbers(int first, int second);

int addNumbers(int first, int second) {
    return first + second;
}

void swap(int& first, int& second) {
    int tmp = second;
    second = first;
    first = tmp;
}

void byValVsByRef(int passByValue, int& passByReference) {
    std::cout << "Inside fcn: " << passByValue << " " << passByReference << std::endl;
    passByValue = 100;
    passByReference = 100;
}

int main() {
    std::cout << addNumbers(2, 3) << std::endl;
    std::cout << multNumbers(2, 3) << std::endl;

    int first = 3;
    int second = 50;
    std::cout << "Before: " << first << " " << second << std::endl;
    swap(first, second);
    std::cout << "After: " << first << " " << second << std::endl;

    int third = 2;
    int fourth = 20;
    std::cout << "Before: " << third << " " << fourth << std::endl;
    byValVsByRef(third, fourth);
    std::cout << "After: " << third << " " << fourth << std::endl;

    return 0;
}

int multNumbers(int first, int second) {
    return first * second;
}