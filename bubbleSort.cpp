#include "bubbleSort.hpp"

void BubbleSort::Sort(Container* container) { 
    int flag = 1;   
    //Base* temp;             
    int size = container->size(); 
    for(int i = 1; (i <= size) && flag; i++) {
        flag = 0;
        for (int j = 0; j < (size - 1); j++) {
            if (container->at(j+1)->evaluate() < container->at(j)->evaluate()) { 
                container->swap(j+1, j);      
            }
        }
    }
    return;  
} 