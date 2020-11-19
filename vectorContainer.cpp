#include "vectorContainer.hpp"
#include "container.hpp"
#include <iostream>

void VectorContainer::add_element(Base* element) {
    container.push_back(element);
}

        // iterate through trees and output the expressions (use stringify())
void VectorContainer::print() {
    for (int i = 0; i < container.size(); ++i) {
        cout << container.at(i)->stringify();
    }
}

        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
void VectorContainer::sort() {
    if (sort_function) {
        this->sort_function->sort(this); 
    } else {
        throw "sort_function is null";
    }
}

        /* Essentially the only functions needed to sort */
        //switch tree locations
void VectorContainer::swap(int i, int j) {
    Base* temp = container.at(i);
    container.at(i) = container.at(j);
    container.at(j) = temp;
    delete temp;
}

        // get top ptr of tree at index i
Base* VectorContainer::at(int i) {
    return container.at(i);
}

        // return container size
int VectorContainer::size() {
    return container.size();
}
