#if !defined(RPN_HPP)
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
    private:
        RPN();
		
        std::string     expression;
        double result;

        inline bool     IsOperator(char ch) const;

    public:
        RPN(const char *_expression);
        RPN(const RPN &src);
        ~RPN();

        RPN operator=(const RPN &rhs);

        double GetResult() const;
        double CalculateExpression() const;
        double DoOperation(char operation, double firstNum, double secondNum) const;
};

#endif // RPN_HPP
