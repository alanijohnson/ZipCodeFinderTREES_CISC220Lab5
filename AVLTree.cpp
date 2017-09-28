
/* 
 * File:   AVLTREE.cpp
 * Author: Alani
 * 
 * Contains: Methods necessary to build Balanced Binary Search Tree
 * Created on April 12, 2017, 8:18 PM
 */

#include "AVLTree.hpp"

/* AVLTree() - constructor for AVLTree class
 *             creates unbalanced binary search tree
 *             initializes root to NULL
 */
AVLTree::AVLTree() {
    // constructor, sets AVLflag to false
    AVLflag = false;
    root = NULL; //initialize root
}

/* AVLTree(bool) - constructor for ZDatabase class
 *          creates a binary search tree (balanced or unbalanced)
 *          Initializes root to NULL
 * 
 * arguments:
 *          bool - flag - determines whether or not tree is balanced
 *                  true - AVL Balanced Tree
 *                  false - Unbalanced Binary Search Tree
 */
AVLTree::AVLTree(bool flag) {
    // constructor, sets AVLflag to flag
    AVLflag = flag;
    root = NULL; //initialize root
}

/* findZip(int, ZNode) - returns the ZNode that contains that zip code in its 
 *                       z_Obj field. If it does notfind the zip, it returns NULL
 * 
 *                       fnct written recursively
 *                          starts at root and calls the left or right node
 *                          after comparing node zipcode to searching zipcode
 *                          when zipcode is found, ZNode is returned
 *                          if bottom of tree is reached when node is null,
 *                          NULL is returned
 * 
 * arguments:
 *          int - zip code to be found within 
 *          ZNode - node to start at (should pass in root to start at top of tree)
 * return: 
 *          ZNode - node with matching zipcode
 *          NULL - node not found
 */
ZNode* AVLTree::findZip(int z, ZNode *n) {
    if (n == NULL) { //stop condition: bottom of tree reached
        return NULL;
    } else if (z == n->zipO->zip) { //node found; return node
        return n; 
    } else { //continue search for matching node
        //call function with left node if zipcode is smaller than current node zipcode
        //call function with right node if zipcode is larger than current node zipcode 
        findZip(z, ((z < n->zipO->zip) ? n->left : n->right));
    }
}

/* addNode(Z_Obj, ZNode) - creates node and adds it to the tree in its proper place
 *                         when AVLFlag = true, tree is balanced after addition of
 *                         node
 * 
 *                         function written recursively
 *                             looks through tree, compares zipcode of new node 
 *                             with zipcode of current node to see if node should
 *                             be a left or right child. Then checks position to
 *                             see if a child exists. If child exists, function
 *                             is called passing in the child. When empty position
 *                             is reached node is added to tree
 * 
 * arguments:
 *          Z_Obj - zip code object containing all data fields
 *          ZNode - node to start at (should pass in tree->root to start at top of tree)
 * return: none
 */
void AVLTree::addNode(Z_Obj* z, ZNode* r) {
    if (r == NULL) { //tree is empty (root is NULL); create new node and make it the root
        root = new ZNode(z);
        return;
    } else { //tree contains elements
        if (*z < *(r->zipO)) { //zip less than the root, left child
            if (r->left == NULL) { //can the node be added? yes, if no pointer
                //add node as left child
                ZNode *n = new ZNode(z);
                n->parent = r;
                r->left = n;
                adjustHeights(n->parent); //adjust the heights going up the tree to root
                
                //AVL Balancing
                if (AVLflag) {
                    AVLBalance(n);
                }
                return;
            }
            addNode(z, r->left); //call function to check left child for node addition
        } else { //node's zipcode is larger, right child
            if (r->right == NULL) { //can node be added? yes, if no pointer
                //add node as right child
                ZNode *n = new ZNode(z);
                n->parent = r;
                r->right = n;
                adjustHeights(n->parent); //adjust the heights going up the tree to the root
                
                //AVL Balancing
                if (AVLflag) {
                    AVLBalance(n);
                }
                return;
            }
            addNode(z, r->right); //call function to check right child for node addition
        }
    }
}

/* AVLBalance(ZNode) - balances the tree by rotating following AVL Rules
 *                     AVL Rules:
 *                     -Balance factor = left height - right height
 *                     -Rotation Required when balance factor (bf) is 2 or -2
 *                          -bf = -2 --> check child
 *                                          bf = -1 : left rotation
 *                                          bf = 1 : right rotation left rotation
 *                          -bf = 2 --> check child
 *                                          bf = -1 : right rotation
 *                                          bf = 1 : left rotation right rotation
 *                      
 * arguments:
 *          ZNode - node added to tree, start of potential imbalance
 * return: none
 */
void AVLTree::AVLBalance(ZNode* n) {

    //locate imbalanced node
    ZNode* imbal_Z = checkBalances(n->parent);
    
    //after checkBalances imbal_Z is imbalanced Node and bf is the balance factor
    int bf = getBalance(imbal_Z);

    //while there is an imbalance rotate
    while (bf != 0) { //continue balancing until bf isn't 0 (while bf is 2 or -2)
        if (bf > 0) { //balance factor positive - left heavy
            if (getBalance(imbal_Z->left) < 0) { //if lefts balance factor is negative - right heavy
                rotateLeft(imbal_Z->left); //rotate the left node left
            }
            rotateRight(imbal_Z);
        } else if (bf < 0) { //balance factor negative - right heavy
            if (getBalance(imbal_Z->right) > 0) { // if the rights balance factor is positive - left heavy
               rotateRight(imbal_Z->right);
            }
            rotateLeft(imbal_Z);
        }
        
        //check balances again, finding imbalanced node and finding balance factor
        imbal_Z = checkBalances(n->parent);
        bf = getBalance(imbal_Z);
    }

}

