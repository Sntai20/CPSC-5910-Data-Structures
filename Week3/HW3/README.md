# HW3

## Problem 1: Big Three
### Instructions
The ```LinkedList``` class discussed in the book and in class has a potential problem, which is that when it is copied via assignment or passing to a function, it uses the *default constructor* which is only a *shallow* copy. See also the mention at the bottom of page 281 in the textbox, "The remaining methods".

Fix this problem by implementing a *deep* copy via:
* A copy constructor.
* A copy assignment operator.

Along with the virtual destructor that is already there, these are known as the "Big Three" (https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming))

Many references online will help you if you get stuck.

Add a few lines of code to ```ListDriver.cpp``` that demonstrates your code.

Implement your solution directly in the HW3 starter code.

## Problem 2: contains
Implement "contains" functionality for LinkedList:

* ```contains``` returns true if the item is in the list, false otherwise, and is implemented non-recursively (i.e. with a looping construct).
* ```containsRecursive``` does the same thing, but with a recursive implementation. *Hint: You may consider using a helper method for the recursion*
* Add tests in ```ContainsDemo.cpp``` to fully demonstrate all of this functionality.

These are exercises 7 and 8 in the textbook (but only for LinkedList).

Implement your solution directly in the HW3 starter code.

## Problem 3: ```String``` class
Use ```LinkedList``` to implement your own ```String``` class. It should support:

* A constructor that takes a std::string.
* Appending to the end:
  * A char
  * A std::string
* A ```toString``` method that returns a std::string.
* A ```reverse``` method that reverses the ```String```.

### Tips
* You are allowed to leverage your solutions to Problems 1 and 2 if you want.
* You are allowed to add other public or private methods (*including* to ```LinkedList```)

Write a program that demonstrates this in a file with a ```main``` method called "StringDemo.cpp".

