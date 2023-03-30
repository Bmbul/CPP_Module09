#if !defined(LIST_SORTER)
#define LIST_SORTER

#include "ISorter.hpp"
#include <list>

class ListSorter : public ISorter
{
    private:
        std::list<int> list;

    public:
        ListSorter();
        ListSorter(const ListSorter &src);
        ListSorter(int argc, char **argv);
        ~ListSorter();
        ListSorter  operator=(const ListSorter &rhs);

        void    Sort();
        void    LogData() const;
};

#endif // LIST_SORTER
