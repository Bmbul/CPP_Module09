#include "VectorSorter.hpp"

#include <algorithm>

VectorSorter::~VectorSorter() { }

VectorSorter::VectorSorter() { }

VectorSorter::VectorSorter(const VectorSorter &src) : vector(src.vector) { }

VectorSorter::VectorSorter(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        int number = std::atoi(argv[i]);
        vector.push_back(number);
    }
}
    
VectorSorter    VectorSorter::operator=(const VectorSorter &rhs)
{
    if (this != &rhs)
    {
        vector.clear();
        vector = rhs.vector;
    }
    return (*this);
}

void    VectorSorter::Sort()

    std::cout << "Before    ";
    LogData();
    std::vector<int>::iterator it = vector.begin() + 2;
    std::iter_swap(vector.begin(), it);
    std::cout << "After    ";
    LogData();
}

void    VectorSorter::LogData() const
{
    std::vector<int>::const_iterator    it = vector.begin();
    for(;it != vector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}