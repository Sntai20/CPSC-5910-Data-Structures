#include <iostream>
#include <string>
#include "Calculator.h"
#include "CalculatorIO.h"

void testCalc(std::string desc, double expected, double actual) {
    if (expected == actual) {
        std::cout << "PASS: " << desc << std::endl;
    } else {
        std::cerr << "FAIL: " << desc << "; expected: " << expected << ", actual " << actual << std::endl;
    }
}

// Driver program that tests Calculator and CalculatorIO.
// Your code MUST pass these tests.
// But note that we can and will run other tests when grading to ensure that your code meets the requirements.
int main() {
    Calculator calc;
    testCalc("basic add", 5, calc.Add(3, 2));
    testCalc("basic sub", 1, calc.Subtract(3, 2));
    testCalc("basic mult", 6, calc.Multiply(3, 2));
    testCalc("basic div", 1.5, calc.Divide(3, 2));
/*
    CalculatorIO io;
    std::cout << "Calculate something that calculates to 5" << std::endl;
    testCalc("basic calc to 5 interactive", 5, io.CalculateInteractive());

    std::cout << "Enter a string instead of a number" << std::endl;
    bool caughtException = false;
    try {
        io.CalculateInteractive();
    } catch (const std::invalid_argument& err) {
        caughtException = (std::string(err.what()) == "first number invalid");
    }
    if (caughtException) {
        std::cout << "PASS: invalid number" << std::endl;
    } else {
        std::cerr << "FAIL: invalid number" << std::endl;
    }

   // io.CalculateFile("input.txt", "output.txt");
*/
    return 0;
}
