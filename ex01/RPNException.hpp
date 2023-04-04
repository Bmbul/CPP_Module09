#if !defined(RPN_EXCEPTION_HPP)
#define RPN_EXCEPTION_HPP

#include <exception>
#include <iostream>

class RPNException : public std::exception
{
    private:
	    std::string errorMessage;

    public:
        RPNException(const std::string &_message) : errorMessage(_message) { }
        virtual const char *what() const throw()
        {
            return errorMessage.c_str();
	    }
        ~RPNException() throw() { }
};


#endif // RPN_EXCEPTION_HPP
