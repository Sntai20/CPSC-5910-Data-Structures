#include <iostream>
#include <string>
#include <stdexcept>

#include "date.h"

void runDisplayTest(int month, int day, int year, std::string expected) {
    Date d(month, day, year);
    std::string result = d.GetDisplayFormat();
    if (result != expected) {
        std::cerr << "Failure: " << expected << " is not " << result << std::endl;
    }
}

int main() {
    runDisplayTest(10, 13, 1971, "October 13 is the 286 day in 1971");
    runDisplayTest(10, 13, 2020, "October 13 is the 287 day in 2020");
    runDisplayTest(1, 1, 2020, "January 1 is the 1 day in 2020");

    bool foundException = false;
    try {
        Date d(13, 13, 1971);
    } catch (std::invalid_argument& e) {
        foundException = true;
    }
    if (!foundException) {
        std::cerr << "Didn't catch invalid month" << std::endl;
    }

    foundException = false;
    try {
        Date d(1, 13, -9);
    } catch (std::invalid_argument& e) {
        foundException = true;
    }
    if (!foundException) {
        std::cerr << "Didn't catch invalid year" << std::endl;
    }

    foundException = false;
    try {
        Date d(3, 32, 2019);
    } catch (std::invalid_argument& e) {
        foundException = true;
    }
    if (!foundException) {
        std::cerr << "Didn't catch invalid day" << std::endl;
    }

    foundException = false;
    try {
        Date d(2, 29, 2019);
    } catch (std::invalid_argument& e) {
        foundException = true;
    }
    if (!foundException) {
        std::cerr << "Didn't catch invalid leap day" << std::endl;
    }

    try {
        Date d(2, 29, 2020);
    } catch (std::invalid_argument& e) {
        std::cerr << "leap day invalid" << std::endl;
    }

    return 0;
}
