#if !defined(BTC_EXCEPTION_HPP)
#define BTC_EXCEPTION_HPP

#include <exception>
#include <iostream>

class BtcException : public std::exception
{
    private:
	    std::string errorMessage;

    public:
        BtcException(const std::string &_message) : errorMessage(_message) { }
        virtual const char *what() const throw()
        {
            return errorMessage.c_str();
	    }
        ~BtcException() throw() { }
};


#endif // BTC_EXCEPTION_HPP
