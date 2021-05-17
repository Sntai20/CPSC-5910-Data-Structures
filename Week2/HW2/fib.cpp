/*
 * Created by Antonio Santana on 5/17/21.
 *
 * Problem 3: Fibonacci Tester
 */
#include <iostream>
#include <vector>
//#include<stdio.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fibIterative(unsigned long num);
void fibRecursive(unsigned long num);
long fibRecursive_(unsigned long num);
void fibRecursiveBetter(unsigned long num);

// ANSWER 1 - DID fibRecursive(45) RUN TO COMPLETION ON YOUR SYSTEM, AND IF NOT, HOW LARGE A NUMBER DID YOU TEST?
// ANSWER 2 - TIME FOR fibIterative(45) ON YOUR SYSTEM = 31 microseconds
// ANSWER 3 - TIME FOR fibRecursive(45) ON YOUR SYSTEM = ?????
// ANSWER 3 - TIME FOR fibRecursiveBetter(45) ON YOUR SYSTEM = 22 microseconds
int main() {
    // TODO demonstration up to fib(45)
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function
    fibIterative(45);
    fibRecursive(45);
    //fibRecursiveBetter(45);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}

// Fibonacci Series using Space Optimized Method
void fibIterative(unsigned long num)
{
    // TODO
    int a = 0, b = 1, c;
    if( num == 0)
    {
        cout << a;
    }
    for ( unsigned long i = 2; i <= num; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << b;
}

void fibRecursive(unsigned long num)
{
    fibRecursive_(num);

}

long fibRecursive_(unsigned long num)
{
    // TODO
    if (num <= 2){
        return 1;
    } else {
        cout << "return fibRecursive"<< (num - 1) << "+" << "fibRecursive" << (num - 2) << endl;
        return fibRecursive_(num - 1) + fibRecursive_(num - 2);
    } // num > 2, so num - 1 > 0 and n - 2 > 0
}

void fibRecursiveBetter(unsigned long num)
{
    // TODO
    int a = 0, b = 1, c;
    if( num == 0)
        cout << a;
    for( unsigned long i = 2; i <= num; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << b;
}