#include <iostream>
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
    if (!head) {
      head = new Node(element);
   } else {
      Node *temp = new Node(element);
      temp->next = head;
      head = temp;
   }
}

void ListContainer::print() {
    Node* currNode = head;
    while(currNode != nullptr) {
        cout << currNode->data;
        currNode = currNode->next;
    }
}

void ListContainer::sort() {

}

void ListContainer::swap(int i, int j) {
    ListContainer* node1;
    ListContainer* node2;

    Base* node1Val = node1->at(i);
    Base* node2Val = node2->at(i);

    Base* tempVal = node1Val;

    node1Val = node2Val;
    node2Val = tempVal;
}

Base* ListContainer::at(int r) {
    Node* current = head;
    int count = 0;
    Base* atReturn = 0;

    while(current != nullptr) {
        if(count == r) {
            atReturn = current->data;
        }
        else {
            current = current->next;
            count++;
        }
    }
    return atReturn;
}

int ListContainer::size() {
    Node* current = head;
    int count = 0;

    while(current != nullptr) {
        count++;
        current = current->next; 
    }

    return count;
}