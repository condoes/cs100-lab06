#include <iostream>
#include <list>
#include "ListContainer.hpp"
#include "sort.hpp"
#include "base.hpp"

using namespace std;

// ListContainer::ListContainer() : sort_function(nullptr){

// }

// ListContainer::ListContainer(Sort* function) : sort_function(function){

// }

void ListContainer::set_sort_function(Sort * sort_function) {

}

void ListContainer::add_element(Base* element) {
    container.push_back(element);
}

void ListContainer::print() {
    for(list<Base*>::iterator it = container.begin(); it != container.end(); it++) {
        cout << (*it)->stringify();
        cout << endl;
    }
}

void ListContainer::sort() {

}

void ListContainer::swap(int i, int j) {
    list<Base*>::iterator item1 = next(container.begin(), i); 
    list <Base*>:: iterator item2 = next(container.begin(), j);

    iter_swap(item1, item2);
}

Base* ListContainer::at(int r) {
    list<Base*>::iterator it = container.begin();
    for(unsigned i = 0; i < r; i++) {
        it++;
    }
    return *it;
}

int ListContainer::size() {
    return container.size();
}