#if !defined(DATE_HPP)
#define DATE_HPP

#include <iostream>
#include <sstream>
#include <string>

struct  Date
{
    ~Date();
    Date(const Date &src);
    Date(const std::string &formattedText);
    Date();
    void    PrintDate();

    short year;
    short month;
    short day;
    Date    operator=(const Date &rhs);
    bool    operator<(const Date &rhs) const;
    bool    operator==(const Date &rhs) const;
    bool    operator!=(const Date &rhs) const;

};

#endif // DATE_HPP
