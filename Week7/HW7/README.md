# HW7

 1. Write a program that:

Prompts the user for a filename where the file contains integers, one per line with some number of optional blank lines.
Prompts the user to enter an integer k.
Prints the k'th largest integer in the file.
The program must run in at most O(n lg n) time, where n is the number of integers in the file.
The program must perform all reasonable error-checking on inputs (i.e. we should not be able to make it crash).
You may not use any C/C++ Standard Library sorting algorithms, but rather supply your own in the source code (which can be based on code in the book or lecture materials).
Your program should be fully contained in a file called HW7-1.cpp and compile with the standard command-line flags.


2. Write a program that:

Prompts the user to enter two filenames where the files both contain either all-integers (one per line) or all-(non-integer)-strings (one per line).
Detects whether it is working with integers or strings based on the first line of the first file (i.e. if it's an integer, do integer sorting, otherwise do string sorting).
Merges these two files into a single sorted output file called "output.txt".
You may not use any C/C++ Standard Library sorting algorithms, but rather supply your own in the source code (which can be based on code in the book or lecture materials).
You must use the same function for sorting integers and strings.
Hint: Consider a template function.
Include a descriptive paragraph (not bullet points, not line-oriented code comments) in a block comment in the source code that explains the runtime complexity of your solution.
It must be efficient to get full credit.
Your program should be fully contained in a file called HW7-2.cpp and compile with the standard command-line flags.


3. Write a program that:

Prompts the user to enter an integer n,
Creates an array of random integers of size n where all values are between 1 and 1000 inclusive.
Sort this array in O(n) time.
Hint: Research "sort in linear time" or "sort in O(n) time" on the Internet.
Print the sorted array to the console.
Your program should be fully contained in a file called HW7-3.cpp and compile with the standard command-line flags.
Submission

Copy the source files only into a directory named after your SU email, zip it, and submit it to this Canvas assignment.