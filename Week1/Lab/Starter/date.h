//
// Created by Antonio Santana on 3/29/21.
//

#ifndef CPSC_5910_DATE_H
#define CPSC_5910_DATE_H

#include <string>
class Date {
public:
    Date(int month, int day, int year);
    std::string GetMonthName() const;
    int GetDay() const;
    int GetYear() const;
    int GetDayInYear() const;
    std::string GetDisplayFormat() const;

private:
    static bool IsLeapYear(int year);
    int month, day, year;
};
#endif //CPSC_5910_DATE_H