/*
Title :       DoublyLinkedList.cpp
Auhor :       Richard Ngo
Description : implementation file of DoublyLinkedList
Dependencies: DoublyLinkedList.hpp
*/
#include <iostream>
#include "DoublyLinkedList.hpp"
using namespace std;
    template <typename ItemType>
    DoublyLinkedList<ItemType>::DoublyLinkedList(){
      First_=nullptr;
      Last_=nullptr;
      size=0;
    }

    /*
    DoublyLinkedList();
    //Default Constructor
    //Copy Constructor
    //Destructor
    */


    //got this code from the slides and adjusted it to fit my class
    template <typename ItemType>
    bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position){
      int pos = position;
      //Create a new node containing the new entry and get a pointer to position
      DoubleNode<ItemType>* new_node_ptr = new DoubleNode<ItemType>(item);
     DoubleNode<ItemType>* pos_ptr = getAtPos(pos);
    // Attach new node to chain
    if (First_ == nullptr){
      // Insert first node
      new_node_ptr->setNext(nullptr);
      new_node_ptr->setPrev(nullptr);
      First_ = new_node_ptr;
      Last_ = new_node_ptr;
      }


      else if (pos==1) {
    // Insert new node at head of chain
        new_node_ptr->setNext(First_);
        new_node_ptr->setPrev(nullptr);
        First_->setPrev(new_node_ptr);
        First_ = new_node_ptr;
      }
      else if (pos==size+1) {
      //insert at end of list
        new_node_ptr->setNext(nullptr);
        new_node_ptr->setPrev(Last_);
        Last_->setNext(new_node_ptr);
        Last_ = new_node_ptr;
      }
      else {
      // Insert new node before node to which position points
        new_node_ptr->setNext(pos_ptr);
        new_node_ptr->setPrev(pos_ptr->getPrevious());
        pos_ptr->getPrevious()->setNext(new_node_ptr);
        pos_ptr->setPrev(new_node_ptr);
      }//end if
    size++; // Increase count of entries
    return true;
    }//end insert

    template <typename ItemType>   
    //refered to the code on the slides and adjusted it to fit my program 
    bool DoublyLinkedList<ItemType>::remove(const int &position){
        // get pointer to position
      DoubleNode<ItemType>* pos_ptr = getAtPos(position);
      if (pos_ptr == nullptr) // no node at position
        return false;
      else {
      // Remove node from chain
      if (pos_ptr == First_)
      {
      // Remove first node
      First_ = pos_ptr->getNext();
      First_->setPrev(nullptr);
      // Return node to the system
      pos_ptr->setNext(nullptr);
      delete pos_ptr;
      pos_ptr = nullptr;
      }
      else if (pos_ptr == Last_ ) {
      //remove last_ node
      Last_ = pos_ptr->getPrevious();
      Last_ ->setNext(nullptr);
      // Return node to the system
      pos_ptr->setPrev(nullptr);
      delete pos_ptr;
      pos_ptr = nullptr;
      }
      else {
      //Remove from the middle
      pos_ptr->getPrevious()->setNext(pos_ptr->getNext());
      pos_ptr->getNext()->setPrev(pos_ptr->getPrevious());
      // Return node to the system
      pos_ptr->setNext(nullptr);
      pos_ptr->setPrev(nullptr);
      delete pos_ptr;
      pos_ptr = nullptr;
      }
      size--;
      return true;
      }
    }
        //removes the node at position

    template <typename ItemType>
    int DoublyLinkedList<ItemType>::getSize() const{
        return size;
    }
        //returns the number of the nodes in the calling list

    template <typename ItemType>
    DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getHeadPtr() const{
        return First_;
    }
        //returns a copy of the hearPtr

    template <typename ItemType>
    DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getAtPos(const int &pos) const{
      DoubleNode<ItemType>* find_ptr = nullptr;
      // return nullptr if there is no node at position
      if(pos <= size){//there is a node at position
        find_ptr = First_;
        for(size_t i = 1; i < pos; i++){
          find_ptr = find_ptr->getNext();
        }
        //find_ptr points to the node at position
      }
    return find_ptr;
        
    }
        //returns a pointer to the node located at pos

    template <typename ItemType>    
    bool DoublyLinkedList<ItemType>::isEmpty() const{
        return(size==0);
    }
        //returns whether the calling list is empty

    template <typename ItemType>
    void DoublyLinkedList<ItemType>:: clear(){
        DoubleNode<ItemType>* holder = Last_;
        for(int i=1;i<=size;i++){
            this->remove(size);
        }
        size=0;
        First_=nullptr;
        Last_=nullptr;
      
    }
        //clears the list

    template <typename ItemType>
    void DoublyLinkedList<ItemType>::display() const{
      DoubleNode<ItemType>* holder = First_;
        for(int i=1;i<size;i++){
            cout<<holder->getItem()<<" ";
            holder= holder->getNext();
        }
        cout<<holder->getItem()<<endl;

    }
        //prints the contents of the calling list in order

    template <typename ItemType>
    void DoublyLinkedList<ItemType>::displayBackwards() const{
        DoubleNode<ItemType>* holder = Last_;
        for(int i=size;i>1;i--){
            cout<<holder->getItem()<<" ";
            holder= holder->getPrevious();
        }
        cout<<holder->getItem()<<endl;

    }
        //prints the contents of the calling list in reverse order

    template <typename ItemType>
    DoublyLinkedList<ItemType> 
        DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list){
          DoublyLinkedList<ItemType> returnList;
          int currIndex =1;
          

          if(size >= a_list.size){  
            for(int i =1;i<=a_list.size;i++){
              returnList.insert(getAtPos(i)->getItem(), returnList.size+1);
              returnList.insert(a_list.getAtPos(i)->getItem(), returnList.size+1);
              currIndex++;
            }       
             
            for(int i = currIndex;i<=size;i++){
              returnList.insert(getAtPos(i)->getItem(), returnList.size+1);
              currIndex++;
            }
            
          }else if(size < a_list.size){
            for(int i =1;i<=size;i++){
              returnList.insert(getAtPos(i)->getItem(), returnList.size+1);
              returnList.insert(a_list.getAtPos(i)->getItem(), returnList.size+1);
              currIndex++;
            }      
            for(int i = currIndex;i<=a_list.size;i++){
              returnList.insert(a_list.getAtPos(i)->getItem(), returnList.size+1);
              currIndex++;
            }

          }


          return returnList;
        }
        //returns the interleaved list of the calling and parameter lists
      