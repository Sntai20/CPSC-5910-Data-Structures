//
// Created by Antonio Santana on 4/18/21.
// This program checks if a word is a palindrome.
// INPUT: file, strings
// OUTPUT: Prints the result to the screen.
//
#include <iostream>
#include <string>
#include <list>
#include "IO.h"
using namespace std;

bool isPalindromeI(string word);
bool isPalindromeR(string word, int low, int high);

int main() {
    bool foundException = false;
    try
    {
        cout << "Please provide the file path to words.txt.\n";
        string userFilePath, filePath;
        char* pPath;
        pPath = getenv ("PATH");
        //if (pPath!=NULL)
            //printf ("The current path is: %s",pPath);

        //cin >> userFilePath;
        filePath = "words.txt";
        string fullPath =  pPath + filePath;
        cout << fullPath << endl << endl;
        cout << "Read lines from a file, remove whitespace, and convert to lowercase. \n";

        list<string> wordList = IO::ProcessFile(filePath);
        for (auto word : wordList)
        {
            isPalindromeI(word);
            isPalindromeR(word, 0, word.length() - 1);
        }
    }
    catch (std::invalid_argument& e)
    {
        foundException = true;
    }
    if (!foundException)
    {
        std::cerr << "\nDid not catch an invalid input" << std::endl;
    }
    return 0;
}

bool isPalindromeI(string word)
{
    std::string text = word;
    bool palindrome = true;

    for (long unsigned int i = 0; i < (text.length()-1/2); i++)
    {
        cout << text[i];
        if (text[i] != text[(text.length()-1)-i])
        {
            palindrome = false;
            i = text.length() + 1;
        }
    }
    if (palindrome)
    {
        cout << text << " This is a palindrome" << endl;
        return true;
    }
    else
    {
        //cout << text << " This is not a palindrome" << endl;
        return false;
    }
}

bool isPalindromeR(string word, int low, int high)
{
    // base case
    if (low >= high)
    {
        cout << word << " This is a palindrome" << endl;
        return true;
    }
    if (word[low] != word[high]) {
        return false;
    }

    return isPalindromeR(word, low + 1, high - 1);
}