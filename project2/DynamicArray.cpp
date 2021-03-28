/****************************************************************************************************************************
Title :       DynamicArray.cpp
Auhor :       Nigel Ferrer
Modified By:  ** Richard Ngo **
Description : implementation file of a dynamically resizeable array class
Dependencies: DynamicArray.hpp
****************************************************************************************************************************/

#include <iostream>


/****************************************************** Public Methods *****************************************************/

/* Default Constructor */
template <class T>
DynamicArray<T>::DynamicArray() : current_capacity_{1}, item_count_{0} // initializer list
{
    items_ = new T[current_capacity_]; /* initializes items_ to a dynamically 
                                           allocated array of size 
                                           current_capacity_ */
}

/* Destructor */
template <class T>
DynamicArray<T>::~DynamicArray()
{
    clear(); /* clear() releases dynamically allocated
                   memory - we want to repeat this behavior
                   in other methods, which is why the code 
                   in clear() is in its own function as 
                   opposed to simply being in the destructor */
}

/** 
    implements addition of an item of type T to the end of the caller
    @param new_entry to be added to the caller
    @post if successful, the caller contains the new_entry
    @return true if the addition was successful; false otherwise
*/
template <class T>
bool DynamicArray<T>::add(const T &new_entry)
{
    try
    {
      if(item_count_==current_capacity_){
        //if itemcount == capacity call resize and then set the next index to the itemcount
        resize();
      }
      items_[item_count_]= new_entry;
      item_count_++;
      return true;
    }
    catch (...)
    {
        return false;
    }
}

/**
    returns whether the caller contains parameter 
        T an_entry by checking whether its index 
        is above sentinel value -1
*/
template <class T>
bool DynamicArray<T>::contains(const T &an_entry) const
{
    return getIndexOf(an_entry) > -1;
}

/**
    returns whether the caller contains no items
 */
template <class T>
bool DynamicArray<T>::isEmpty() const
{
    return item_count_ == 0;
}

/** 
    implements the removal of the first instance of parameter 
        an_item from the caller
    @param an_item to be removed from the caller
    @post if successful, the first instance of an_item has been 
        has been removed from the dynamic array 
    @return true if the removal was successful; false otherwise
*/
template <class T>
bool DynamicArray<T>::remove(const T &an_item)
{

    try
    {
      //if contains item then loop through the index of that item and set the next values to its previous and then decrement item item_count_
      //if itemcount <= current_capacity_/2 resize array;
      
      if(contains(an_item)){
          
       for(int i = getIndexOf(an_item);i<item_count_-1;i++){
          items_[i]=items_[i+1];
        }
        item_count_--;
        resize();
   
        
        
        return true;

      }else{
        return false;
      }

    }
    catch (...)
    {
        return false;
    }
    
}

/**
    reassigns the caller's items_ array to parameter new_items_arr
    @param new_items_arr is a pointer to the first element of the
        array to which items_ will be assigned
    @param size is the number of entries in new_items_arr
    @post if successful, the items_ array has been assigned to new_items_arr
    @return true if the reassignment was successful; false otherwise
*/
template <class T>
bool DynamicArray<T>::setItems(T *new_items_arr, const size_t &size)
{
    try
    {
        clear();
        item_count_ = size;
        items_ = new_items_arr;
        current_capacity_ = size * 2;
    }
    catch (...)
    {
        return false;
    }
}

/**
    return the frequency of occurence of parameter an_entry
        in the caller
*/
template <class T>
int DynamicArray<T>::getFrequencyOf(const T &an_entry) const
{
    int frequency = 0;
    int cun_index = 0; // Current array index
    while (cun_index < item_count_)
    {
        if (items_[cun_index] == an_entry)
        {
            frequency++;
        } // end if

        cun_index++; // Increment to next entry
    }                // end while

    return frequency;
}

/* Accessor: current_capacity_ */
template <class T>
size_t DynamicArray<T>::getCapacity() const
{
    return current_capacity_;
}

