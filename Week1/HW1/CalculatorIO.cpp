// TOOO: CalculatorIO implementation goes in this file.
#include <iostream>
#include <fstream>
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

void CalculatorIO::CalculateFile(const std::string& inputFilePath, const std::string& outputFilePath){
    // Open output file
    std::ofstream myfile;
    myfile.open (outputFilePath);

    // Open input file
    std::ifstream inFile;
    char line[20];  // watch the size
    inFile.open(inputFilePath);    // watch for the working directory when you run the project
    if (inFile.is_open())
    {
        std::cout << "\nReading in file " + inputFilePath << std::endl;
        while (inFile.getline(line, 20))
        {
            // TOOO: Parse strings. Reference Lecture code
            // To print to the screen use std::out
            std::cout << line << std::endl;
            myfile << line << std::endl;
        }
        std::cout << "Output saved in " + outputFilePath << std::endl;

        // Close input file
        inFile.close();
    }
    // Close output file
    myfile.close();
}

/*
 * // Uncomment to read a file
void skipBlanks(std::ifstream& inputFilePath)
{
    while (inputFilePath.peek() == ' ')
        inputFilePath.ignore(1);
}

void CalculatorIO::CalculateFile(const std::string& inputFilePath, const std::string& outputFilePath){
    std::ifstream inFile("Input.txt");
    if (!inFile)
    {
        std::cout << "File does not exist";
    }
    while (inFile.peek() != EOF)
        std::cout << (inFile.get());

    inFile.close();

    std::ifstream inFile(inputFilePath);
    if (!inFile)
    {
        std::cout << "File does not exist";
    }
    //while (inFile.peek() != EOF)
    //while (inFile.peek() != '\n' & inFile.peek() != EOF)
    //    std::cout << (inFile.get());
    while (inFile.peek() != '\n')
    {
        std::cout << (inFile.get());
    }

    inFile.ignore(1);
    std::cout << "\n";
    inFile.close();


}

 // TOOO: CalculatorIO::CalculateInteractive
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