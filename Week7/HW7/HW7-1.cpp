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
#include <bits/stdc++.h>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib>
using namespace std;
int main()
{
    string filename;
    ifstream input_file; //instance for a file
    int num;
    //read file name from user
    cout<<"Enter file name : ";
    cin>>filename;
    input_file.open(filename); // open file
    if(!input_file) { //unable to open
        cerr << "File unable to open " << endl;
        exit(1);
    }
    input_file >> num;
    int len=0;
    int arr[100];
    while ( !input_file.eof() ) { // reading until reach  end-of-file
        arr[len++]=num; //place num in array
        input_file>> num;
    }
    arr[len++]=num;
    input_file.close();
    sort(arr, arr + len,greater<int>()); //sort an array in descending order
    int k;

    cout<<"Enter an integer K : ";
    cin>>k; //read k
    //print largest
    cout<<"The "<<k<<" largest element is : "<<arr[k-1];
    return 0;
}

/*
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
*/

/*
 * #include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>
​
​
using namespace std;
​
// Method to determine if line from input file is empty or contains only whitespace. Accepts a reference
// to a string and returns true if line is empty or contains only whitespace, else returns false.
bool isEmptyOrWhiteSpace(const std::string& line) {
    if (line.empty()) {
        return true;
    }
    for (unsigned long i = 0; i < line.size(); i++ ) {
        if (!isspace(line[i])) {
            return false;
        }
    }
    return true;
}
​
// Method to process the file inputted by user. Accepts an input file stream variable and a vector
// to store the integers in the file. Processes the file line by line. If a line contains an integer,
// the integer is added to the vector.
void processFile (ifstream& inFile, vector<int>& vec) {
    string line;
    while (getline(inFile, line)) {
​
        // Process line if it isn't empty or contains only whitespaces.
           if (!isEmptyOrWhiteSpace(line)) {
                istringstream s(line);
                // Accepts long integer from stream.
                signed long int n;
                s >> n;
​
                // Check that the state of the stream is good. If the stream contained an integer that variable n
                // was able to accept, the state of the stream should be good.
                if (s.good()) {
                    cout << n << "\n";
​
                    // Add integer to vector.
                    vec.push_back(n);
​
                    // Clears any remaining characters from the stream.
                    s.ignore(numeric_limits<streamsize>::max(), '\n');
                }
​
                // If the state of stream is not good, clear the stream.
                else {
                    cout << "oops! \n";
                    // Clears the stream.
                    s.ignore(numeric_limits<streamsize>::max(), '\n');
                }
           }
    }
}
​
// Function to merge the two halves vector left and vector right of the vector vec.
void merge (vector<int>& vec, vector<int>& left, vector<int>& right) {
    // Create iterators for input vectors
    vector<int>::iterator v = vec.begin();
    vector<int>::iterator l = left.begin();
    vector<int>::iterator r = right.begin();
​
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
​
    // Copy remaining elements of vector right, if there are any
    while (r != right.end()) {
        *v = *r;
        r++;
        v++;
    }
}
​
// Function to merge sort a vector of integers. Accepts a reference to the vector.
void mergeSort (vector<int> &vec) {
    if (vec.size() == 1) return;
    else {
​
        // Declare temp vectors
        vector<int> left;
        vector<int> right;
​
        int mid = (vec.size() + 1) / 2;
​
        // Copy contents of input vector to temp vectors
        for (int i=0; i < mid; i++){
            left.push_back(vec[i]);
        }
​
        for (int i = mid; i < (int)vec.size(); i++) {
            right.push_back(vec[i]);
        }
​
        mergeSort(left);
        mergeSort(right);
        merge(vec, left, right);
​
    }
}
​
int main() {
​
    // Vector to hold integers from file.
    vector<int> vec;
​
    // Accept user input for file name.
    cout << "Enter file name." << endl;
    string fileName;
    cin >> fileName;
    ifstream inFile;
    inFile.open(fileName);
​
    // If file is able to open, process file. Else tell user file could not be opened and terminate program.
    if (inFile.is_open()) {
        processFile(inFile, vec);
​
        // If integers were processed from file and added to the vector, prompt user to enter an integer k.
        // Else tell user no integers were extracted from file.
        if (vec.size() > 0) {
            cout << "Enter a positive integer k. Program will print the kth largest integer in file." << endl;
            int k;
            cin >> k;
​
            // If the user enters a positive integer for k, evaluate k. Else print message telling user that an input
            // error occurred.
            if (!cin.fail() && k > 0) {
                // If k is less than or equal to the size of the vector, sort vector and print kth largest integer.
                // Else print error message telling user k is greater than the total number of integers processed
                // from the file.
                if (k <= int(vec.size())) {
​
                    // Print message to user to let them know what value will be processed as k.
                    cout << "Program will process " << k << " as k." << endl;
​
                    // Sort the vector in ascending order using the mergeSort function.
                    mergeSort(vec);
​
                    // Print the kth largest integer in then file.
                    cout << "The " << k << "th largest integer in the file is: " << vec[vec.size() - k];
                } else {
                    cout << "Error: The integer you entered for k is greater than the total number of integers "
                            "processed from the file." << endl;
                }
            }
            else {
                cout << "Input error. A positive integer must be entered." << endl;
            }
        }
        else {
            cout << "No integers were extracted from input file. Please check file and try again." << endl;
        }
    }
    else {
        cout << "File could not be opened. Program terminating." << endl;
    }
}
 */