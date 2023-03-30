#if !defined(VECTOR_SORTER_HPP)
#define VECTOR_SORTER_HPP

#include "ISorter.hpp"
#include <vector>

class VectorSorter : public ISorter
{
    private:
        std::vector<int> vector;

    public:
        VectorSorter();
        VectorSorter(const VectorSorter &src);
        VectorSorter(int argc, char **argv);

        VectorSorter    operator=(const VectorSorter &rhs);
        ~VectorSorter();

        virtual void    Sort();
        virtual void    LogData() const;
};

#endif // VECTOR_SORTER_HPP
