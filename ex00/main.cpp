#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>

void    ValidateInput(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cout << "Error: Wrong Number of arguments!" << std::endl
            << "Correct Usage: ./btc <filename>." << std::endl;
        exit (EXIT_FAILURE);
    }
    std::ifstream myfile;
    myfile.open(argv[1]);
    if (!myfile)
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    ValidateInput(argc, argv);
    BitcoinExchange btc(argv[1]);
}