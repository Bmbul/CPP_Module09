#include "ListSorter.hpp"

ListSorter::~ListSorter() { }

ListSorter::ListSorter() { }

ListSorter::ListSorter(const ListSorter &src) : list(src.list) { }

ListSorter::ListSorter(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        int number = std::atoi(argv[i]);
        list.push_back(number);
    }
}

ListSorter    ListSorter::operator=(const ListSorter &rhs)
{
    if (this != &rhs)
    {
        list.clear();
        list = rhs.list;
    }
    return (*this);
}

void    ListSorter::Sort()
{

}

void    ListSorter::LogData() const
{
    std::list<int>::const_iterator    it = list.begin();
    for(;it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
