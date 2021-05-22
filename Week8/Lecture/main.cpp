#include <iostream>
#include "ArrayMaxHeap.h"

int main() {
    std::cout << "ArrayMaxHeap testing" << std::endl;
    ArrayMaxHeap<int> heapOfInts;
    heapOfInts.add(3);
    heapOfInts.add(12);
    heapOfInts.add(4);
    heapOfInts.add(7);
    heapOfInts.add(15);
    heapOfInts.add(9);

    std::cout << "Peek: " << heapOfInts.peekTop() << std::endl;
    std::cout << "Height: " << heapOfInts.getHeight() << std::endl;
    std::cout << "Remove: " << heapOfInts.remove() << std::endl;
    std::cout << "Peek Again: " << heapOfInts.peekTop() << std::endl;

    return 0;
}
