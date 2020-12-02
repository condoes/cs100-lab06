#include <iostream>
#include <list>
#include "ListContainer.hpp"
#include "sort.hpp"
#include "base.hpp"

using namespace std;

void ListContainer::add_element(Base *element) {
    container.push_back(element);
}

void ListContainer::print() {
    for(list<Base*>::iterator it = container.begin(); it != container.end(); it++) {
        cout << (*it)->stringify() << " ";
    }
}

void ListContainer::sort() {
    if (sort_function) {
        this->sort_function->sort(this); 
    } else {
        throw "sort_function is null";
    }
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