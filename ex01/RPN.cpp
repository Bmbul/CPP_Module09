#include "RPN.hpp"
#include <limits>

RPN::RPN() { }

RPN::RPN(const RPN &src) : expression(src.expression), result(src.result) { }

RPN::RPN(const char *_expression) : expression(_expression), result(CalculateExpression()) { }

RPN::~RPN() { }


RPN RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
        result = rhs.result;
        expression = rhs.expression;
    }
    return (*this);
}

inline bool    RPN::IsOperator(char ch) const
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

double RPN::DoOperation(char operation, double firstNum, double secondNum) const
{
    if (operation == '+')
        return (firstNum + secondNum);
    if (operation == '-')
        return (firstNum - secondNum);
    if (operation == '*')
        return (firstNum * secondNum);
    if (secondNum == 0)
    {
        std::cout << "Division by 0" << std::endl;
        throw std::exception();
    }
    return (firstNum / secondNum);
}   

double RPN::CalculateExpression() const
{
    std::stack<double> numbers;
    double result;
    double firstNum;
    double secondNum;
    char ch;

    for(int i = 0; expression[i]; i++)
    {
        ch = expression[i];   
        if (ch == ' ')
            continue ;
        if (isdigit(ch))
            numbers.push(ch - '0');
        else if (IsOperator(ch))
        {
            if (numbers.size() < 2)
                throw std::exception();
            secondNum = numbers.top();
            numbers.pop();
            firstNum = numbers.top();
            numbers.pop();
            result = DoOperation(ch,firstNum, secondNum);
            numbers.push(result);
        }
        else throw std::exception();
    }
    result = numbers.top();
    return (result);
}

double  RPN::GetResult() const
{
    return (result);
}
