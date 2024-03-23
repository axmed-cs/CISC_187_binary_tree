/******************************************************************************

Ahmed Abdullahi

Chapter 21 programming assignment - Binary Trees

December 2023

This is the implementation file for the NumberTree Class

*******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include "NumberTree.h"
using namespace std;


/************************************
NumberTree constructor
************************************/
NumberTree::NumberTree(){
    root = nullptr;
    //int n = 0
    
    
}


/******************************************
NumberTree destroySubTree (for destructor)
******************************************/
void NumberTree::destroySubTree(TreeNode *nodePtr){
    // check if node exists
    if (nodePtr)
    {
        //traverse the list using recursion
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        
        //delete the node
        delete nodePtr;
    }
    
}


/***************************************************
NumberTree insertNode (passes it to insert function)
***************************************************/
void NumberTree::insertNode(int num){
    TreeNode *newNode = nullptr; //new node pointer
    
    //store input in the new node
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = nullptr;
    newNode->right = nullptr;
    
    // pass the newnode and root pointer into the insert function
    insert(root, newNode);
}


/**********************************************
NumberTree insert (insert node using recursion)
**********************************************/
void NumberTree::insert(TreeNode *&nodePtr, TreeNode *&newNode){
    // if nodePtr is empty, insert newNode in it
    if (nodePtr == nullptr){
        nodePtr = newNode;
        //n++;
    }
    //if new node is less than current node move left and insert if its at end
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);     //check left branch (recursion)
    //if new node is greater than current node move right and insert if its at end
    else
        insert(nodePtr->right, newNode);    //check right branck (recursion)

}


/*********************************************************************
NumberTree displayInOrder (display all nodes in order using recursion)
*********************************************************************/
void NumberTree::displayInOrder(TreeNode *nodePtr) const{
    // if node exists
    if(nodePtr){
    //traverse the left branch first
        displayInOrder(nodePtr->left); 
    //print out the node value
        cout << nodePtr->value << " ";
    //traverse the right branch
        displayInOrder(nodePtr->right);
    }
    
}


/**********************************************
NumberTree countLeafs (display number of leafs)
**********************************************/
void NumberTree::countLeafs(int &counter){
    
   
    //call the private member function to get the number of leafs
    return numLeafs(root, counter);
    
}

/*******************************************************************************
NumberTree numLeafs (display number of leafs in the binary tree using recursion)
*******************************************************************************/
void NumberTree::numLeafs(TreeNode *nodePtr, int &input){
    
    // if node exists
    if(nodePtr){
    //traverse the left branch first
        numLeafs(nodePtr->left, input); 
    //if node has no children then it is a leaf (increment counter)
    if ((nodePtr->right == nullptr) && (nodePtr->left == nullptr))
        input++;  
    //traverse the right branch
        numLeafs(nodePtr->right, input);
    //if node has no children then it is a leaf (increment counter)
    if ((nodePtr->right == nullptr) && (nodePtr->left == nullptr))
        input++;  
    
    }
    
}


/**************************************************************
NumberTree getTreeHeight (get the tree height using recursion)
**************************************************************/
int NumberTree::getTreeHeight(TreeNode *nodePtr){
    
    // if the node doesn't exist return -1
    // this handles the height being off by 1
    if(nodePtr == NULL){
        return -1;
    }
    else {
        //traverse the left and right subtree and get each depth
        int leftSubTree = getTreeHeight(nodePtr->left);
        int rightSubTree = getTreeHeight(nodePtr->right);
        
        //find the greater depth of the two subtrees
        // and return that + 1 for the root node
        if (leftSubTree > rightSubTree){
            return (leftSubTree + 1);
        }
        else
            return(rightSubTree + 1);
    }
}


/***********************************************
NumberTree treeWidth (display max width of tree)
***********************************************/
int NumberTree::treeWidth(){
    int widthTree = 0;     //holds the current level width of tree
    int maxWidthTree = 0;  //holds the max width of tree
    //the for loop handles the levels of the binary tree
    for (int i = 1; i <= treeHeight(); i++){
        //call the private member function to get the width of tree and
        //use the root node and current level (i) as parameter
        widthTree = getTreeWidth(root, i);
        if (widthTree > maxWidthTree)    //get the max width
            maxWidthTree = widthTree;
    }
    //return the max width
    return maxWidthTree;
}


/**************************************************************
NumberTree getTreeWidth (get the tree width using recursion)
**************************************************************/
int NumberTree::getTreeWidth(TreeNode *nodePtr, int level){

    // if the tree is empty return 0 for width
    if(nodePtr == NULL){
        return 0;
    }
    // if tree is at root node then return 1 for width
    if(level == 1){
        return 1;
    }
    //else find the width using recursion for left and right subtree
    else if (level > 1)
        //traverse the left and right subtree and get each width
       return getTreeWidth(nodePtr->left, level-1) 
            + getTreeWidth(nodePtr->right, level - 1);
            
return 0;
}





