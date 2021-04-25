//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

const int ITEM_COUNT = 6;

int main()
{
    ListInterface<std::string>* listPtr = new LinkedList<std::string>();
    std::string data[] = {"one", "two", "three", "four", "five", "six"};
    std::cout << "isEmpty: returns " << listPtr->isEmpty()
            << "; should be 1 (true)" << std::endl;
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

    string removed = listPtr->replace(3, "foobar");
    cout << "replaced position 3 which had " << removed << " with "
        << listPtr->getEntry(3) << endl;

    delete listPtr;

    // TODO: Demonstrate assignment operator here.
    /* working on the contains method
    for (int i = 0; i < ITEM_COUNT; i++)
    {
        if (listPtr->getEntry(i) == listPtr->contains("foobar"))
        {
            try
            {
                std::cout << "List contains " << listPtr->getEntry(i)
                          << " at position " << (i) << std::endl;
            }
            catch (std::invalid_argument& except)
            {
                std::cout << "Failed to get entry at position "
                          << (i) << std::endl;
            }
        }
        else
            std::cout << "Cannot find " << data[i] << " at position " << (i + 1)
                      << std::endl;
    }  // end for
     listPtr->contains("foobar");
     working on the contains method
     */

    return 0;
}  // end main
