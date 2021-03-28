
/*
Title :       DoubleNode.cpp
Auhor :       Richard Ngo
Description : implementation file of DoubleNode
Dependencies: DoubleNode.hpp
*/

    template <typename ItemType>
    DoubleNode<ItemType>::DoubleNode(ItemType itemIn){
        ptrFront=nullptr;
        pointerBack=nullptr;
        item_=itemIn;
    }
    template <typename ItemType>
    DoubleNode<ItemType>::DoubleNode(ItemType itemIn,DoubleNode* ptr1,DoubleNode* ptr2 ){
        ptrFront=ptr1;
        pointerBack=ptr2;
        item_ = itemIn;
        

    }
    template <typename ItemType>
    ItemType DoubleNode<ItemType>::getItem(){
        return item_;
    }
    template <typename ItemType>
    bool DoubleNode<ItemType>::setNext(DoubleNode* ptr){
        ptrFront=ptr;
        return true;

    }
    template <typename ItemType>
    bool DoubleNode<ItemType>::setPrev(DoubleNode* ptr){
        pointerBack=ptr;
        return true;

    }
    template <typename ItemType>
    DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const {
        return ptrFront;
    }

    template <typename ItemType>
    DoubleNode<ItemType>* DoubleNode<ItemType>::getPrevious() const{
        return pointerBack;
    }