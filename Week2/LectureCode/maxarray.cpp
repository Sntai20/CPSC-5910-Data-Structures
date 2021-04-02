#include <iostream>
#include <string>

int numCalls = 0;

int maxArray(int a[], int startIdx, int endIdx) {
    if (startIdx == endIdx) {
        return a[startIdx];
    } else {
        int mid = (startIdx + endIdx)/2;
        return std::max(
                maxArray(a, startIdx, mid),
                maxArray(a, mid + 1, endIdx));
    }
}

int main() {
    int a[] = {1, 6, 8, 3};
    std::cout << maxArray(a, 0, sizeof(a)/sizeof(a[0])) << std::endl;

    int b[] = {1, 6, 8, 3, 3, 0, 100, 33, 57, 9};
    std::cout << maxArray(b, 0, sizeof(b)/sizeof(b[0])) << std::endl;
    return 0;
}
