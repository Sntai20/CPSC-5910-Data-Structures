//
// Created by Antonio Santana on 4/18/21.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 2: Reverse vector
Instructions
Write a program that recursively reverses a C++ vector (#include <vector>) of any data type and in-place.
("In place" means that the positions of the elements in the original vector passed to the function are modified.)

Demonstrate your program on:
A vector of int
A vector of std::string
 */

template<typename T>
void reverseVector(std::vector<T> &InputVector, int SIZE);

template<typename T>
void printVector(T const (&InputVector));

int main() {
    // TEST AN ARRAY OF INTS
    std::vector<int> numbers {1, 5, 6, 7, 10};
    // TODO
    printVector(numbers);
    reverseVector(numbers, numbers.size()-1);
    printVector(numbers);

    // TEST AN ARRAY OF STRINGS
    std::vector<std::string> strings {"cat", "dog", "bird", "cow", "frog", "horse"};
    // TODO
    //reverseVector(strings, numbers.size()-1);
    printVector(strings);

    return 0;
}


template<typename T>
void reverseVector(std::vector<T> &InputVector, int SIZE)
{
    if (SIZE <= 1){
        return ;
    } else {
        int temp;
        int i = 0;
        temp = InputVector[i];
        InputVector[i] = InputVector[SIZE-1];
        InputVector[SIZE-1] = temp;
        reverseVector(InputVector, SIZE-2);
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



/* First attempt
 *oid reverseArray(std::vector<int> &InputVector, int SIZE);

template <class T>
void reverseVector(std::vector<T> &InputVector, int startIndex, int endIndex);

template<typename T, size_t n>
void printArray(T const(& arr)[n]);

template<typename T>
void printVector(T const (&InputVector));

int main() {
    // TEST AN ARRAY OF INTS
    std::vector<int> numbers {1, 5, 6, 7, 10};

    cout << "vector contents BEFORE: ";
    printVector(numbers);
    reverseArray(numbers, numbers.size());
    cout << "\nvector contents AFTER: ";
    printVector(numbers);



    // TODO TEST AN ARRAY OF STRINGS
    std::vector<std::string> strings {"cat", "dog", "bird", "cow", "frog", "horse"};

    cout << "\nvector contents BEFORE: ";
    printVector(strings);
    int endIndex = (strings.size()-1);
    reverseVector(strings, 0, endIndex);
    cout << "\nvector contents AFTER: ";
    printVector(strings);

    return 0;
}



// Pass vector by reference.
void reverseArray(std::vector<int> &InputVector, int SIZE){
    if (SIZE <= 1){
        return ;
    } else {
        int temp;
        int i = 0;
        temp = InputVector[i];
        InputVector[i] = InputVector[SIZE-1];
        InputVector[SIZE-1] = temp;
        reverseArray(&InputVector[1], SIZE-2);
    }
}

// Pass vector by reference.
template <class T>
void reverseVector(std::vector<T> &InputVector, int startIndex, int endIndex){
//void reverseArray(std::vector<string> &InputVector, int SIZE){
    if (startIndex <= endIndex){
        return ;
    } else {
        int temp = 0;
        InputVector[startIndex];
        cout << InputVector[startIndex];
        InputVector[startIndex] = InputVector[endIndex-1];
        cout << InputVector[endIndex-1];
        cout << InputVector[startIndex];
        InputVector[endIndex-1] = temp;
        cout << InputVector[endIndex-1];
        reverseVector(InputVector, 1, (endIndex-2));
    }
}

template<typename T, size_t n>
void printArray(T const(& arr)[n])
{
    for (size_t i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
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
}

 */
