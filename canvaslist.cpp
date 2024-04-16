#include "canvaslist.h"

#include <iostream>

using namespace std;

CanvasList::CanvasList() {
    list_size = 0;
    list_front = nullptr;
}

CanvasList::CanvasList(const CanvasList& other) {
    list_size = 0;
    list_front = nullptr;

    ShapeNode* currNode = other.list_front;

    // go through other list and add coppies to new list
    while (currNode != nullptr) {
        push_back(currNode->value->copy()); // push a copy of the other list to new list

        currNode = currNode->next;
    }
}

CanvasList& CanvasList::operator=(const CanvasList& other) {
    // check that other is not the same as this
    if (list_size == other.list_size) { // if the same size, check all values for different shape/values
        bool isSame = true;
        for (int i = 0; i < other.list_size; i++) {
            if (this->shape_at(i)->as_string() != other.shape_at(i)->as_string()) { // if different continue function, else return
                isSame = false;
                break;
            }
        }
        if (isSame) return *this; // if the lists are the same return
    }

    this->clear(); // clear all data from this list

    // go through other list and add coppies to new list
    ShapeNode* currNode = other.list_front;
    while (currNode != nullptr) {
        push_back(currNode->value->copy()); // push a copy of the other list to new list

        currNode = currNode->next; 
    }

    return *this;
}

CanvasList::~CanvasList() { 
    clear(); // calls clear to clear all data
}

void CanvasList::clear() {
    if (empty()) return; // if nothing is there, do nothing

    ShapeNode* currNode = list_front;

    // go through list and delete each node one by one
    while (currNode != nullptr) {
        ShapeNode* tmp = currNode->next;
        delete currNode->value;
        delete currNode;
        currNode = tmp;
    }

    // rewire subitems to default values
    list_front = nullptr;
    list_size = 0;
}

void CanvasList::insert_after(int index, Shape* s) {
    if (list_size <= index || index < 0) return; // if invalid index, return

    ShapeNode* currNode = list_front;

    int count = 0;

    // go to node at index
    while (count != index) {
        count++;
        currNode = currNode->next; 
    }

    // create new node with shape s, and rewire current node to point to new node
    ShapeNode* newNode = new ShapeNode();
    newNode->value = s;
    newNode->next = currNode->next;
    currNode->next = newNode;

    list_size += 1;
}

void CanvasList::push_front(Shape* s) {
    ShapeNode* newNode = new ShapeNode(); // create new node
    newNode->value = s;

    if (empty()) { // if list is empty, add new node to front
        newNode->next = nullptr;
        list_front = newNode;
        list_size = 1;
    } else { // else rewire new node as the new front
        newNode->next = list_front;
        list_front = newNode;
        list_size += 1;
    }
}

void CanvasList::push_back(Shape* s) {
    // create new node
    ShapeNode* newNode = new ShapeNode();
    newNode->value = s;
    newNode->next = nullptr;

    if (empty()) { // if list is empty, add node to front
        list_front = newNode;
        list_size = 1;
    } else { // else, add node after the last node
        ShapeNode* currNode = list_front;

        while (currNode->next != nullptr) { // get to last node
            currNode = currNode->next;
        }
        
        // rewire new node as current's next node
        currNode->next = newNode;
        list_size += 1;
    }
}

void CanvasList::remove_at(int index) {
    if (empty()) return; // if empty, do nothing

    if (list_size <= index || index < 0) return; // if invalid index, do nothing

    if (list_size == 1) { // if there is only one node, clear list
        clear();
        return;
    }

    list_size -= 1; // reduce size by one

    if (index == 0) { // if index is the front node, delete current front and rewire new node as front
        ShapeNode* tmp = list_front;
        list_front = list_front->next;
        delete tmp->value;
        delete tmp;
        return;
    }

    ShapeNode* prevNode = list_front; // stores the node before index for rewiring
    ShapeNode* currNode = list_front->next;

    int count = 1;
    while (count != index) { // go to node at index
        count++;
        prevNode = currNode;
        currNode = currNode->next; 
    }

    prevNode->next = currNode->next; // rewire so that node at index is removed

    // delete index node and its value
    delete currNode->value;
    delete currNode;
}

void CanvasList::remove_every_other() {
    if (empty()) return; // if list is empty, do nothing

    if (list_size == 1) { // if list is size of 1, do nothing
        return;
    }

    ShapeNode* prevNode = list_front;
    ShapeNode* currNode = list_front->next;

    int count = 1;
    // traverse list and delete every node that has an odd index
    while (currNode != nullptr) {
        remove_at(count); // deletes the current node and shifts the next node into the place we just removed, so we are removing every other one
        prevNode = prevNode->next;
        if (prevNode == nullptr) { 
            return;
        }
        currNode = prevNode->next;
        
        count++;
    }
}

Shape* CanvasList::pop_front() {
    if (empty()) return nullptr; // if the list is empty return nullptr

    Shape* popShape = list_front->value; // store list_front's value for returnig
    ShapeNode* tmp = list_front->next; // store list_front's next for rewiring

    delete list_front; 

    // rewire list_front
    list_front = tmp;
    list_size -= 1;
    return popShape;
}

Shape* CanvasList::pop_back() {
    if (empty()) return nullptr; // if the list is empty return nullptr

    if (list_size == 1) { // if there is only one node, call pop_front since it will pop out the first node even there is only one
        return pop_front(); // return the node that pop_front returns
    }

    ShapeNode* prevNode = list_front;
    ShapeNode* currNode = list_front->next;

    // get to the last node
    while (currNode->next != nullptr) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // rewire previous so that it is now the last node
    prevNode->next = nullptr;
    Shape* tmp = currNode->value;

    // delete the ShapeNode and return the popped value
    delete currNode;
    list_size -= 1;
    return tmp;
}

ShapeNode* CanvasList::front() const {
    return list_front; // returns the ShapeNode at the front
}

bool CanvasList::empty() const {
    if (list_size == 0 || list_front == nullptr) { // if the size is 0 or the front node is nullptr, the list is empty
        return true;
    } else {
        return false;
    }
}

int CanvasList::size() const {
    return list_size; // returns the list's size
}

int CanvasList::find(int x, int y) const {
    ShapeNode* currNode = this->list_front;
    
    int index = 0;

    // traverses the list to find a shape with an x and y value that is the same as the parameters
    while (currNode != nullptr) {
        if (currNode->value->getX() == x && currNode->value->getY() == y) {
            return index;
        }
        index++;
        currNode = currNode->next; 
    }

    return -1; // if a shape with x and y the same as the parameters is not found, return -1
}

Shape* CanvasList::shape_at(int index) const {
    if (list_size <= index || index < 0) return nullptr; // if the index is invalid, return nullptr
    ShapeNode* currNode = this->list_front;

    int count = 0;

    while (currNode != nullptr) {
        if (index == count) return currNode->value; // if we traverse the list to index, return the shape at that index
        count++;
        currNode = currNode->next; 
    }

    return nullptr;
}

void CanvasList::draw() const {
    ShapeNode* currNode = this->list_front;

    // traverses the list and prints the result of each shape's as_string() function
    while (currNode != nullptr) {
        cout << currNode->value->as_string() << endl;
        currNode = currNode->next;
    }
}

void CanvasList::print_addresses() const {
    ShapeNode* currNode = list_front;

    // traverses the list and prints the the address of each ShapeNode and its Shape value
    while (currNode != nullptr) {
        cout << "Node Address: " << &currNode << "	Shape Address: " << &(currNode->value) << endl;
        currNode = currNode->next; 
    }
}