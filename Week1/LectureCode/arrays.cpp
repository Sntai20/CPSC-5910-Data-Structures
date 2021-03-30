#include <iostream>

int main() {
    // Stack-based array.
    int myInts[10];

    for (int i = 0; i < 10; i++) {
        myInts[i] = i*10;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << myInts[i] << std::endl;
    }

    std::cout << std::endl;

    // Pointer to array
    int* pArr = myInts;
    std::cout << *pArr << std::endl;
    std::cout << pArr[5] << std::endl;

    std::cout << std::endl;

    // Static initialization
    int moreInts[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        std::cout << moreInts[i] << std::endl;
    }

    std::cout << std::endl;

    // 2D
    int matrix[2][3] = {{0, 1, 2}, {3, 4, 5}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << std::endl;
        }
    }

    return 0;
}
