#include "VectorSorter.hpp"

#include <algorithm>
#include <iomanip>

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
	// for(std::vector<int>::iterator iter = vector.begin(); iter != vector.end() - 1; ++iter)
	// {
	// 	if (iter[0] > iter[1])
	// 	{
	// 		std::cout << "\n\n\n\n VORI E" << std::endl;
	// 	}
	// }
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
	if (len > 15)   
	{
		int firstLen = len/2 + (len % 2);
		MergeSort(array, firstLen);
		MergeSort(array + firstLen, len - firstLen);  
	}
	InsertionSort(array, len);
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