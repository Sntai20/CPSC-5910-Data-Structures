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

template<class ItemType>
void quickSort(ItemType theArray[], int first, int last);
template<class ItemType>
int partition(ItemType theArray[], int low, int high);
template<class ItemType>
void insertionSort(ItemType theArray[], int n);
bool fileExists(string userInput);

const int MIN_SIZE = 3;
const int RANGE = 1000;
const long SIZE = 10000;

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

        // Prints the k'th largest integer in the file.
        cout << "HW7 tester" << endl << "============" << endl;

        // Create a test file
        srand(7);

        int* data = new int[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            data[i] = rand() % RANGE;
        }

        std::ofstream myfile;
        myfile.open ("testints.txt");
        for (int i = 0; i < SIZE; i++)
        {
            myfile << data[i] << endl;
        }
        myfile.close();

        string inputFilePath = userInput;
        std::ifstream inFile;
        inFile.open(inputFilePath);

//        int* numbers = new int[SIZE];
        vector<int> numbers;
        if (!inFile) {
            throw std::runtime_error("invalid input!");
        }
        cout << "** TEST INSERT**" << endl << "Inserting in this order: ";
        string line;

        while (getline(inFile, line)) {
            stringstream ss(line);
            int n;
            ss >> n;
            cout << n << " ";
            numbers.push_back(n);
        }
        cout << endl;
        auto start = std::chrono::high_resolution_clock::now();

        quickSort(data, 0, SIZE - 1);

        auto stop = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < SIZE; i++) {
            std::cout << numbers[i] << ' ';
        }
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

/** Sorts an array into ascending order. Uses the quick sort with
    median-of-three pivot selection for arrays of at least MIN_SIZE
    entries, and uses the insertion sort for other arrays.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
template<class ItemType>
void quickSort(ItemType theArray[], int first, int last) {
    if ((last - first + 1) < MIN_SIZE) {
        insertionSort(theArray, last - first);
    } else {
        // Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(theArray, first, last);

        // Sort subarrays S1 and S2
        quickSort(theArray, first, pivotIndex - 1);
        quickSort(theArray, pivotIndex + 1, last);
    }  // end if
}  // end quickSort

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
template<class ItemType>
int partition(ItemType theArray[], int low, int high) {
    int middle = low + (high - low) / 2;

    if ((theArray[middle] >= theArray[low] && theArray[middle] <= theArray[high])
        || (theArray[middle] <= theArray[low] && theArray[middle] >= theArray[high]))
        std::swap(theArray[high], theArray[middle]);

    if ((theArray[high] >= theArray[low] && theArray[high] <= theArray[middle])
        || (theArray[high] <= theArray[low] && theArray[high] >= theArray[middle]))
        std::swap(theArray[low], theArray[high]);


    int pivot = theArray[low];
    int i = low - 1, j = high + 1;

    while (true) {
        do {
            i++;
        } while (theArray[i] < pivot);

        do {
            j--;
        } while (theArray[j] > pivot);

        if (i >= j)
            return j;

        std::swap(theArray[i], theArray[j]);
    }
}

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  theArray is sorted into ascending order; n is unchanged.
 @param theArray  The given array.
 @param n  The size of theArray. */
template<class ItemType>
void insertionSort(ItemType theArray[], int n)
{
    // unsorted = first index of the unsorted region,
    // loc = index of insertion in the sorted region,
    // nextItem = next item in the unsorted region.
    // Initially, sorted region is theArray[0],
    //            unsorted region is theArray[1..n−1].
    // In general, sorted region is theArray[0..unsorted−1],
    //             unsorted region theArray[unsorted..n−1]
    for (int unsorted = 1; unsorted < n; unsorted++)
    {
        // At this point, theArray[0..unsorted−1] is sorted.
        // Find the right position (loc) in theArray[0..unsorted]
        // for theArray[unsorted], which is the first entry in the
        // unsorted region; shift, if necessary, to make room
        ItemType nextItem = theArray[unsorted];
        int loc = unsorted;
        while ((loc > 0) && (theArray[loc - 1] > nextItem))
        {
            // Shift theArray[loc − 1] to the right
            theArray[loc] = theArray[loc - 1];
            loc--;
        }  // end while
        // At this point, theArray[loc] is where nextItem belongs

        theArray[loc] = nextItem; // Insert nextItem into sorted region
    }  // end for
}  // end insertionSort

bool fileExists(string userInput)
{
    ifstream ifile;
    ifile.open(userInput);
    if(ifile) { return true; }
    else return false;
}





//        if (fileExists(userInput) && userInput.length() >= 1)
//        {
//            inputFilePath = userInput;
//
////            vector<int> dataList = preProcess(inputFilePath);
//
//            ifstream inputFile;
////            int number;
//            inputFile.open(inputFilePath);
////            vector<int> numbers;
//            int* numbers = new int[SIZE];
//            for (int i = 0; i < SIZE; i++)
//            {
//                while(inputFile.peek() != EOF)
//                {
//                    inputFile >> numbers[i];
////                numbers.push_back(number);
////                    numbers[i] = number;
//
////                    cout << numbers[i];
//                }
//
//            }
//
//
//            inputFile.close();


//            vector<int> dataList = preProcess(inputFilePath);
