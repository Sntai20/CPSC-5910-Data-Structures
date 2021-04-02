#include <iostream>
#include <string>

int numCalls = 0;

int binarySearch(int a[], int startIdx, int endIdx, int target) {
    int index = 0;
    if (startIdx > endIdx) {
        index = -1;
    } else {
        int mid = startIdx + (endIdx - startIdx) / 2;
        if (a[mid] == target) {
            index = mid;
        } else if (a[mid] > target) {
            index = binarySearch(a, startIdx, mid - 1, target);
        } else {
            index = binarySearch(a, mid + 1, endIdx, target);
        }
    }

    return index;
}

int main() {
    int b[] = {1, 6, 8, 9, 25, 28, 33, 44};
    std::cout << binarySearch(b, 0, sizeof(b)/sizeof(b[0]), 33) << std::endl;
    std::cout << binarySearch(b, 0, sizeof(b)/sizeof(b[0]), 66666666) << std::endl;
    return 0;
}
