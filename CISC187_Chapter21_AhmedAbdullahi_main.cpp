/******************************************************************************

Ahmed Abdullahi

Chapter 21 programming assignment - Binary Trees

December 2023

*******************************************************************************/
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include "NumberTree.h"
using namespace std;


// main
int main()
{
    //holds user input
    int inputNumber;
    int counterA;
    
    //DYNQueue object initialization
    NumberTree tree;
                      
    // while loop
    char option = 0;
  while (option != 6)
  {
    //Display menu
    cout <<  endl << endl << "********************************" << endl;
    cout << " Binary Tree - Display Menu " << endl;
    cout << "********************************" << endl;
    cout << "1.  Insert an Integer into the Tree" << endl;
    cout << "2.  Display Tree in order" << endl;
    cout << "3.  Display Leaf Count" << endl;
    cout << "4.  Display Tree Height" << endl;
    cout << "5.  Display Tree Width" << endl;
    cout << "6.  Exit" << endl << endl;
    
    //input option
    cout << "Please choose an option from the numbers above or enter 6 to exit: ";
    cin >> option;
    cout << endl;
    
    // switch case from user option
    switch(option)
    {
    case '1': 
        // case 1 will insert a integer to the binary tree
        cout << "Enter an integer: " << endl << endl;
        
        //get user input for the number
        cin >> inputNumber;

        //input validation
        while (cin.fail()){
            cin.clear();
            cin.ignore();
            
            cout << "Error..." << endl;
            cout << "Please enter a number without any characters." << endl;
            cin >> inputNumber;
        }
        cin.ignore();
        
        // insert the user input
        tree.insertNode(inputNumber);
        
        //confirmation message
        cout << "Great news, we have inserted " << inputNumber<< " into the tree!" << endl;
        
        break;
    
    case '2':   
        // case 2 will display the binary tree in order 
        tree.displayNodes();
        cout<< endl;
        
        break;
    
    case '3':    
        //case 3 will display the leaf counts 
        //counter everytime there is a leaf 
        // (a node that has its left and right pointer to NULL )
        counterA = 0;
        //if there is only a root node, display 0 leafs
        if (tree.treeHeight() != 0){
            tree.countLeafs(counterA);
            cout << "There are: " << (counterA/2) << " leafs" << endl;
        }
        else{
            cout << "There are: 0 leafs" << endl;
        }
        
        break;
    
    case '4':    
        //case 4 will display the tree height
        
        if (tree.treeHeight() != -1){
            cout << "The height is: " << tree.treeHeight() << endl;
        }  
        else{
            cout << "The tree is empty." << endl;
        }
        
        break;
        
    case '5':    
        //case 5 will display all the tree width
        cout << "The width is: " << tree.treeWidth() << endl;
        
        break;
           
    case '6':
        // case 3 will close program
        cout << "Bye, we hope you had a good time." << endl;
        exit(0);
       
        break;
       
    default:  
    
        // validation for menu option
        cout << "That is not a valid menu option." << endl;
        
        break;
    
    }//end switch
 
    
  }//end the while loop
 
    return 0;
}//end main
