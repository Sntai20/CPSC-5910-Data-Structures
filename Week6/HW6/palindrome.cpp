/*
 * Created by Antonio Santana on 5/17/21.
 *
 * Problem 1: Palindrome
 * /Users/antonio/repo/CPSC-5910-Data-Structures/Week2/HW2/morewords.txt
 * Single Word Palindromes
 * Multiple Word Palindromes
 * Number Palindromes
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <list>

using namespace std;

bool fileExists(string userInput);
bool isPalindrome(string word);
bool isPalindrome_(string word);
bool isPalindrome_(string word, int low, int high);
list<string> preProcess(string &inputFilePath);
void isPalindromeTester();

int main()
{
    // TODO clean up comments
    // TODO test exception handling
    cout << "Recursively and iteratively testing if a word is a Palindrome.\n" << endl;

    isPalindromeTester();
    cout << "\nAll done testing!" << endl;
    return 0;
}

bool fileExists(string userInput)
{
    ifstream ifile;
    ifile.open(userInput);
    if(ifile) { return true; }
    else return false;
}

bool isPalindrome_(string word)
{
    bool palindrome = true;

    for (long unsigned int i = 0 ; i < (word.length()-1/2) ; i++)
    {
        if (word[i] != word[(word.length()-1)-i])
        {
            palindrome = false;
            i = word.length() + 1;
        }
    }
    return palindrome;
}

bool isPalindrome_(string word, int low, int high)
{
    // base case
    if (low >= high)
    {
        return true;
    }
    if (word[low] != word[high])
    {
        return false;
    }

    return isPalindrome_(word, low + 1, high - 1);
}

bool isPalindrome(string word)
{
    bool palindrome = true;
    bool palindromeIterative, palindromeRecursive;

    palindromeIterative = isPalindrome_(word);
    palindromeRecursive = isPalindrome_(word, 0, word.length() - 1);

    if(palindromeIterative == 1 && palindromeRecursive == 1 ){
        return palindrome;
    } else return false;
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

void isPalindromeTester()
{
    bool foundException = false;
    try
    {
        string userInput;
        string inputFilePath;

        // Inform the user if the input was a palindrome
        cout << "Please input a palindrome or a file path to a file containing palindromes: ";
        cin >> userInput;

        if (fileExists(userInput) && userInput.length() >= 1)
        {
            inputFilePath = userInput;
            list<string> wordsList = preProcess(inputFilePath);
            for (auto word : wordsList) {
                if (isPalindrome(word) == true) {
                    // Check to see if the word is a palindrome.
                    cout << "\nisPalindrome(" << word << "); return: " <<
                         isPalindrome(word) << " should be 1 (true)" << endl;
                }
                if (isPalindrome(word) == false) {
                    // Check to see if the word is a palindrome.
                    cout << "\nisPalindrome(" << word << "); return: " <<
                         isPalindrome(word) << " should be 0 (false)" << endl;
                }
            }
            return;
        } else {
            if (!fileExists(userInput) && userInput.length() >= 1)
            {
                string word = userInput;
                if(isPalindrome(word) == true)
                {
                    // Check to see if the word is a palindrome.
                    cout << "\nisPalindrome(" << word << "); return: " <<
                         isPalindrome(word) << " should be 1 (true)" << endl;
                }
                if(isPalindrome(word) == false)
                {
                    // Check to see if the word is a palindrome.
                    cout << "\nisPalindrome(" << word << "); return: " <<
                         isPalindrome(word) << " should be 0 (false)" << endl;
                }
                return;
            }
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
