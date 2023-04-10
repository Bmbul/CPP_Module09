#include "VectorSorter.hpp"

#include <algorithm>
#include <iomanip>

VectorSorter::~VectorSorter() { }

VectorSorter::VectorSorter() : baseCaseAmount(0){ }

VectorSorter::VectorSorter(const VectorSorter &src)
    : vector(src.vector), baseCaseAmount(src.baseCaseAmount){ }

VectorSorter::VectorSorter(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        int number = std::atoi(argv[i]);
        vector.push_back(number);
    }
    baseCaseAmount = std::max(16, (int)(vector.size() * 0.005));
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

void    VectorSorter::MergeInsertionSort()
{
    clock_t start, end;

    std::cout << "Before    ";
    LogData();

    start = clock();
	std::ios_base::sync_with_stdio(false);
	MergeSort(vector.begin(), vector.size());
    end = clock();

    std::cout << "After    ";
    LogData();
	double duration = double(end - start) / double(CLOCKS_PER_SEC) * 1000000;

	std::cout << "\033[1;31mTime to process a range of " << vector.size()
		<< " elements with std::vector: " << duration << std::setprecision(9) << " usec\033[0m" << std::endl;
}

void	VectorSorter::InsertionSort(std::vector<int>::iterator array, int len)
{
	int key, j;
    for (int i = 1; i < len; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void	VectorSorter::MergeSort(std::vector<int>::iterator array, int len)
{

	if (len < baseCaseAmount)   
	    InsertionSort(array, len);
    else
    {
		int firstLen = len/2 + (len % 2);
		MergeSort(array, firstLen);
		MergeSort(array + firstLen, len - firstLen);
        Merge(array, len);
    }
}


void	VectorSorter::Merge(std::vector<int>::iterator array, int len)
{
    int firstHalfLen = len/2 + (len % 2);
    std::vector<int>::iterator  firstIter = array;
    std::vector<int>::iterator  secondIter = array + firstHalfLen;

    std::vector<int>::iterator  firstEnd = array + firstHalfLen;
    std::vector<int>::iterator  secondEnd = array + len;

    std::vector<int>    temp;
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

    for(int i = 0; i < len; i++)
    {
        array[i] = temp[i];
    }
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