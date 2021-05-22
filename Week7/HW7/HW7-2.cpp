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
        cout << "Please input a file path to a file containing integers: ";
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