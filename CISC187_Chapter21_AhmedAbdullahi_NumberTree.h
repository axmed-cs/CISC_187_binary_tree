/******************************************************************************

Ahmed Abdullahi

Chapter 21 programming assignment - Binary Trees

December 2023

This is the specification file for the NumberTree Class

*******************************************************************************/
#ifndef NUMBERTREE_H
#define NUMBERTREE_H


class NumberTree{
    private: 
        // structure for the tree nodes
        struct TreeNode{
            int value;       // holds the node value
            TreeNode* left;  // pointer to left child node
            TreeNode* right; // pointer to right child node
        };
        
        TreeNode *root; // Tree root pointer
        
        //private member functions  
        void insert(TreeNode *&, TreeNode *&);
        void destroySubTree(TreeNode *);
        void displayInOrder(TreeNode *) const;
        void numLeafs(TreeNode *, int&);
        int getTreeHeight(TreeNode *);
        int getTreeWidth(TreeNode *, int);
        
        
    public: 
        // contructor
        NumberTree();
        
        // destructor
        ~NumberTree()
            { destroySubTree(root); }
        
        //Binary tree operations
        void insertNode(int);
        void displayNodes() const
            { return displayInOrder(root); } 
        void countLeafs(int &);
        int treeHeight() 
            { return getTreeHeight(root); }
        int treeWidth();
        
            
};
#endif