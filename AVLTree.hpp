
/* 
 * File:   AVLTREE.hpp
 * Author: Alani Johnson
 *
 * Created on April 12, 2017, 8:18 PM
 */

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_
#include "ZNode.hpp"
#include <iostream>

class AVLTree {
    friend class ZDatabase;
    ZNode *root;
    bool AVLflag;
public:
    // constructor, sets AVLflag to false
    AVLTree(); 
    
    // constructor, sets AVLflag to flag
    AVLTree(bool flag); 
    
    // returns the ZNode that contains
    //that zip code in its z_Obj field. If it does not
    //find the zip, it returns NULL
    ZNode *findZip(int z, ZNode *n); 
    
    // adds a new node to the tree. It starts
    // traversing the tree at r
    void addNode(Z_Obj *n, ZNode *r); 
   
    // rotates right around n
    void rotateRight(ZNode *n); 
    
    // rotates left around n
    void rotateLeft(ZNode *n); 
    
    // print tree in order (left, root, right)
    void printIO(ZNode *root); 
    
    // print tree in preorder (root, left, right)
    void PrintPre(ZNode *root); 
    
    // print tree in postorder (left, right, root)
    void PrintPost(ZNode *root); 
    
    //adjusts only heights of the nodes in the tree
    void adjustHeights(ZNode *n); 
    
    //Balances tree using AVL rules by calling other methods
    void AVLBalance(ZNode *n);
    
    //checks balances and returns imbalanced node
    ZNode* checkBalances(ZNode *n); 
    
    //returns balance factor of node
    int getBalance(ZNode* n);
  
};
#endif /* AVLTREE_HPP_ */


