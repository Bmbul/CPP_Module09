#if !defined(PMERGE_ME_HPP)
#define PMERGE_ME_HPP

#include "VectorSorter.hpp"
#include "ListSorter.hpp"

class PmergeMe
{
    private:
        VectorSorter    vectorSorter;
        ListSorter      listSorter;

        PmergeMe();
        
    public:
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &src);
        ~PmergeMe();
        PmergeMe  operator=(const PmergeMe &rhs);
};



#endif // PMERGE_ME_HPP
