//
// Created by Antonio Santana on 4/18/21.
//
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <list>
using namespace std;

#include "IO.h"

/*
 * To pre-process the string before starting the recursive test this helper method reads a file, then use
 * tolower and isspace to store the normalized strings in a list.
 *
 * Your program must use recursion to perform the palindrome test
 * Your program must not be case-sensitive to user input
 * Your program must ignore any whitespace that the user enters (but punctuation is considered)
 * You might want to consider adding a helper function with different parameters than the ones required above
*/

std::list<string> IO::ProcessFile(const std::string &inputFilePath){
    std::list<string> wordList;
    std::list<string>::iterator myPosition = wordList.begin();

    ifstream inputFile;
    inputFile.open(inputFilePath, ios::in);
    string line;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

        transform(line.begin(), line.end(), line.begin(),
                  [](unsigned char c){ return tolower(c); });

        wordList.insert(myPosition, line);
    }
    inputFile.close();
    return wordList;
}


