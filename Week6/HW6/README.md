# HW2

While doing HW6 (redoing HW2) I learned that thorough testing is an important part of validating the developers assumptions. Getting a list of test cases and even looking up test data can really help. I changed a most of the code, but I mostly actually completed the assignment. Also turning in the assignment on time is usually the best way to demostrate how important the class is to you and your career.

## Problem 1: Palindrome
### Instructions 
Write a C++ program that based on any type of user input, informs the user if the input was a palindrome. Your program must include a method that accepts a string as an argument and returns a boolean whether or not that string is a valid palindrome.

```
bool isPalindrome(string text) {
    // TODO: Your implementation
}
```
The user must specify the file path for the data file; however, you can use the ```words.txt``` file included with the starter code for testing.

### Hints:

* Your program must use recursion to perform the palindrome test
* Your program must not be case-sensitive to user input
* Your program must ignore any whitespace that the user enters (but punctuation is considered)
* You might want to consider methods such as tolower 
* and isspace in the ```cctype>``` library (Links to an external site.)
* You might want to consider adding a helper method to pre-process the string before starting the recursive test
* You might want to consider adding a helper function with different parameters than the ones required above
  
### Notes:

The grader may use any file path, so please ask the user to enter a file name when coding this lab

## Problem 2: Reverse vector
### Instructions
Write a program that *recursively* reverses a C++ ```vector``` (```#include <vector>```) *of any data type* and *in-place*. ("In place" means that the positions of the elements in the original ```vector``` passed to the function are modified.)

Demonstrate your program on:
* A vector of ```int```
* A vector of ```std::string```

## Problem 3: Fibonacci Tester
The textbox discusses the Fibonacci sequence, as do many sources online. Write a program that:

* Prints the Fibonacci sequence up to 45 using **a recursive implementation**.
  * ```fibRecursive``` function.
* Prints the Fibonacci sequence up to 45 using **an iterative implementation**.
  * ```fibIterative``` function.
* Times the execution of each of these in milliseconds.
  * Put the example timings in source code comments where indicated.

Note that the recursive Fibonacci implementation does a lot of repetitive work in calculations.
* Come up with an alternative recursive implementation that eliminates duplicate computation.
  * ```fibRecursiveBetter``` function.

### Notes
* You may use helper methods if it, er, helps.
* You should NOT use global variables.

## Problem 4: Coins
Consider all of the different ways of making change for one U.S. dollar ($1) using combinations of pennies, nickels, dimes, quarters, and half-dollars. (No $1 coins in this exercise.)

* Write a program that calculates and prints the **total weight in pounds** of all the coins that would be used by all the possible combinations. (This is asking for a *single number*, not a number per combination.)
* Write a paragraph describing your approach and include it in a source code comment.
  * Some ideas to get you started?
    * What is the overall approach?
    * If recursive, what is the base case? What are the smaller subproblems?
* Your implementation must allow us to modify the amount from $1 to any other amount by changing a constant at the top of the file.

You can use the coin weights from the U.S. Mint here: https://www.usmint.gov/learn/coin-and-medal-programs/coin-specifications


## Submission
* Create a SINGLE folder file containing ONLY source code for all four problems:
  * ```.h``` files
  * ```.cpp``` files
  * any ```.txt``` files for testing
  * ```CMakeLists.txt```
* Zip this folder.
* Double-check that it only contains files of the type listed just above ^^.
* And submit it to HW2 in Canvas.

If you submit any additional files, including:
  * Executable, binary, and output files, including everything in ```cmake-build-debug```
  * CLion files (i.e. ```.idea```)

  you *will* lose points.

If your code does not compile using the following command lines:

```$ g++ palindrome.cpp -o HW2P1 -pedantic -Wall -Werror -std=c++11```

```$ g++ reversevec.cpp -o HW2P2 -pedantic -Wall -Werror -std=c++11```

```$ g++ fib.cpp -o HW2P3 -pedantic -Wall -Werror -std=c++11```

```$ g++ coinchange.cpp -o HW2P4 -pedantic -Wall -Werror -std=c++11```

you *will* lose points, up to and including receiving a 0 on the assignment.

Upload the zip file to the HW2 assignment in Canvas.
