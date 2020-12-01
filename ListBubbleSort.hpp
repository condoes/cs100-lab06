#ifndef __LIST_BUBBLE_SORT_HPP__
#define __LIST_BUBBLE_SORT_HPP__

#include "container.hpp"
#include "sort.hpp"
#include "ListContainer.hpp"
#include <list>

class Container;

using namespace std;

class BubbleSort : public Sort {
    public:
        /* Constructors */
        BubbleSort() {};
        
        /* Pure Virtual Functions */
        void sort(Container* container);
 
};

#endif 
