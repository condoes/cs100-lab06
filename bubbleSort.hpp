#ifndef _BUBBLESORT_HPP_
#define _BUBBLESORT_HPP_

#include "sort.hpp"
#include "container.hpp"
#include "vectorContainer.hpp"

class BubbleSort : public Sort {
    public:
        BubbleSort();
        void Sort(Container* container);
};

#endif
