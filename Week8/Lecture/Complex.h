//
// Created by Scott McMaster on 5/16/2021.
//

#ifndef LECTURE_COMPLEX_H
#define LECTURE_COMPLEX_H


class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    double getReal() const;
    double getImag() const;

    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    /*
    int operator<(const Complex& other) {
        // TODO -- compare based on the magnitude of the complex number, i.e. sqrt(real^2 + imag^2)
        return false;
    }

    int operator>(const Complex& other) {
        // TODO -- compare based on the magnitude of the complex number, i.e. sqrt(real^2 + imag^2)
        return false;
    }
    */
    
    int operator==(const Complex& other) {
        if (this == &other) {
            return true;
        }

        // In reality, since these are doubles, you might want to use a tolerance (epsilon) to compare.
        return real == other.real && imag == other.imag;
    }
};


#endif //LECTURE_COMPLEX_H
