#include <iostream>

int main() {
    int first = 7;
    int second = 10;

    std::cout << "Sum: " << first + second << std::endl;
    std::cout << "Difference: " << second - first << std::endl;
    std::cout << "Product: " << second * first << std::endl;
    std::cout << "Quotient: " << second / first << std::endl;   // truncates, NOT rounds

    std::cout << "Greater? " << (first > second) << std::endl;
    std::cout << "Less? " << (first < second) << std::endl;
    std::cout << "Equal? " << (first == second) << std::endl;

    first = second;
    std::cout << "Equal after assignment? " << (first == second) << std::endl;

    return 0;
}
