//
// Created by Antonio Santana on 4/25/21.
//
#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

const int ITEM_COUNT = 6;

void linkedListTester(LinkedList<std::string>* listPtr)
{
    std::string data[] = {"one", "two", "three", "four", "five", "six"};

    // isEmpty method
    std::cout << "isEmpty: returns " << listPtr->isEmpty()
              << "; should be 1 (true)" << std::endl;

    // insert and getEntry methods
    cout << "Insert and getEntry methods";
    cout << endl;
    for (int i = 0; i < ITEM_COUNT; i++)
    {
        if (listPtr->insert(i + 1, data[i]))
        {
            try
            {
                std::cout << "Inserted " << listPtr->getEntry(i + 1)
                          << " at position " << (i + 1) << std::endl;
            }
            catch (std::invalid_argument& except)
            {
                std::cout << "Failed to get entry at position "
                          << (i + 1) << std::endl;
            }
        }
        else
            std::cout << "Cannot insert " << data[i] << " at position " << (i + 1)
                      << std::endl;
    }  // end for

    // Display the list
    cout << "\nThe items in the list are: " << endl;
    for (int i = 0; i < ITEM_COUNT; i++)
    {
        cout << listPtr->getEntry(i + 1) << ", ";
    }  // end for
    cout << "\n" << endl;

    // TODO: Test LinkedList.contains() here
    // Contains method true
    cout << "contains(\"six\"): returns " <<
         listPtr->contains("six") << " should be 1 (true)" << endl;

    // Contains method false
    cout << "contains(\"seven\"): returns " <<
         listPtr->contains("seven") << " should be 0 (false)" << endl;

    // TODO: Test LinkedList.containsRecursive() here
    // ContainsRecursive method
    cout << "containsRecursive(\"six\"): returns " <<
         listPtr->containsRecursive("six") << " should be 1 (true)" << endl;

    // Contains method false
    cout << "containsRecursive(\"seven\"): returns " <<
         listPtr->containsRecursive("seven") << " should be 0 (false)\n" << endl;

    // clear method
    cout << "clear(): should clear the list" << endl;
    listPtr->clear();

    // Display the list
    if (!listPtr->isEmpty())
    {
        cout << "\nThe items in the list are: " << endl;
        for (int i = 0; i < ITEM_COUNT; i++)
        {
            cout << listPtr->getEntry(i + 1) << ", ";
        }  // end for
    } else
        // isEmpty method
        std::cout << "isEmpty: returns " << listPtr->isEmpty()
                  << "; should be 1 (true)" << std::endl;

    cout << endl;
}

int main() {
    LinkedList<std::string>* listPtr = new LinkedList<std::string>();

    cout << "Testing the ContainsDemo with a LinkedList: \n" << endl;
    linkedListTester(listPtr);
    cout << "All done testing the LinkedList!" << endl;

    delete listPtr;
    return 0;
}
