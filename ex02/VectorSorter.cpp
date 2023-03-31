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
{
    std::cout << "Before    ";
    LogData();
    std::cout << "After    ";
    LogData();
}

void    VectorSorter::MergeSort()
{
    
}

void    VectorSorter::InsertionSort(std::vector<int>::iterator start, int length)
{

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