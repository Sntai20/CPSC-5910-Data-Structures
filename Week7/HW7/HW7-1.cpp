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

using namespace std;

void hW7Tester(string userInput);
bool fileExists(string userInput);
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

template<typename ItemType>
list<ItemType> preProcess(ItemType &inputFilePath)
{
    ItemType line;
    ifstream inputFile;
    list<ItemType> dataList;

    list<string>::iterator myPosition = dataList.begin();

    inputFile.open(inputFilePath);

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            ItemType data;
            if (line.length() >= 1)
            {
                for (long unsigned int i = 0; i < line.length(); i++)
                {
                    if (isalpha(line[i]) || isalnum(line[i])) data += line[i];
                }

                dataList.insert(myPosition, data);
            }
        }
    }
    inputFile.close();
    return dataList;
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

            list<string> dataList = preProcess(inputFilePath);
            dataList.sort();

            for (auto word : dataList)
            {
                cout << word << endl;
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

