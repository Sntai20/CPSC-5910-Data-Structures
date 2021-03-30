#include <iostream>
#include <string>

int myGlobal = 10;

void printSum(int a, int b) {
    // a and b are parameters.

    int sum = a + b;    // sum is a local variable, only defined inside this function.
    std::cout << "Sum: " << sum << std::endl;
}

void printIsEven(int a) {
    bool even = (a % 2 == 0);
    // not the best way to structure this code...for demo only
    if (even) {
        std::string result = "even";
        std::cout << result << std::endl;
    } else {
        std::string result = "odd";
        std::cout << result << std::endl;
    }

    // out here, result is undefined.
    // C/C++ is block-scoped.
    //std::cout << result << std::endl;
}

int main() {
    int myLocal = 5;

    std::cout << "Global: " << myGlobal << std::endl;
    std::cout << "Local: " << myLocal << std::endl;
    printSum(5, 10);
    printIsEven(4);

    return 0;
}
