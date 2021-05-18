/*
 * Created by Antonio Santana on 5/17/21.
 *
 * Problem 3: Fibonacci Tester
 * Accepts an unsigned long number and prints the Fibonacci sequence up to that number
 * using an iterative implementation.
 *
 * ANSWER 1 - DID fibRecursive(45) RUN TO COMPLETION ON YOUR SYSTEM, AND IF NOT, HOW LARGE A NUMBER DID YOU TEST?
 * ANSWER 2 - TIME FOR fibIterative(45) ON YOUR SYSTEM = 31 microseconds
 * ANSWER 3 - TIME FOR fibRecursive(45) ON YOUR SYSTEM = ?????
 * ANSWER 3 - TIME FOR fibRecursiveBetter(45) ON YOUR SYSTEM = 22 microseconds
 */
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

void fibIterative(unsigned long num);
unsigned long getFibNumR (unsigned long num);
void fibRecursive(unsigned long num);
unsigned long getFibNumBetter (unsigned long num, unsigned long current, unsigned long previous);
void fibRecursiveBetter(unsigned long num);

int main()
{
    unsigned long num = 45;
    cout << "Using iterative implementation: \n" << "The Fibonacci sequence up to fib("
              << num << ") is: " << endl;

    // Starting fibIterative function
    auto startFibIterative = chrono::high_resolution_clock::now();
    fibIterative(num);
    auto stopFibIterative = chrono::high_resolution_clock::now();
    auto durationFibIterative = chrono::duration_cast<chrono::microseconds>(stopFibIterative - startFibIterative);
    cout << "The time required to execute the iterative function to print the "
              << "Fibonacci sequence up to 45 is " << durationFibIterative.count() << " microseconds. \n";


    // Starting fibRecursive function
    cout << "Using recursive implementation: \n" << "The Fibonacci sequence up to fib("
              << num << ") is: \n";
    auto startFibRecursive = chrono::high_resolution_clock::now();
    fibRecursive(num);
    auto stopFibRecursive = chrono::high_resolution_clock::now();
    auto durationFibRecursive = chrono::duration_cast<chrono::microseconds>(stopFibRecursive - startFibRecursive);
    cout << "The time required to execute the recursive function to print the "
              << "Fibonacci sequence up to 45 is " << durationFibRecursive.count() << " microseconds. \n";

    // Starting the fibRecursiveBetter function
    cout << "Using better recursive implementation: \n" << "The Fibonacci sequence up to fib("
              << num << ") is: \n";
    auto startFibRB = chrono::high_resolution_clock::now();
    fibRecursiveBetter(num);
    auto stopFibRB = chrono::high_resolution_clock::now();
    auto durationFibRB = chrono::duration_cast<chrono::microseconds>(stopFibRB - startFibRB);
    cout << "The time required to execute the better recursive function to print the "
              << "Fibonacci sequence up to 45 is " <<  durationFibRB.count() << " microseconds. \n";

    return 0;
}

void fibIterative(unsigned long num)
{
    unsigned long previous = 1;
    unsigned long current = 1;
    unsigned long fibNumber = 0;
    for (unsigned long i=0; i <= num; i++)
    {
        if (i == 0)
        {
             cout << fibNumber << endl;
        } else if ((i == 1) || (i == 2))
        {
            fibNumber = 1;
            cout << fibNumber << endl;
        } else
        {
            fibNumber = previous + current;
            previous = current;
            current = fibNumber;
            cout << fibNumber << endl;
        }
    }
}

// Helper function for fibRecursive. Accepts unsigned long number >0 for the Fibonacci sequence
// number and returns the value of unsigned long number at that position is the Fibonacci sequence.
unsigned long getFibNumR (unsigned long num)
{
    if ((num == 1) || (num == 2)) {
        return 1;
    } else {
        return getFibNumR(num - 1) + getFibNumR(num - 2);
    }
}

// Accepts an unsigned long number and prints the Fibonacci sequence up to that number
// using a recursive implementation.
void fibRecursive(unsigned long num)
{
    unsigned long fibNumber = 0;
    if (num == 0){
        cout << fibNumber << endl;
    } else
    {
        fibNumber = getFibNumR(num);
        fibRecursive(num - 1);
        cout << fibNumber << endl;
    }
}

/*
 * Helper function for fibRecursiveBetter. Accepts unsigned long number >0 for the Fibonacci sequence
 * number, the value of the number at the current position in the Fibonacci sequence, and the value
 * of the number at the previous position in the Fibonacci sequence. Returns the value of the
 * unsigned long number at the Fibonacci sequence number.
 */
unsigned long getFibNumBetter (unsigned long num, unsigned long current, unsigned long previous)
{
    if (num == 0) {
        return previous;
    }
    return getFibNumBetter(num -1, current + previous, current);
}

void fibRecursiveBetter(unsigned long num)
{
    unsigned long fibNumber = 0;
    if (num == 0)
    {
        cout << fibNumber << endl;
    } else
    {
        unsigned long previous = 0;
        unsigned long current = 1;
        fibNumber = getFibNumBetter(num, current, previous);
        fibRecursiveBetter(num - 1);
        cout << fibNumber << endl;
    }
}
