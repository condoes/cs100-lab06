
#include "ListBubbleSort.hpp"

void BubbleSort::sort(Container* container) {             
    int size = container->size(); 
    for(int i = 0; i < size-1; i++) {
        for (int j = 0; j < size -i-1; j++) {
            if (container->at(j+1)->evaluate() < container->at(j)->evaluate()) { 
                container->swap(j, j+1);      
            }
        }
    }
} 