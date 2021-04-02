#include <iostream>

int numCalls = 0;

// Depending on your system, this may crash or return wrong results for larger n.
int fact(int n) {
    numCalls++;

    if (n == 0) {
        return 1;
    } else {
        return n * fact(n-1);
    }
}
int main() {
    std::cout << fact(20) << std::endl;
    std::cout << numCalls << std::endl;
    return 0;
}
