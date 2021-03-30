#include <iostream>

int main() {
    // Stack integer
    int x = 3;
    std::cout << x << " " << &x << std::endl;

    // Single heap integer
    int* pInt = new int;
    *pInt = 10;

    std::cout << pInt << " " << *pInt << " " << &(*pInt) << std::endl;

    delete pInt;

    std::cout << std::endl;

    // Larger block of memory
    int* pInts = new int[10];
    for (int i = 0; i < 10; i++) {
        pInts[i] = i*10;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << pInts[i] << std::endl;
    }
    delete[] pInts;

    return 0;
}
