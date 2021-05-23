/*
 * Created by Antonio Santana on 5/21/2021.
 *
 * Problem 2: Write a program that: Prompts the user to enter two filenames where the files both
 * contain either all-integers (one per line) or all-(non-integer)-strings (one per line). Detects
 * whether it is working with integers or strings based on the first line of the first file
 * (i.e. if it's an integer, do integer sorting, otherwise do string sorting). Merges these two
 * files into a single sorted output file called "output.txt".
 *
 * You may not use any C/C++ Standard Library sorting algorithms, but rather supply your own in
 * the source code (which can be based on code in the book or lecture materials). You must use
 * the same function for sorting integers and strings. Hint: Consider a template function.
 *
 * Include a descriptive paragraph (not bullet points, not line-oriented code comments)
 * in a block comment in the source code that explains the runtime complexity of your
 * solution. It must be efficient to get full credit. Your program should be fully contained
 * in a file called HW7-2.cpp and compile with the standard command-line flags.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <list>
#include <vector>

using namespace std;

void hW7Tester(string userInput);
bool fileExists(string userInput);
//template<typename ItemType>
//vector<ItemType> preProcess(string &inputFilePath);
template<typename ItemType>
list<ItemType> preProcess(string &inputFilePath);

int main() {
    string userInput;

    // Inform the user if the input was a palindrome
    cout << "Please input a file path to a file containing integers:  ";
    //cin >> userInput;
    userInput = "testints.txt";

    // Prompt the user to enter an integer k
    cout << "Please enter an integer k:  ";

    // Prints the k'th largest integer in the file.
    cout << "HW7 tester" << endl << "============" << endl;
    hW7Tester(userInput);

    return 0;
}

bool fileExists(string userInput)
{
    ifstream ifile;
    ifile.open(userInput);
    if(ifile) { return true; }
    else return false;
}

//template<typename ItemType>
//vector<int> preProcess(ItemType &inputFilePath)
//{
//    ifstream inputFile;
//    int number;
//    inputFile.open(inputFilePath);
//    vector<int> numbers;
//
//    while(inputFile >> number)
//    {
//        numbers.push_back(number);
////                cout << "Added " << number << " to number vector. " << endl;
//    }
//    inputFile.close();
//    return numbers;
//}

template<typename ItemType>
list<int> preProcess(ItemType &inputFilePath)
{
    ifstream inputFile;
    int number = 0;
    inputFile.open(inputFilePath);
    list<int> numbers;

    while(inputFile >> number)
    {
        numbers.push_back(number);
    }

    inputFile.close();
    return numbers;
}

void hW7Tester(string userInput) {
    bool foundException = false;
    try
    {
        // Create a test file
        srand(7);

        const int RANGE = 1000;
        const long SIZE = 10000;
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

        string inputFilePath;
        if (fileExists(userInput) && userInput.length() >= 1)
        {
            inputFilePath = userInput;

//            vector<int> numbers = preProcess(inputFilePath);
            list<int> numbers = preProcess(inputFilePath);

            numbers.sort();
            for (auto num :  numbers)
            {
                cout << num << endl;
            }
            return;
        }
    }
    catch (invalid_argument& e)
    {
        foundException = true;
    }
    if (!foundException)
    {
        cerr << "\nDid not catch an invalid input" << endl;
    }

}