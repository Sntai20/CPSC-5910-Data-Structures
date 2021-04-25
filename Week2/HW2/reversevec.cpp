//
// Created by Antonio Santana on 4/18/21.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 2: Reverse vector
 * Write a program that recursively reverses a C++ vector (#include <vector>) of any data type and in-place.
 * ("In place" means that the positions of the elements in the original vector passed to the function are modified.)

Demonstrate your program on:
A vector of int
A vector of std::string
 */

template<typename T>
void reverseVector( T &InputVector, int startIndex, int endIndex);
template<typename T>
void reverseVectorS( T (&InputVector), int startIndex, int endIndex);

template<typename T>
void printVector(T const (&InputVector));

int main() {
    // TEST AN ARRAY OF INTS
    vector<int> numbers {1, 5, 6, 7, 10};
    // TODO
    printVector(numbers);
    reverseVector(numbers, 0, numbers.size());
    printVector(numbers);

    // TEST AN ARRAY OF STRINGS
    vector<string> strings {"cat", "dog", "bird", "cow", "frog", "horse"};
    // TODO
    printVector(strings);
    reverseVectorS(strings, 0, strings.size());
    printVector(strings);

    return 0;
}

// Pass vector by reference to reduce the consumption on the stack.
// Pass startIndex by value.
template<typename T>
void reverseVector( T (&InputVector), int startIndex, int endIndex)
{
    int temp;
    if (startIndex <= endIndex){
        temp = InputVector[endIndex - 1];
        InputVector[endIndex-1] = InputVector[startIndex];
        InputVector[startIndex] = temp;
        reverseVector(InputVector, startIndex + 1, endIndex -1);
    }
}

template<typename T>
void reverseVectorS( T (&InputVector), int startIndex, int endIndex)
{
    string temp;
    if (startIndex <= endIndex){
        temp = InputVector[endIndex - 1];
        InputVector[endIndex-1] = InputVector[startIndex];
        InputVector[startIndex] = temp;
        reverseVectorS(InputVector, startIndex + 1, endIndex -1);
    }
}

template<typename T>
void printVector(T const (&InputVector))
{
    int n = InputVector.size();
    for ( int i = 0 ; i < n ; i++ )
    {
        std::cout << InputVector[i] << ' ';
    }
    cout << endl;
}

