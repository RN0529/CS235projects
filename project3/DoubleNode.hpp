/*
Title :       DoubleNode.hpp
Auhor :       Richard Ngo
Description : header/interface file of a double node
*/

#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_


template <typename ItemType>
class DoubleNode
{

public:
    DoubleNode(ItemType itemIn);
    DoubleNode(ItemType itemIn,DoubleNode* ptr1,DoubleNode* ptr2 );
    ItemType getItem(); 
    bool setNext(DoubleNode* ptr);
    bool setPrev(DoubleNode* ptr);
    DoubleNode<ItemType>* getNext() const;
    DoubleNode<ItemType>* getPrevious() const;
    

protected:
    DoubleNode *ptrFront;
    DoubleNode *pointerBack;
    ItemType item_;
    
}; // end DoubleNode
#include "DoubleNode.cpp"
#endif