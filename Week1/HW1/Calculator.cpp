// TOOO: Calculator implementation goes in this file.

#include "Calculator.h"

// Adds two numbers and returns the result.
double Calculator::Add(const double first, const double second){
    /*double results = 0;
    op = '+';
    double Calc(const double first, const double second, const char op);
    */
    return first + second;
}

// Subtracts two numbers and returns the result.
double Calculator::Subtract(const double first, const double second){
    return first - second;
}

// Multiplies two numbers and returns the result.
double Calculator::Multiply(const double first, const double second){
    return first * second;
}

// Divides two numbers and returns the result.
double Calculator::Divide(const double first, const double second){
    return first / second;
}

// Runs the given calculation and returns the result.
double Calculator::Calc(const double first, const double second, const char op){
    double results = 0;

    if (op == '+'){
        results = Calculator::Add( first, second);
        return results;
    } else {
        //std::cout << "IDK";
        return results;
    }
}