// TOOO: Exception handling CalculatorIO implementation.
#include <iostream>
#include <fstream>
#include "CalculatorIO.h"
#include <sstream>
using namespace std;

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
void CalculatorIO::CalculateFile(const std::string& inputFilePath, const std::string& outputFilePath){

    string operand;
    ifstream inputFile;
    ofstream outputFile;
    double firstNumber, secondNumber, results;

    // Open input and output files
    inputFile.open(inputFilePath, ios::in);
    outputFile.open(outputFilePath, ios::out);

    string str;
    // loop to write file to the string
    while (getline(inputFile, str))
    {
        // TOOO: Parse strings. Reference Lecture code
        // To print to the screen use std::out
        istringstream iss(str);
        iss >> firstNumber >> operand >> secondNumber;

        if (operand == "*")
        {
            results = calc.Multiply(firstNumber, secondNumber);
        }
        else if (operand == "+")
        {
            results = calc.Add(firstNumber, secondNumber);
        }
        else if (operand == "-")
        {
            results = calc.Subtract(firstNumber, secondNumber);
        }
        else if (operand == "/")
        {
            results = calc.Divide(firstNumber, secondNumber);
        }

        outputFile << results << endl;
    }
}

// Prompts the user for first number.
// 2. Operation (+, -, *, /)
// 3. Second number.
// In this order, and uses the Calculator to calculate and return the result.
//Does the calculator operations
double CalculatorIO::CalculateInteractive(){
    char operand;
    double firstNumber, secondNumber;

    cout << "Enter first number: ";
    cin >> firstNumber;

    cout << "Enter in an operator(+, -, *, /): ";
    cin >> operand;

    cout << "Enter in a second number: ";
    cin >> secondNumber;

    if(operand == '+')
    {
        return calc.Add(firstNumber, secondNumber);
    }
    else if(operand == '-')
    {
        return calc.Subtract(firstNumber, secondNumber);
    }
    else if(operand == '*')
    {
        return calc.Multiply(firstNumber, secondNumber);
    }
    else if(operand == '/')
    {
        return calc.Divide(firstNumber, secondNumber);
    }
    return 0;
}