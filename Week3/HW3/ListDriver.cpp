//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

const int ITEM_COUNT = 6;

void listInterfaceTester(ListInterface<std::string>* listPtr)
{
    std::string data[] = {"one", "two", "three", "four", "five", "six"};

    // isEmpty method
    std::cout << "isEmpty: returns " << listPtr->isEmpty()
              << "; should be 1 (true)" << std::endl;

    // insert and getEntry methods
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
    cout << endl;

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

    // Contains method false
    cout << "contains(\"seven\"): returns " <<
         listPtr->contains("seven") << " should be 0 (false)" << endl;

    // ContainsRecursive method
    cout << "containsRecursive(\"one\"): returns " << listPtr->containsRecursive("one") << " should be 1 (true)" << endl;
    //listPtr->containsRecursive("one");

    cout << endl;
}

int main()
{
    ListInterface<std::string>* listPtr = new LinkedList<std::string>();

    cout << "Testing the LinkedList-based ListInterface:" << endl;
    listInterfaceTester(listPtr);
    cout << "All done testing the LinkedList-based ListInterface!" << endl;

    delete listPtr;

    // TODO: Demonstrate assignment operator here.

    return 0;
}  // end main
