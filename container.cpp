#include <iostream>

#include "container.hpp"

class Sort;
class Base;

// class Container {
//     protected:
//         Sort* sort_function;

//    public:
        /* Constructors */
//Container::Container() : sort_function(nullptr) { };
//Conatiner::Container(Sort* function) : sort_function(function) { };

        /* Non Virtual Functions */
void Container::set_sort_function(Sort* sort_function) {
    this->sort_function = sort_function;
}