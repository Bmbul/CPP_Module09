#include "RPN.hpp"
#include <iostream>
#include <stdlib.h>
#include "RPNException.hpp"

void    ValidateInput(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "Wrong Number of arguments!" << std::endl
            << "Valid Usage: ./RPN <expression>" << std::endl;
    else if (std::string(argv[1]).find_first_not_of("0123456789+-/* ") != std::string::npos)
        std::cout << "ERROR" << std::endl;
    else return ;

    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    ValidateInput(argc, argv);
    try
    {
        RPN rpn(argv[1]);
        std::cout << rpn.GetResult() << std::endl;
    }
    catch(RPNException &e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}