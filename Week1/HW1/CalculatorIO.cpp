// TOOO: CalculatorIO implementation goes in this file.
#include <iostream>
#include "CalculatorIO.h"

// Reads calculations line by line from input file and writes the results line by line to the output file.
// If an error occurs on any given calculation, the output should include:
//  1. A description of the error.
//  2. An indication of what line number the error occurred on.
//  3. And the method should continue processing the rest of the lines in the file.
//
// Example input file:
// 7 * 8
// 24 / 4
//
// Example output file:
// 56
// 6
/* Uncomment to read a file
void CalculatorIO::CalculateFile(const std::string& inputFilePath, const std::string& outputFilePath){

}


double CalculatorIO::CalculateInteractive(){
    const double first = 3;
    const double second = 2;
    const char op = '+';

    //const char = '+';
    // Prompts the user for:
    // 1. First number.
    // 2. Operation (+, -, *, /)
    // 3. Second number.
    // In this order, and uses the Calculator to calculate and return the result.

    std::cout << "Enter the first number\n";
    std::cout << "3";
    //std::cin.get(firstNumber);
    std::cout << "Enter op code (+, -, *, /)\n";
    //std::cin >> op;
    std::cout << "Enter the second number";
    std::cout << "2";
    //std::cin >> second;

    double result = calc.Calc(first, second, op);
    return result;

}*/