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


bool    Date::IsValidData()
{
    if (year <= 0)
        return (false);
    if (month <= 0 || month > 12)
        return (false);
    if (day <= 0)
        return (false);

    int isLongMonth = !(month == 4 || month == 6 || month == 9 || month == 11);
    if (month == 2)
    {
        int isLeapYear = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
        if (day > 28 + isLeapYear)
            return (false);
    }
    else  if (day > 30 + isLongMonth)
        return (false);
    return (true);
}

Date::Date(const std::string &formattedText)
{
    std::stringstream stream(formattedText);
    std::string segment;
    if (std::getline(stream, segment, '-'))
        std::istringstream(segment) >> year;

    if (std::getline(stream, segment, '-'))
        std::istringstream(segment) >> month;

    if (std::getline(stream, segment))
        std::istringstream(segment) >> day;

    if (!IsValidData())
        throw (BtcException("Bad Input " + formattedText));
}

void    Date::PrintDate() const
{
    std::cout << year << "-" << month << "-" << day; 
}
