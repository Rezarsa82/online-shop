#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <string>
#include <string.h>

using namespace std;

class Date
{
    friend std::istream &operator>>(std::istream&, Date&);
public:
    explicit Date(unsigned int = 1900, unsigned int = 1, unsigned int = 1);
    Date(string&);

    void setYear(unsigned int);
    unsigned int getYear() const;
    void setMonth(unsigned int);
    unsigned int getMonth() const;
    void setDay(unsigned int);
    unsigned int getDay() const;

    void cast_to_date(std::string&);
    void tick();
    void check_month();
    void print() const;

    bool operator<=(Date&);

private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

#endif // DATE_H_INCLUDED
