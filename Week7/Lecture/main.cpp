#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "bubblesort.h"
#include "insertionsort.h"
#include "selectionsort.h"
#include "mergesort.h"
#include "quicksort.h"

int main() {
    srand(7);

    const int RANGE = 1000;
    const long SIZE = 10000;
    int* data = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % RANGE;
    }

    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(data, SIZE);
    //insertionSort(data, SIZE);
    //selectionSort(data, SIZE);
    //mergeSort(data, 0, SIZE - 1);
    //quickSort(data, 0, SIZE - 1);

    auto stop = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << duration.count() << std::endl;

    delete[] data;
    return 0;
}
