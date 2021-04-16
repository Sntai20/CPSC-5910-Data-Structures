#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(std::string word) {
    // TODO
    std::string text = word;
    bool palindrome = true;

    for (long unsigned int i = 0; i < (text.length()-1/2); i++)
    {
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
        cout << text << " This is not a palindrome" << endl;
        return false;
    }
}

int main() {
    // TODO
    string text = "TACOCAT";
    isPalindrome(text);
    return 0;
}
