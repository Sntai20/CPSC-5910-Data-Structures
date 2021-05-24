/*
 * Created by Antonio Santana on 5/24/2021.
 *
 * Problem 3: Write a program that: Prompts the user to enter an integer n, Creates an array of
 * random integers of size n where all values are between 1 and 1000 inclusive. Sort this array
 * in O(n) time. Hint: Research "sort in linear time" or "insertionSort in O(n) time" on the Internet.
 * Print the sorted array to the console. Your program should be fully contained in a file
 * called HW7-3.cpp and compile with the standard command-line flags.
 */

#include <iostream>
#include <string>
#include <time.h>
// method to print an array. Accepts a pointer to the array and the size of the array as input parameters.
void printArray(int* data, int size)
{
    for (int i = 0; i< size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

// Method to sort array in linear time. Accepts pointer to array data and the size of the array as input parameters.
void countingSort (int *data, int size)
{
    int* output = new int [size + 1];
    // The assignment specifications state that all values in the array are between 1 and 1000 inclusive.
    // Thus, we know that the minimum possible value in the array is 1 and the maximum possible value in
    // the array is 1000. If we didn't have a defined range of possible values for the array, we'd use
    // #inlcude<climits> and set the minimum value to INT_MIN and the maximum value to INT_MAX.
    int minRange = 1;
    int maxRange = 1000;
    // Iterate over the array contents to set minRange and maxRange to the actual minimum and maximum values
    // in the array.
    for (int i = 0; i < size; i++)
    {
        minRange = std::min(minRange, data[i]);
        maxRange = std::max(maxRange, data[i]);
    }
    int range = maxRange - minRange +1;
    // Initializing array counts of size range and initializing all values to 0.
    int* counts = new int[range];
    for (int i = 0; i < range; i++)
    {
        counts[i] =0;
    }
    // Store count of each element in the data array.
    for (int i = 0; i < size; i++)
    {
        counts[data[i] - minRange]++;
    }
    // Change count[i] so that count[i] now contains actual position of this integer in the output array.
    for(int i = 1; i < range; i++ )
    {
        counts[i] += counts[i-1];
    }
    // Build output integer array
    for (int i = size - 1; i >= 0; i--)
    {
        output[counts[data[i] - minRange] -1] = data[i];
        counts[data[i] - minRange]--;
    }
    // Copy the output array to array data
    for (int i=0; i < size; i++)
    {
        data[i] = output[i];
    }
    delete[] output;
    delete[] counts;
}
int main() {
    // Initialize random seed to the current time so that the rand function generates
    // different random numbers every time the program is run.
    srand (time(NULL));
    int n;
    std::cout << "This program creates an array of size n of randomly generated integers between 1 and 1000.\n"
                 "Please enter the integer n for the size of the array." << std::endl;
    std::cin >> n;
    // If the user enters an integer for n, tell user what integer the program will process as n
    // create an array of size n of randomly generated integers. Else print message telling user
    // that input error occurred.
    if (!std::cin.fail() && n > 0)
    {
        std::cout << "Program will process " << n << " as n. Original unsorted array: " << std::endl;
        int* data = new int[n];
        for (int i = 0; i < n; i++)
        {
            data[i] = rand() % 1000 + 1;
        }
        printArray(data, n);
        countingSort(data, n);
        std::cout << "Sorted array:" << std::endl;
        printArray (data, n);
        delete[] data;
    }
    else
    {
        std::cout << "Input error. A positive integer must be entered." << std::endl;
    }
}