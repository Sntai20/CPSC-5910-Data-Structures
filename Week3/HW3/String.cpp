//
// Created by Antonio Santana on 4/25/21.
//
#include "LinkedList.h"
#include "String.h"
#include <stdexcept>
#include <iostream>
#include <assert.h>

//using namespace std;

String::String() {
} // end default constructor

//String<>::String() : headPtr(nullptr), itemCount(0) {
//} // end default constructor

String::String(const std::string aString) {
    for (char i : aString) {
        myList.append(i);
    }
}

std::string String::toString() const {
    std::string returnMe;

    for (int i = 0; i < myList.getLength(); i++) {
        returnMe.push_back(myList.getEntry(i));
    }

    return returnMe;
}

std::string String::reverseStr() const {
    std::string returnMe;

    for (int i = myList.getLength(); i >= 0; i--) {
        returnMe.push_back(myList.getEntry(i));
    }

    return returnMe;
}

void String::append(const char aChar) {
    return myList.append(aChar);
}

void String::append(const std::string& aString) {
    for (char i : aString) {
        myList.append(i);
    }
}

String String::reverse() const {
    std::string myString = reverseStr();

    return String(myString);
}
