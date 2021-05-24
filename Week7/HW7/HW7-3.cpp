/*
 * Created by Antonio Santana on 5/21/2021.
 *
 * Problem 3: Write a program that: Prompts the user to enter an integer n, Creates an array of
 * random integers of size n where all values are between 1 and 1000 inclusive. Sort this array
 * in O(n) time. Hint: Research "sort in linear time" or "insertionSort in O(n) time" on the Internet.
 * Print the sorted array to the console. Your program should be fully contained in a file
 * called HW7-3.cpp and compile with the standard command-line flags.
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
            wordsList.sort();
            for (auto word : wordsList)
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

*/

/*
 * vector<int>* numbers;
        if (!inFile) {
            throw std::runtime_error("invalid input!");
        }
        cout << "** TEST INSERT**" << endl << "Inserting in this order: ";
        string line;

        vector<int>::iterator myPosition = numbers->begin();
        while (getline(inFile, line)) {
            stringstream ss(line);
            int n;
            ss >> n;
            cout << n << " ";
            numbers->insert(myPosition, n);
        }

        cout << endl;
        auto start = std::chrono::high_resolution_clock::now();

//        mergeSort(numbers, 0, SIZE - 1);
        auto stop = std::chrono::high_resolution_clock::now();

        for (auto number : *numbers)
        {
            cout << number << endl;
        }

 */