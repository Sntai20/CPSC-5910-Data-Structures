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
 *
 * The time requirements for the algorithm is O(n*2^n). The number of operations consist of traversing
 * the list to read, add, and remove from the list. The hydraTester reads in the starting string to
 * make hydra, each add operation is O(n). Once the word is stored into a list the hydraTester performs a
 * couple of operations inside of a loop. To simulate the head being cut off and growing two heads requires
 * the first letter of the string to be removed, while two add operations O(n^2) are performed to make two
 * copies of the string and add them into the list. The following output shows the algorithm growing exponentially
 * as the length of the strings increases from 13 to 31.
 *
 * Runtime	Length of Strings	Heads cut off	Starting Strings
 * 5153	    9	                   511	        stringwit
 * 7064	    13	                   8191	        stringwithaaa
 * 15251	16	                   65535	    stringwithaaabbb
 * 21573	19	                   524287	    stringwithaaabbbccc
 * 22003	22	                   4194303	    stringwithaaabbbcccddd
 * 32517	25	                   33554431	    stringwithaaabbbcccdddeee
 * 103836	28	                   268435455	stringwithaaabbbcccdddeeefff
 * 740088	31	                   2147483647	stringwithaaabbbcccdddeeefffggg
 *
 */

void hydraTester()
{
    LinkedList<string>* hydra = new LinkedList<string>();
    cout << "Enter a starting string to represent Hydra, a monster with many heads" << endl;
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
    } // O(n*2^n)

    cout << "\nTo defeat the Hydra Monster, the hero cut off " << count << " heads " ;
}

// question 2

bool hasEvens(int nums[], int size)
{
    for (auto i : nums)
    {
        if (i == 0)
            return 1;
        else if (i == 1)
            return 0;
        else if (i < 0)
            return hasEvens(-i);
        else return hasEvens(i - 2);
    }
}

int sum(LinkedList *list)
{
    assert(list!=NULL);
    Node *currentNode = list->head;
    int sum = 0;
    for (currentNode = currentNode->next ; currentNode !=NULL ; currentNode = currentNode -> next)
    {
        sum = sum + currentNode->data;
    }
    return sum;
}


int secretRecursion(int a, int b) {
    if (b <= 0) {
        return 0;
    }
    int c = secretRecursion(a, b-1);
    if (a % b == 0) {
        c += b;
    }
    return c;
}


int main() {
    //cout << "Hydra tester" << std::endl << "============" << std::endl;
    //Timer hydraTimer ("hydraTimer");
    //hydraTester();
    secretRecursion(14,4);



    return 0;
}
