#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <errno.h>
#include <climits>

void    ValidateInput(int argc, char ** argv)
{
    bool shouldExit = false;
    if (argc == 1)
    {
        std::cout << "More arguments Required!" << std::endl <<
            "Correct Usage: ./PmergeMe <numbers to sort>" << std::endl;
        shouldExit = true;
    }
    char *end;
    for (int i = 1; i < argc; i++)
    {
        long number = std::strtol(argv[i], &end, 10);
        if (errno || end[0] != 0 || number < 0 || number > INT_MAX)
        {
            std::cerr << "Error" << std::endl;
            shouldExit = true;
            break;
        }
    }
    if (shouldExit)
        exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    ValidateInput(argc, argv);
    PmergeMe    merger(argc, argv);
}