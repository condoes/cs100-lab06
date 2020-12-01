#include "ListSelectionSort.hpp"
#include <iostream>
#include "container.hpp"
#include "sort.hpp"
#include "base.hpp"
#include "ListContainer.hpp"
#include <list>


void SelectionSort::sort(Container* container){
    for(int i = 0; i < container->size() - 1; i++) {
        int min_index = i;
        for(int j = i+1; j < container->size(); j++) {
            if(container->at(j)->evaluate() < container->at(min_index)->evaluate()) {
                min_index = j;
            }
            container->swap(i, min_index);
        }
    }
}
 


