#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include "sort.hpp"
#include "base.hpp"

class Sort;
class Base;

struct Node {
    Base* data;
    Node *next;
    Node(Base* data) : data(data), next(0) {}
};

class ListContainer : public Container {
    private:
        Node *head;
    protected:
        Sort* sort_function;

    public:
        /* Constructors */
        ListContainer() : sort_function(nullptr) { };
        ListContainer(Sort* function) : sort_function(function) { };

        /* Non Virtual Functions */
        void set_sort_function(Sort* sort_function); // set the type of sorting algorithm

        /* Pure Virtual Functions */
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

#endif 
