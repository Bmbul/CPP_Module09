#include "RPN.hpp"


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

int RPN::DoOperation(char operation, int firstNum, int secondNum) const
{
    if (operation == '+')
        return (firstNum + secondNum);
    if (operation == '-')
        return (firstNum - secondNum);
    if (operation == '*')
        return (firstNum * secondNum);
    return (firstNum /secondNum);
}   

int RPN::CalculateExpression() const
{
    std::stack<int> numbers;
    std::string str;
    std::stringstream ss(expression);
    int result;
    int firstNum;
    int secondNum;

	while (std::getline(ss, str, ' '))
	{
        if (str.length() != 1)
            throw std::exception();

		if (isdigit(str[0]))
            numbers.push(str[0] - '0');
        else if (IsOperator(str[0]))
        {
            if (numbers.size() < 2)
                throw std::exception();
            secondNum = numbers.top();
            numbers.pop();
            firstNum = numbers.top();
            numbers.pop();
            result = DoOperation(str[0],firstNum, secondNum);
            numbers.push(result);
        }
        else throw std::exception();
	}
    return (numbers.top());
}

int  RPN::GetResult() const
{
    return (result);
}
