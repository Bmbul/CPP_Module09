#if !defined(VECTOR_SORTER_HPP)
#define VECTOR_SORTER_HPP

#include "ISorter.hpp"
#include <vector>
#include <iterator>

class VectorSorter : public ISorter
{
    private:
        std::vector<int> vector;
        int baseCaseAmount;

        void    InsertionSort(std::vector<int>::iterator array, int len);
        void    MergeSort(std::vector<int>::iterator array, int len);
        void    Merge(std::vector<int>::iterator array, int len);

    public:
        VectorSorter();
        VectorSorter(const VectorSorter &src);
        VectorSorter(int argc, char **argv);

        VectorSorter    operator=(const VectorSorter &rhs);
        ~VectorSorter();

        virtual void    MergeInsertionSort();
        virtual void    LogData() const;
};

#endif // VECTOR_SORTER_HPP
