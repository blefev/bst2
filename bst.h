#ifndef BST_H
#define BST_H

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>

/* Struct which will be the building block of our list */
struct node{
	int val;
	node* left = NULL;
    node* right = NULL;
};

// NOTE! This implementation ignores duplicates, and does
// not insert them into the list at all.
class BST{
public:
    BST();
    void insert(int);
    void inorder();
    void postorder();
    void preorder();
    bool remove(int);
    node* findMin();
    node* findMax();
    node* search(int);
    int findHeight();

private:
    node * root;

    int findHeightHelper(node*, int);
    void inorder_helper(node*);
    void preorder_helper(node*);
    void postorder_helper(node*);
	node * search_helper(int, node*);
    void insert_helper(int num, node*, node*);
};


#endif