/* checkBalances(ZNode) - checks for an imbalance starting at added node
 *                        returns first imbalanced node (bf = 2 or -2)
 *                        if no imbalanced node is found NULL is returned
 * 
 *                        recursive function
 *                           keeps checking parent of node until NULL is reached
 *                           or until imbalance is found
 *                      
 * arguments:
 *          ZNode - node added to tree, start of potential imbalance
 * return: 
 *          ZNode - first imbalanced node encountered
 */
ZNode* AVLTree::checkBalances(ZNode * n) {
    
    if (n == NULL) { //if node is NULL there isn't an imbalance 0 should be returned
        return NULL;
    } else {
        if (abs(getBalance(n)) == 2) { //if balance factor is 2 or -2, return imbalanced node
            return n;
        } else { //otherwise check the parent's parent for an imbalance
            checkBalances(n->parent);
        }
    }
}

/* getBalance(ZNode) - returns balance factor of node
 *                      
 * arguments:
 *          ZNode - node to calculate balance factor of
 * return:
 *          int - balance factor
 */
int AVLTree::getBalance(ZNode * n) {
    if (n != NULL) { //if node isn't null
        int leftHeight = ((n->left == NULL) ? 0 : n->left->height); //if left node is null return 0 as height, otherwise return height
        int rightHeight = ((n->right == NULL) ? 0 : n->right->height); //if right node is null return 0 as height, otherwise return height
        return (leftHeight - rightHeight); //return bf
    } else { //bf is 0 if node is null
        return 0;
    }
}

/* adjustHeights(ZNode) - adjusts the heights of nodes starting at the node and going to the root
 *                      
 *                        recursive function
 *                          adjusts height of node then calls function passing in parent
 * arguments:
 *          ZNode - node to start at (should be added node)
 * return: void
 */
void AVLTree::adjustHeights(ZNode * n) {
    if (n == NULL) { //stop condition, node doesn't exist
        return;
    } else { //stop condition not met
        //reassigns the height of the parent of the node
        //checks the left and right node to see if they are null to return height of 0
        //if nodes aren't null height field is used
        n->height = (max(((n->left == NULL) ? 0 : n->left->height),
                ((n->right == NULL) ? 0 : n->right->height))) + 1;
        adjustHeights(n->parent);
    }
}

/* rotateRight(ZNode) - rotates branch of tree right
 *                      
 * arguments:
 *          ZNode - node of imbalance
 * return: none
 */
void AVLTree::rotateRight(ZNode * n) {
    // rotates right around n
    ZNode* nleft = n->left; //stores n's left node as a temp variable

    nleft->parent = n->parent; //assign n's parent to nlefts parent

    //point parent to the node as the proper child
    if (n->parent == NULL) {
        root = nleft;
    } else if (n->parent->left == n) {
        nleft->parent->left = nleft;
    } else if (n->parent->right == n) {
        nleft->parent->right = nleft;
    }

    //node picks up lefts right node as left
    n->left = nleft->right;
    if (n->left != NULL) {
        n->left->parent = n; //update parent pointer
    }

    //assign node as lefts right
    nleft->right = n;
    n->parent = nleft;
    
    adjustHeights(n);
    
}

/* rotateLeft(ZNode) - rotates branch of tree left
 *                      
 * arguments:
 *          ZNode - node of imbalance
 * return: none
 */
void AVLTree::rotateLeft(ZNode * n) {
    // rotates left around n
    ZNode* nright = n->right; //stores n's right node as a temp variable

    nright->parent = n->parent; //assign n's parent to nrights parent

    //point parent to the node as the proper child
    if (n->parent == NULL) {
        root = nright;
    } else if (n->parent->left == n) {
        nright->parent->left = nright;
    } else if (n->parent->right == n) {
        nright->parent->right = nright;
    }

    //node picks up rights left node as right
    n->right = nright->left;
    if (n->right != NULL) {
        n->right->parent = n; //update parent pointer
    }

    //assign node as rights left
    nright->left = n;
    n->parent = nright;

    adjustHeights(n);
}

/* printIO(ZNode) - prints tree left node right
 *                      
 * arguments:
 *          ZNode - root
 * return: none
 */
void AVLTree::printIO(ZNode * root) {
    if (root == NULL) { //stop condition, node doesn't exist
        return;
    } else { //stop condition not met
        printIO(root->left); //print the left most node
        root->printZNode(); //print the root of the node
        printIO(root->right); //print the right node
    }
}

/* PrintPre(ZNode) - prints tree root left right
 *                      
 * arguments:
 *          ZNode - root
 * return: none
 */
void AVLTree::PrintPre(ZNode * root) {
    // print tree in preorder
    if (root == NULL) { //stop condition, node doesn't exist
        return;
    } else { //stop condition not met
        root->printZNode(); //print the root of the node
        PrintPre(root->left); //print the left most node
        PrintPre(root->right); //print the right node
    }
}

/* PrintPost(ZNode) - prints tree left right node
 *                      
 * arguments:
 *          ZNode - root
 * return: none
 */
void AVLTree::PrintPost(ZNode * root) {
    // print tree in postorder
    if (root == NULL) { //stop condition, node doesn't exist
        return;
    } else { //stop condition not met
        PrintPost(root->left); //print the left most node
        PrintPost(root->right); //print the right node
        root->printZNode(); //print the root node

    }
}
