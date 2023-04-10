#include "ListSorter.hpp"
#include <iomanip>

ListSorter::~ListSorter() { }

ListSorter::ListSorter() : baseCaseAmount(0) { }

ListSorter::ListSorter(const ListSorter &src)
    : list(src.list), baseCaseAmount(src.baseCaseAmount) { }

ListSorter::ListSorter(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        int number = std::atoi(argv[i]);
        list.push_back(number);
    }
    baseCaseAmount = std::max(16, (int)(list.size() * 0.005));
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
	if (len < baseCaseAmount)   
	    InsertionSort(array, len);
    else
    {
		int firstLen = len/2 + (len % 2);
		MergeSort(array, firstLen);
		std::list<int>::iterator iter = array;
		std::advance(iter, firstLen);
		MergeSort(iter, len - firstLen);
        Merge(array, len);
    }
}

void	ListSorter::Merge(std::list<int>::iterator array, int len)
{
    int firstHalfLen = len/2 + (len % 2);
    std::list<int>::iterator  firstIter = array;
    std::list<int>::iterator  secondIter = array;
    std::list<int>::iterator  firstEnd = array;
    std::list<int>::iterator  secondEnd = array;

    std::advance(secondIter, firstHalfLen);
    std::advance(firstEnd, firstHalfLen);
    std::advance(secondEnd, len);

    std::list<int>    temp;
    while (firstIter != firstEnd && secondIter != secondEnd)
    {
        if (*firstIter < *secondIter)
        {
            temp.push_back(*firstIter);
            ++firstIter;
        }
        else{
            temp.push_back(*secondIter);
            ++secondIter;
        }
    }

    for (;firstIter != firstEnd; ++firstIter)
        temp.push_back(*firstIter);
    for (;secondIter != secondEnd; ++secondIter)
        temp.push_back(*secondIter);

    std::list<int>::iterator it = temp.begin();
    for(int i = 0; i < len; i++)
    {
        *array = *it;
        ++array; ++it;
    }
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