/* Accessor: item_count_ */
template <class T>
size_t DynamicArray<T>::getOccupiedSpaces() const
{
    return item_count_;
}

/* Accessor: items_ */
template <class T>
T *DynamicArray<T>::getItems() const
{
    return items_;
}

/** 
    copies the items of the calling dynamic array
        into a vector and returns that vector
*/
template <class T>
std::vector<T> DynamicArray<T>::toVector() const
{
    std::vector<T> arr_contents;
    for (size_t i = 0; i < item_count_; i++)
    {
        arr_contents.push_back(items_[i]);
    }
    return arr_contents;
}

/**
    Releases dynamically allocated data and 
        handles the potential dangling pointer 
        that could be items_
*/
template <class T>
void DynamicArray<T>::clear()
{
    item_count_ = 0;
    delete[] items_;
    items_ = nullptr;
    current_capacity_ = 1;
}

/** 
    prints items of the caller line by line with 
        their corresponding index rankings    
    @pre type T contains a method getName()
 */
template <class T>
void DynamicArray<T>::displayOrderedNames()
{
    try
    {
        for (size_t i = 0; i < item_count_; i++)
        {
            std::cout << i << ". " << items_[i].getName() << std::endl;
        }
    }

    catch (...)
    {
        return;
    }
}

/** 
    swaps the positions of parameters i and j 
        in the caller
*/
template <class T>
void DynamicArray<T>::swap(const int &i, const int &j)
{
    T temp = items_[i];
    items_[i] = items_[j];
    items_[j] = temp;
}

/**************************************************** Operator Overloads ***************************************************/

template <class T>
void DynamicArray<T>::operator+(T rhs)
{
    add(rhs);

}

template <class T>
void DynamicArray<T>::operator-(const T &rhs)
{
    remove(rhs);

}

template <class T>
T DynamicArray<T>::operator[](const size_t &index)
{
    return(items_[index]);
}

/***************************************************** Private Methods *****************************************************/

/**
    returns whether the caller is full
    @pre item_count_ > -1
    @return true if the caller is at capacity; false otherwise
*/
template <class T>
bool DynamicArray<T>::atCapacity() const
{
    return item_count_ == current_capacity_;
}
/**
    @param target an object of type T that will be 
        parsed sought after in the caller
    @return the index of target if it is in the caller;
        -1 otherwise 
*/
template <class T>
int DynamicArray<T>::getIndexOf(const T &target) const
{
    bool found = false;
    int result = -1;
    int search_index = 0;

    // If the bag is empty, item_count_ is zero, so loop is skipped
    while (!found && (search_index < item_count_))
    {
        if (items_[search_index] == target)
        {
            found = true;
            result = search_index;
        }
        else
        {
            search_index++;
        } // end if
    }     // end while
    return result;
} // end getInde

/* 
    copies the elements of items_ into a new dynamically allocated
        array which is either twice or half the size of current_capacity_
        depending on whether the resize was called because of an addition
        or a removal
*/
template <class T>
void DynamicArray<T>::resize()
{
    T* newAry;
    //declaring a new pointer called new array
    if(item_count_<= current_capacity_/2){
      //if the itemcount is less than or equal to capacity/2 we must set the array to be half of the capacity 
        newAry = new T[current_capacity_/2];
        for(int i = 0; i<item_count_;i++){
            newAry[i]=items_[i];
        }
        delete[] items_;
        items_ = newAry;
        current_capacity_ = current_capacity_ / 2;
        //deleteing the current array and reset the respected variables
    }else if(item_count_==current_capacity_){
      //same as above except expanding the array;
        newAry = new T[current_capacity_*2];
        for(int i = 0; i<item_count_;i++){
            newAry[i]=items_[i];
        }
        delete[] items_;
        items_ = newAry;
        current_capacity_ = current_capacity_ * 2;
    }
}