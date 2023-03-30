#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <errno.h>
#include <climits>

PmergeMe::PmergeMe() { }

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &src) : vectorSorter(src.vectorSorter),
    listSorter(src.listSorter)
{

}

PmergeMe::PmergeMe(int argc, char **argv) : vectorSorter(argc, argv), listSorter(argc, argv)
{
    std::vector<int> temp;
    vectorSorter.Sort();
    listSorter.Sort();
}


PmergeMe    PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        vectorSorter = rhs.vectorSorter;
        listSorter = rhs.listSorter;
    }
    return (*this);
}