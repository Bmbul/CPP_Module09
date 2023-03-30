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
        int result;

        inline bool     IsOperator(char ch) const;

    public:
        RPN(const char *_expression);
        RPN(const RPN &src);
        ~RPN();

        RPN operator=(const RPN &rhs);

        int GetResult() const;
        int CalculateExpression() const;
        int DoOperation(char operation, int firstNum, int secondNum) const;
};

#endif // RPN_HPP
