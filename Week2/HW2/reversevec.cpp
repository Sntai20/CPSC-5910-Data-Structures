/*
 * Created by Antonio Santana on 5/17/21.
 *
 * Problem 2: Reverse vector
 * Write a program that recursively reverses a C++ vector (#include <vector>) of any data type and in-place.
 * ("In place" means that the positions of the elements in the original vector passed to the function are modified.)
 *
 * Demonstrate your program on:
 * A vector of int
 * A vector of string
 *
 * Function to print the vector.
 * The reverseVector accepts a vector of any type and the size of the vector and reverses the vector in place.
 * Pass vector by reference to reduce the consumption on the stack and pass startIndex by value.
 */
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector (vector<T> InputVector, int size);

template <typename T>
void reverseVector (vector<T> &v, int startIndex, int endIndex);

int main() {
    // TEST AN ARRAY OF INTS
    vector<int> numbers {1, 5, 6, 7, 10};
    int startIndexI = 0;
    int endIndexI = numbers.size() - 1;
    reverseVector(numbers, startIndexI, endIndexI);
    printVector (numbers, numbers.size());

    // TEST AN ARRAY OF STRINGS
    vector<string> strings {"cat", "dog", "bird", "cow", "frog", "horse"};
    int startIndexS = 0;
    int endIndexS = strings.size() - 1;
    reverseVector(strings, startIndexS, endIndexS);
    printVector (strings, strings.size());
    return 0;
}

template <typename T>
void printVector (vector<T> InputVector, int size)
{

    for (int i = 0; i < size; i++) {
        cout << InputVector[i] << " ";
    }
    cout << "\n";
}

template <typename T>
void reverseVector (vector<T> &v, int startIndex, int endIndex)
{
    if (endIndex <= startIndex){
        return;
    } else {
        T temp;
        temp = v[startIndex];
        v[startIndex] = v[endIndex];
        v[endIndex] = temp;
        reverseVector(v, startIndex + 1, endIndex - 1);
    }
}