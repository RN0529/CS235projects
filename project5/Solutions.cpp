#include "DoublyLinkedList.hpp"
#include "DoubleNode.hpp"
#include <string>
using namespace std;
namespace solutions
{
    /* Bubblesort */
    template <typename Comparable, typename Comparator>
    void bubbleSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
        //loop through the array
        for(int i =1; i<=a_list.getSize();i++){
            //while looping through the array compare the current value to all the previous values on the list and 
            //swap accordingly to the inputed comparator
            for(int j=1;j<=a_list.getSize()-i;j++){

                if(!comp(a_list.getAtPos(j)->getItem(),a_list.getAtPos(j+1)->getItem())){
                    a_list.swap(j,j+1);
                }
            }
        } 

    }

    /* Insertionsort */
    template <typename Comparable, typename Comparator>
    void insertionSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
        for(int i =1; i<=a_list.getSize();i++){
            for(int j=i;j>1;j--){
                //loop through the array and put move the value to the loewst position 
                if(comp(a_list.getAtPos(j)->getItem(),a_list.getAtPos(j-1)->getItem())){
                    a_list.swap(j,j-1);
                }

            }
        } 
    }

/* Quicksort */
     template <typename Comparable, typename Comparator>
    int partition(DoublyLinkedList<Comparable> &a_list, int left_index, int right_index,  const Comparator &comp){
        Comparable pivot = a_list.getAtPos(right_index)->getItem();
        int i =left_index-1;
         for (int j = left_index; j <= right_index - 1; j++)
            {
                // If current element is smaller than the pivot
                if (comp(a_list.getAtPos(j)->getItem(), pivot))
                {
                    i++; // increment index of smaller element
                    a_list.swap(i,j);
                }
            }
            a_list.swap(i+1,right_index);
            return (i + 1);
    }



    template <typename Comparable, typename Comparator>
    void quicksort(DoublyLinkedList<Comparable> &a_list, int left_index, int right_index, const Comparator &comp)
    {
        if(left_index<right_index){
            //while left is less than right recusivly call the quicksort function with the fixed indexes and the two halfs of the list
            int j = partition(a_list,left_index,right_index,comp);
             quicksort(a_list,left_index,j-1,comp);
             quicksort(a_list,j+1,right_index,comp);
        }

    }

    /* Quicksort Wrapper */
    template <typename Comparable, typename Comparator>
    void quickSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
        //calls the other quicksort function
        quicksort(a_list,1,a_list.getSize(),comp);
    }
    /* Merge */
    template <typename Comparable, typename Comparator>
    void merge(DoublyLinkedList<Comparable> &a_list, int left_index, int middle_index, int right_index, const Comparator &comp)
    {

        // int i = 0;
        // int j= 0;
        // int k=1;
        // while(i<middle_index-left_index&& j<= right_index-middle_index){
        //     if(a_list.getAtPos(i+left_index)->getItem()<= a_list.getAtPos(j+middle_index)->getItem()){
        //         a_list.swap(i+left_index,j+middle_index);
        //         i++;
        //     }else{
        //         a_list.swap(j+middle_index,i+left_index);
        //         j++;
        //     }
        //     k++;
        // }

        //couldnt figure out the regular merge sort code so i just used insertion sort to sort the split arrays
        for(int i =left_index; i<=right_index;i++){
            for(int j=i;j>1;j--){
                //loop through the array and put move the value to the loewst position 
                if(comp(a_list.getAtPos(j)->getItem(),a_list.getAtPos(j-1)->getItem())){
                    a_list.swap(j,j-1);
                }

            }
        }

    }

    /* Mergesort */
    template <typename Comparable, typename Comparator>
    void mergeSort(DoublyLinkedList<Comparable> &a_list, int left_index, int right_index, const Comparator &comp)
    {
        if(left_index<right_index){
             int mid = (left_index+right_index)/2;
             //split the array into multiple parts recursivly and then sort the split arrays by combining them
             mergeSort(a_list,left_index,mid,comp);

             mergeSort(a_list,mid+1,right_index,comp);

             merge(a_list,left_index,mid,right_index,comp);

        }

    }

    /* Mergesort Wrapper */
    template <typename Comparable, typename Comparator>
    void mergeSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {

        mergeSort(a_list,1,a_list.getSize(),comp);
    }

    /* Shellsort */
    template <typename Comparable, typename Comparator>
    void shellSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {


         for(int gap =a_list.getSize()/2;gap>1;gap/=2){
            //iterate through the list and compare the gaps and decrese the gap size
            for(int a=gap;a<a_list.getSize();a++){
              for(int i =1; i<=a_list.getSize();i++){
                    for(int j=i;j>1;j--){
                        if(comp(a_list.getAtPos(j)->getItem(),a_list.getAtPos(j-1)->getItem())){
                            a_list.swap(j,j-1);
                        }

                    }
                }
            } 
             
        }
        
    }




}; // namespace solutions