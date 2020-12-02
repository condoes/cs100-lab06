#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include "sort.hpp"
#include "base.hpp"
#include "container.hpp"
#include <vector>

using namespace std;

class VectorContainer : public Container {
    private:
        vector<Base*> container;
    protected:
        Sort* sort_function;
    public:
        /* Constructors */
        VectorContainer() : sort_function(nullptr) {};
        VectorContainer(Sort* function) : sort_function(function) {};

        // push the top pointer of the tree into container
        void add_element(Base* element);
        // iterate through trees and output the expressions (use stringify())
        void print();
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        void sort();

        /* Essentially the only functions needed to sort */
        //switch tree locations
        void swap(int i, int j);
        // get top ptr of tree at index i
        Base* at(int i);
        // return container size
        int size();
};

#endif //__VECTORCONTAINER_HPP__
