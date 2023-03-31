#include "Date.hpp"
#include "BtcException.hpp"

Date::Date() { }

Date::~Date() { }

Date::Date(const Date &src) : year(src.year), month(src.month), day(src.day) { }

Date    Date::operator=(const Date &rhs)
{
    if (this != &rhs)
    {
        year = rhs.year;
        month = rhs.month;
        day = rhs.day;
    }
    return (*this);
}

bool    Date::operator<(const Date &rhs) const
{
    if (year < rhs.year)
        return (true);
    else if (year == rhs.year)
    {
        if (month < rhs.month)
            return true;
        else if (month == rhs.month)
            return (day < rhs.day);
    }
    return (false);
}

bool    Date::operator==(const Date &rhs) const
{
    return (year == rhs.year && month == rhs.month && day == rhs.day);
}

bool    Date::operator!=(const Date &rhs) const
{
    return !(*this == rhs);
}


bool    Data::IsValidData()
{

}

Date::Date(const std::string &formattedText)
{
    std::stringstream stream(formattedText);
    std::string segment;
    if (std::getline(stream, segment, '-'))
    {
        int _year;
        std::istringstream(segment) >> _year;
        if (_year > 0)
            this->year = _year;
        else
            throw (BtcException("Bad Input" + formattedText));
    }
    else
        throw (BtcException("Bad Input" + formattedText));

    if (std::getline(stream, segment, '-'))
    {
        int _month;
        std::istringstream(segment) >> _month;
        if (_month > 0 && _month <= 12)
            this->month = _month;
        else
            throw (BtcException("Bad Input" + formattedText));
    }
    else
        throw (BtcException("Bad Input" + formattedText));

    if (std::getline(stream, segment))
    {
        int _day;
        
        std::istringstream(segment) >> _day;
        if (_day > 0  && day <= 31)
            this->day = _day;
    }
    else
        throw (BtcException("Bad Input" + formattedText));
}

void    Date::PrintDate()
{
    std::cout << "Year: " << year << ", Month: " << month << ", Day: " << day << std::endl; 
}
