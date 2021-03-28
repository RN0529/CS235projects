#include <iostream>
using namespace std;
template <class T>
void inOrderTraversal(std::shared_ptr<BinaryNode<T>> subtree_root)
{
    if(subtree_root ==NULL){
        return;
    }
    inOrderTraversal(subtree_root->getLeftChildPtr());
    //call for left side
    cout<<subtree_root->getItem()<<endl;
    //print item before calling for right side
    inOrderTraversal(subtree_root->getRightChildPtr());

}

template <class T>
void postOrderTraversal(std::shared_ptr<BinaryNode<T>> subtree_root)
{
    //if there there is a non null node 
    if(subtree_root !=NULL){
        postOrderTraversal(subtree_root->getLeftChildPtr());
        //call the function recursivly for the left side of the tree
        postOrderTraversal(subtree_root->getRightChildPtr());
        //then on the right
        cout<<subtree_root->getItem()<<endl;
        //print out the item
    }
}

template <class T>
void preOrderTraversal(std::shared_ptr<BinaryNode<T>> subtree_root)
{
    if(subtree_root !=NULL){
        cout<<subtree_root->getItem()<<endl;
        //print item before recursivly calling the fucntion
        preOrderTraversal(subtree_root->getLeftChildPtr());
        //call for left side
        preOrderTraversal(subtree_root->getRightChildPtr());
        //call for right side
        
    }
    
}