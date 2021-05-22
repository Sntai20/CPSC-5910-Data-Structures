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

void hW7Tester();
bool fileExists(string userInput);
list<string> preProcess(string &inputFilePath);

int main() {
    cout << "HW7 tester" << std::endl << "============" << std::endl;
    hW7Tester();

    return 0;
}

bool fileExists(string userInput)
{
    ifstream ifile;
    ifile.open(userInput);
    if(ifile) { return true; }
    else return false;
}

list<string> preProcess(string &inputFilePath)
{
    string line;
    ifstream inputFile;
    list<string> wordsList;
    list<string>::iterator myPosition = wordsList.begin();

    inputFile.open(inputFilePath);    // watch for the working directory when you run the project
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            string word;
            if (line.length() >= 1){
                for (long unsigned int i = 0; i < line.length(); i++)
                {
                    char c = tolower(line[i]);
                    if (isalpha(c) || isalnum(c))  word += c;
                }
                wordsList.insert(myPosition, word);
            }
        }
    }
    inputFile.close();
    return wordsList;
}

void hW7Tester() {
    bool foundException = false;
    try
    {
        string userInput = "int.txt";
        string inputFilePath;

        // Inform the user if the input was a palindrome
        cout << "Please input a file path to a file containing integers:  ";
        cin >> userInput;

        if (fileExists(userInput) && userInput.length() >= 1)
        {
            inputFilePath = userInput;
            list<string> wordsList = preProcess(inputFilePath);
            for (auto word : wordsList)
            {
                cout << word;
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

