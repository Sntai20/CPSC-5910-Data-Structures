//
// Created by Antonio Santana on 3/29/21.
//

#include <stdexcept>
#include <string>
#include <sstream>
#include "date.h"

// Months of the year. The 0th element is a dummy to prevent off-by-one errors.
static std::string MONTHS[13] = {"skipme", "January", "February", "March", "April",
                                 "May", "June", "July", "August", "September", "October",
                                 "November", "December" };

// Days per month (with the 0th dummy) for standard and leap years.
static int DAYS_IN_MONTH_STD[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int DAYS_IN_MONTH_LEAP[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Constructor
Date::Date(int month, int day, int year) {
    if (month < 1 || month > 12) {
        throw std::invalid_argument("months between 1 and 12");
    }

    if (year < 0) {
        throw std::invalid_argument("year must be positive");
    }

    int* daysInMonth = IsLeapYear(year) ? DAYS_IN_MONTH_LEAP : DAYS_IN_MONTH_STD;
    if (day < 1 || day > daysInMonth[month]) {
        throw std::invalid_argument("day is invalid");
    }

    this->month = month;
    this->day = day;
    this->year = year;
}

// Static method that does leap year detection.
bool Date::IsLeapYear(int year) {
    if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)) {
        return true;
    }
    return false;
}

// Expose the day of month.
int Date::GetDay() const {
    return day;
}

// Expose the year.
int Date::GetYear() const {
    return year;
}

// Return the month name.
std::string Date::GetMonthName() const {
    return MONTHS[month];
}

// Get the day of year.
int Date::GetDayInYear() const {
    int diy = 0;
    int* daysInMonth = IsLeapYear(year) ? DAYS_IN_MONTH_LEAP : DAYS_IN_MONTH_STD;
    for (int i = 1; i < month; i++) {
        diy += daysInMonth[i];
    }
    diy += day;
    return diy;
}

std::string Date::GetDisplayFormat() const {
    std::stringstream ss ;
    ss << GetMonthName() << " " << GetDay() << " is the " << GetDayInYear() << " day in " << GetYear();
    return ss.str();
}