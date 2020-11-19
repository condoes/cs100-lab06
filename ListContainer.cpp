#include <iostream>
#include <list>
#include "ListContainer.hpp"
#include "sort.hpp"
#include "base.hpp"

using namespace std;


void ListContainer::add_element(Base* element) {
    container.push_back(element);
}

void ListContainer::print() {
    for(list<Base*>::iterator it = container.begin(); it != container.end(); it++) {
        cout << (*it)->stringify() <<  " ";
        //cout << endl;
    }
}

void ListContainer::sort() {
    try{
        if(sort_function) {
        this->sort_function->sort(this);
    }
        else {
            throw "sort function is null";
        }
    }
    catch(const char* msg) {
        cout << "Sort function is null- cannot call sort \n";
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