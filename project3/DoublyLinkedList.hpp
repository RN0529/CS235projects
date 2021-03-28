/*
Title :       DoublyLinkedList.hpp
Auhor :       Richard Ngo
Description : header/interface file of a DoublyLinkedList;
*/

#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_
#include "DoubleNode.hpp"

template <typename ItemType>
class DoublyLinkedList
{

public:
    DoublyLinkedList();
    /*
    DoublyLinkedList();
    //Default Constructor
    //Copy Constructor
    //Destructor
    */
    bool insert(const ItemType &item, const int &pos);
        //inserts item at position in caller list
    bool remove(const int &position);
        //removes the node at position
    int getSize() const;
        //returns the number of the nodes in the calling list
    DoubleNode<ItemType> *getHeadPtr() const;
        //returns a copy of the hearPtr
    DoubleNode<ItemType> *getAtPos(const int &pos) const;
        //returns a pointer to the node located at pos
    bool isEmpty() const;
        //returns whether the calling list is empty
    void clear();
        //clears the list
    void display() const;
        //prints the contents of the calling list in order
    void displayBackwards() const;
        //prints the contents of the calling list in reverse order
    DoublyLinkedList<ItemType> 
        interleave(const DoublyLinkedList<ItemType> &a_list);
        //returns the interleaved list of the calling and parameter lists
        

protected:
    int size;
    DoubleNode<ItemType>* First_;
    DoubleNode<ItemType>* Last_;

}; // end DoublyLinkedList
#include "DoublyLinkedList.cpp"
#endif


