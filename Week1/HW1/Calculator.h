#ifndef HW1_CALCULATOR_H
#define HW1_CALCULATOR_H
#include <string>

// Contains the basic methods for calculation.
// Should NOT be doing any input or output.
// Throws std::invalid_argument for any invalid input or failed calculations.
class Calculator {
public:
    // Adds two numbers and returns the result.
    double Add(const double first, const double second);

    // Subtracts two numbers and returns the result.
    double Subtract(const double first, const double second);

    // Multiplies two numbers and returns the result.
    double Multiply(const double first, const double second);

    // Divides two numbers and returns the result.
    double Divide(const double first, const double second);

    // Runs the given calculation and returns the result.
    double Calc(const double first, const double second, const char op);
};


#endif //HW1_CALCULATOR_H
