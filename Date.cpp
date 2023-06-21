#include "Date.h"

Date::Date(unsigned int y, unsigned int m, unsigned int d)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}

Date::Date(string &d){
    setYear(stoi(d.substr(0, 4)));
    setMonth(stoi(d.substr(4, 2)));
    setDay(stoi(d.substr(6, 2)));
}

void Date::setYear(unsigned int y)
{
    year = y;
}

unsigned int Date::getYear() const
{
    return year;
}

void Date::setMonth(unsigned int m)
{
    if(m < 13)
        month = m;
    else
        throw std::invalid_argument("Invalid month!");
}

unsigned int Date::getMonth() const
{
    return month;
}

void Date::setDay(unsigned int d)
{
    if(d < 31)
        day = d;
    else
        throw std::invalid_argument("Invalid day!");
}

unsigned int Date::getDay() const
{
    return day;
}

void Date::cast_to_date(std::string &d){
    setYear(stoi(d.substr(0, 4)));
    setMonth(stoi(d.substr(6, 2)));
    setDay(stoi(d.substr(9, 2)));
}

void Date::tick(){
    if(day < 30)
        day++;
    if(day == 31){
        day = 1;
        check_month();
    }
}

void Date::check_month(){
    if(month < 11)
        month++;
    if(month == 12){
        month = 1;
        year++;
    }
}

void Date::print() const{
    std::cout << getYear() << "/" << getMonth() << "/" << getDay();
}

bool Date::operator<=(Date &d){
    if(d.getYear() > getYear())
        return true;
    if(d.getMonth() > getMonth())
        return true;
    if(d.getDay() > getDay())
        return true;
    return false;
}

std::istream &operator>>(std::istream &in_put, Date &d){
    int n;
    in_put >> n;
    d.setYear(n);
    in_put.ignore(1);
    in_put >> n;
    d.setMonth(n);
    in_put.ignore(1);
    in_put >> n;
    d.setDay(n);
    return in_put;
}
