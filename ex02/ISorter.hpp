#if !defined(ISORTER_HPP)
#define ISORTER_HPP

#include <iostream>
#include <cstdlib>

class ISorter
{
    protected:
        ISorter();
        
    public:
        ~ISorter();
        virtual void    MergeInsertionSort() = 0;
        virtual void    LogData() const = 0;
};


#endif // ISORTER_HPP
