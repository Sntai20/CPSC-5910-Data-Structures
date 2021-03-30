# HW2

## Overview
You will be creating a simple calculator in C++ to get familiar with some basic C++ features, including:

* Console input and output
* File input and output
* String manipulation
* Exception handling
* Basic data types

## Getting Started
1. Download the starter code from Github.
1. Open the ```HW1``` directory in CLion
1. You should not add any new files to the project.
1. Implement the two classes ```Calculator``` and ```CalculatorIO```, whose requirements are specified in their respective header (.h) files.
1. If you do it correctly, you will make code in ```driver.cpp``` pass.
1. *You should consider writing additional tests, though, because driver.cpp is not sufficient to cover ALL requirements such as the various possible error cases.*

## Tips
You *may* have to do some research to complete this assignment, including:
* Reading and writing files line by line.
* Splitting a space-delimited string.
* Throwing and handling exceptions of specific types.
* Converting between different data types.

## Submission
Create a zip file containing ONLY source code:
  * ```.h``` files
  * ```.cpp``` files
  * any ```.txt``` files for testing
  * ```CMakeLists.txt```

If you submit any additional files, including:
  * Executable, binary, and output files, including everything in ```cmake-build-debug```
  * CLion files (i.e. ```.idea```)

  you *will* lose points.

If your code does not compile using the following command line:

```$ g++ Calculator.cpp CalculatorIO.cpp driver.cpp -o HW1 -pedantic -Wall -Werror -std=c++11```

you *will* lose points, up to and including receiving a 0 on the assignment.

Upload the zip file to the HW1 assignment in Canvas.
