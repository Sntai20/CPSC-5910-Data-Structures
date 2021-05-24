/*
 * Created by Antonio Santana on 5/24/2021.
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
#include<vector>
#include<string>
#include<fstream>
#include <sstream>

using namespace std;

template <typename T>
void display(vector<T> data);
bool fileExists(string filePath);
template<typename ItemType>
vector<ItemType> preProcess(string firstFileName);
template<typename ItemType>
void merge (vector<ItemType>& dataVector, vector<ItemType>& left, vector<ItemType>& right);
template<typename ItemType>
void mergeSort (vector<ItemType> &dataVector);
void displaykthLargestInteger(vector<int> &dataVector, int k);

int main()
{
    string firstFileName = "int.txt";
    int k = 9;

    //Prompt for file names
    cout << "Enter filename contain integers: ";
//    cin >> firstFileName;
    vector<int> values = preProcess<int>(firstFileName);

    cout << endl;
    // Display before Sort
    cout << "Values before Sort: ";
    display(values);

    // Call mergeSort
    mergeSort(values);

    cout << endl;
    displaykthLargestInteger(values, k);

    // Display after insertionSort
    cout << "\nValues after mergeSort: ";
    display(values);

    return 0;
}

// To merge the two halves vector left and vector right of the vector dataVector.
template <typename ItemType>
void merge (vector<ItemType>& dataVector, vector<ItemType>& left, vector<ItemType>& right) {
    // Create iterators for input vectors
    vector<int>::iterator v = dataVector.begin();
    vector<int>::iterator l = left.begin();
    vector<int>::iterator r = right.begin();

    while (l != left.end() && r != right.end()) {
        if (*l <= *r ){
            *v = *l;
            l++;
        }
        else {
            *v = *r;
            r++;
        }
        v++;
    }
    // Copy remaining elements of vector left, if there are any
    while (l != left.end()) {
        *v = *l;
        l++;
        v++;
    }

    // Copy remaining elements of vector right, if there are any
    while (r != right.end()) {
        *v = *r;
        r++;
        v++;
    }
}

// Function to merge sort a vector of integers. Accepts a reference to the vector.
template <typename ItemType>
void mergeSort (vector<ItemType> &dataVector) {
    if (dataVector.size() == 1) return;
    else {

        // Declare temp vectors
        vector<int> left;
        vector<int> right;

        int mid = (dataVector.size() + 1) / 2;

        // Copy contents of input vector to temp vectors
        for (int i=0; i < mid; i++){
            left.push_back(dataVector[i]);
        }

        for (int i = mid; i < (int)dataVector.size(); i++) {
            right.push_back(dataVector[i]);
        }

        mergeSort(left);
        mergeSort(right);
        merge(dataVector, left, right);

    }
}

// Display the data to the console.
template <typename ItemType>
void display(vector<ItemType> data)
{
    for (unsigned int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
}

// Read the users value as k, find and display the kth largest value in the vector.
void displaykthLargestInteger(vector<int> &dataVector, int k)
{
    // Print the kth largest integer in then file.
    cout << "The " << k << "th largest integer in the file is: "
        << dataVector[dataVector.size() - k];
}

bool fileExists(string filePath)
{
    ifstream ifile;
    ifile.open(filePath);
    if(ifile) { return true; }
    else return false;
}

template<typename ItemType>
vector<ItemType> preProcess(string firstFileName)
{
    // File open error check
    if (!fileExists(firstFileName))
    {
        cout << "File not found\n";
        exit(0);
    }

    ifstream firstFileStreamIn(firstFileName);

    //Check for integer
    bool isInteger = true;
    string data;
    firstFileStreamIn >> data;
    for (long unsigned int i = 0; i < data.length(); i++)
    {
        if (!isdigit(data[i]))
        {
            isInteger = false;
            break;
        }
    }

    vector<int> values;
    //If integer read into a int vector
    if (isInteger)
    {
        int number;
        stringstream ss(data); // To grab the first value.
        ss >> number;
        values.push_back(number);
        while (firstFileStreamIn >> data) {
            stringstream ss1(data);
            ss1 >> number;
            values.push_back(number);
        }
        firstFileStreamIn.close();
    }
    return values;
}
