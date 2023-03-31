#include "ListSorter.hpp"
#include <iomanip>

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

void    ListSorter::MergeInsertionSort()
{
	clock_t start, end;

    std::cout << "Before    ";
    LogData();

    start = clock();
	std::ios_base::sync_with_stdio(false);
	MergeSort(list.begin(), list.size());
    end = clock();

    std::cout << "After    ";
    LogData();
	double duration = double(end - start) / double(CLOCKS_PER_SEC) * 1000000;
	// std::list<int>::iterator lastToCheck = GetPrev(list.end());
	// for(std::list<int>::iterator iter = list.begin(); iter != lastToCheck; ++iter)
	// {
	// 	if (*iter > *GetNext(iter))
	// 	{
	// 		std::cout << "\n\n\n\n VORI E" << std::endl;
	// 	}
	// }
	std::cout << "\033[1;31mTime to process a range of " << list.size()
		<< " elements with std::vector : " << duration << std::setprecision(9) << " usec\033[0m" << std::endl;
}


std::list<int>::iterator	ListSorter::GetNext(std::list<int>::iterator it)
{
	std::list<int>::iterator next = it;
	return (++next);
}

std::list<int>::iterator	ListSorter::GetPrev(std::list<int>::iterator it)
{
	std::list<int>::iterator prev = it;
	return (--prev);
}

void	ListSorter::InsertionSort(std::list<int>::iterator array, int len)
{
	int key;
	std::list<int>::iterator it = GetNext(array);
	std::list<int>::iterator j;
	std::list<int>::iterator modifying;
    for (int i = 1; i < len; i++)
    {
        key = *it;
        j = GetPrev(it);

        while (j != GetPrev(array) && *j > key)
        {
			modifying = GetNext(j);
            *modifying = *j;
            --j;
        }
		modifying = GetNext(j);
        *modifying = key;
		++it;
    }
}

void	ListSorter::MergeSort(std::list<int>::iterator array, int len)
{
	if (len > 15)   
	{
		int firstLen = len/2 + (len % 2);
		MergeSort(array, firstLen);
		std::list<int>::iterator iter = array;
		std::advance(iter, firstLen);
		MergeSort(iter, len - firstLen);  
	}
	InsertionSort(array, len);
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
