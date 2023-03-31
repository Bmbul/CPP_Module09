#if !defined(DATE_HPP)
#define DATE_HPP

#include <iostream>
#include <sstream>
#include <string>

class  Date
{
	public:
		~Date();
		Date(const Date &src);
		Date(const std::string &formattedText);
		Date();

		Date    operator=(const Date &rhs);
		bool    operator<(const Date &rhs) const;
		bool    operator==(const Date &rhs) const;
		bool    operator!=(const Date &rhs) const;

    	void    PrintDate() const;
	    
	private:
		short year;
		short month;
		short day;
};

#endif // DATE_HPP
