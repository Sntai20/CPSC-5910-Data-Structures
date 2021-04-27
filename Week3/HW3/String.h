//
// Created by Antonio Santana on 4/25/21.
//
#ifndef LECTURECODE_STRING_H
#define LECTURECODE_STRING_H
#include "LinkedList.h"
#include "Node.h"
#include <stdexcept>
#include <iostream>
#include <assert.h>

using namespace std;

// TODO: Implement
class String
{
private:
    LinkedList<char> myList ;
    Node<char>* headPtr; // Pointer to first node in the chain;

public:
    String(); // Default Constructor
    //String<ItemType>(const char aList); // A constructor that takes a char
    String(const std::string aString); // A constructor that takes a std::string


    void append(char); // A toString method that returns a std::string.
    void append(const std::string&); // A toString method that returns a std::string.
    std::string toString() const; // A toString method that returns a std::string.
    std::string reverseStr() const; // A reverse method that reverses the String.
    String reverse() const; // A reverse method that reverses the String.
};
#endif //LECTURECODE_STRING_H
