#if !defined(LIST_SORTER)
#define LIST_SORTER

#include "ISorter.hpp"
#include <list>

class ListSorter : public ISorter
{
    private:
        std::list<int> list;
        int baseCaseAmount;

		std::list<int>::iterator	GetNext(std::list<int>::iterator it);
		std::list<int>::iterator	GetPrev(std::list<int>::iterator it);

		void    InsertionSort(std::list<int>::iterator array, int len);
		void    MergeSort(std::list<int>::iterator array, int len);
        void    Merge(std::list<int>::iterator array, int len);

    public:
        ListSorter();
        ListSorter(const ListSorter &src);
        ListSorter(int argc, char **argv);
        ~ListSorter();
        ListSorter  operator=(const ListSorter &rhs);

        virtual	void    MergeInsertionSort();
        virtual void    LogData() const;
};

#endif // LIST_SORTER
