/*
 * Created by Antonio Santana on 5/21/2021.
 *
 * Problem 1: Write a program that: Prompts the user for a filename where the file contains integers,
 * one per line with some number of optional blank lines. Prompts the user to enter an integer k.
 * Prints the k'th largest integer in the file. The program must run in at most O(n lg n) time,
 * where n is the number of integers in the file. The program must perform all reasonable error-checking
 * on inputs (i.e. we should not be able to make it crash).
 *
 * You may not use any C/C++ Standard Library sorting algorithms, but rather supply your own in the source code
 * (which can be based on code in the book or lecture materials). Your program should be fully contained in a
 * file called HW7-1.cpp and compile with the standard command-line flags.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <list>
#include <vector>
#include <chrono>
#include <sstream>

using namespace std;

const int MIN_SIZE = 3;
const int RANGE = 1000;
const long SIZE = 10000;

// Function to merge the two haves arr[l..m]
// and arr[m+1..r] of array arr[]
template <class ItemType>
void merge(ItemType arr[], int l, int m, int r) {
    int k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temp arrays
    int* L = new int[n1];
    int* R = new int[n2];
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    // Merge the temp arrays
    // back into arr[l..r]
    int i = 0;
    int j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements
    // of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements
    // of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted
template <class ItemType>
void mergeSort(ItemType arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2 but avoids
        // overflow for large l & h
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    bool foundException = false;
    try
    {
        string userInput;
        // Inform the user if the input was a palindrome
        cout << "Please input a file path to a file containing integers:  ";
        //cin >> userInput;
        userInput = "testints.txt";
        // Prompt the user to enter an integer k
        cout << "Please enter an integer k:  ";
        int k = 9;

        cout << "HW7 tester" << endl << "============" << endl;
        // Create a test file
        srand(7);
        int* data = new int[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            data[i] = rand() % RANGE;
        }

        cout << endl;
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(data, 0, SIZE - 1);
        auto stop = std::chrono::high_resolution_clock::now();
        cout << "Print in order: ";
        for (int i = 0; i < SIZE -1 ; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
        cout << "Print in reverse order: ";
        for (int i = SIZE -1 ; i >= 0; i--)
        {
            std::cout << data[i] << ' ';
        }
        std::cout << std::endl;

        cout << "Last Element should contain the largest integer : " << data[SIZE - 1] << endl;
        // Prints the k'th largest integer in the file.
        cout << "Element "  << (SIZE-k) << " : contains " << data[SIZE - k];
        std::cout << std::endl;
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << duration.count() << std::endl;
        delete[] data;
    }
    catch (invalid_argument& e)
    {
        foundException = true;
    }
    if (!foundException)
    {
        cerr << "\nDid not catch an invalid input in the tester" << endl;
    }
    return 0;
}