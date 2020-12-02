#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "container.hpp"
#include "sort.hpp"
#include "ListContainer.hpp"
#include <list>

class Container;

using namespace std;

class SelectionSort : public Sort {
    public:
        /* Constructors */
        SelectionSort() {};
        
        /* Pure Virtual Functions */
        void sort(Container* container);
 
};

#endif 
