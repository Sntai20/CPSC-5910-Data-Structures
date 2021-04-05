#ifndef HW1_CALCULATORIO_H
#define HW1_CALCULATORIO_H

#include <string>
#include "Calculator.h"

// Command-line and file-based interfaces for the Calculator.
// Throws appropriate exceptions for invalid calculations or file operations.
class CalculatorIO {
public:
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
   // Uncomment to read a file
   // void CalculateFile(const std::string& inputFilePath, const std::string& outputFilePath);

    // Prompts the user for:
    // 1. First number.
    // 2. Operation (+, -, *, /)
    // 3. Second number.
    // In this order, and uses the Calculator to calculate and return the result.
    double CalculateInteractive();

private:
    // A calculator instance for you to use.
    Calculator calc;
};

#endif //HW1_CALCULATORIO_H
