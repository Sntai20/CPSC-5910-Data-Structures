//
// Created by Antonio Santana on 4/25/21.
//
#include "LinkedList.h"
#include "String.h"
#include <iostream>
#include <string>

using namespace std;

const int ITEM_COUNT = 6;

void stringDemoTester(String* aString)
{
    cout << aString << endl;
    /*
    string data[] = {"one", "two", "three", "four", "five", "six"};


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

    // Replace method
    string removed = listPtr->replace(3, "foobar");
    cout << "replace(\"3\", \"foobar\"): Replaced position 3 which had " << removed << " with "
         << listPtr->getEntry(3) << endl;

    // getLength method
    cout << "getLength: returns: " << listPtr->getLength() << " should be 6" << endl;

    // getFrequencyOf method
    cout << "getFrequencyOf(\"six\"): returns " <<
         listPtr->getFrequencyOf("six") << " should be 1" << endl;

    // Contains method true
    cout << "contains(\"six\"): returns " <<
         listPtr->contains("six") << " should be 1 (true)" << endl;

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
*/
    cout << endl;
}

int main()
{
    String* aString = new String();

    // TODO: Test String methods here
    cout << "Testing the LinkedList-based StringDemo: \n" << endl;
    stringDemoTester(aString);
    cout << "All done testing the LinkedList-based StringDemo!" << endl;

    delete aString;

    return 0;
}  // end main

