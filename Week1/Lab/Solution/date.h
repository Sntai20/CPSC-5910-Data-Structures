#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
    Date(int month, int day, int year);     // constructor
    std::string GetMonthName() const;
    int GetDay() const;
    int GetYear() const;
    int GetDayInYear() const;       // between 1 and 365/366
    std::string GetDisplayFormat() const;

private:
    static bool IsLeapYear(int year);
    int month, day, year;
};


#endif //DATE_H
