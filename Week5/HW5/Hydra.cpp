//
// Created by Antonio Santana on 5/10/21.
//
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Timer.h"

using namespace std;

/*
 * The hydraTester prompts the user to enter a starting string. To make hydra, the string
 * is then stored in a list one character at a time. While Hydra has heads, the program counts
 * the number of heads that the hero ends up cutting off to defeat.
 */
void hydraTester()
{
    LinkedList<string>* hydra = new LinkedList<string>();
    cout << "Enter a starting string to represents Hydra, a monster with many heads" << endl;
    string startingString;
    cin >> startingString;

    hydra->insert(1, startingString); // O(n)
    int count = 0;

    cout << "How fast can the Hero defeat the Hydra monster: "
                    << hydra->getEntry(1) << "?" << endl; // O(n)

    while (!(hydra->isEmpty()))
    {
        string hydraHeads = hydra->getEntry(1); // O(n)
        hydra->remove(1); // O(n)

        cout <<  hydraHeads;
        count ++;
        if (hydraHeads.length() > 1)
        {
            string smallerHydraHead = hydraHeads.substr(1, hydraHeads.length() - 1);
            hydra->insert(1, smallerHydraHead);
            hydra->insert(1, smallerHydraHead);
        }
    } // O(n)

    cout << "\nTo defeat the Hydra Monster, the hero cut off " << count << " heads " ;
}

int main() {
    cout << "Hydra tester" << std::endl << "============" << std::endl;
    Timer hydraTimer ("hydraTimer");
    hydraTester();

    return 0;
}
