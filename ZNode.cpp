
/* 
 * File:   Z_NODE.cpp
 * Author: Alani
 * 
 * Contains: Methods to create nodes
 * 
 * Created on April 12, 2017, 8:17 PM
 */

#include "ZNode.hpp"

/* ZNode(Z_Obj) - constructor of ZNode
 *                stores data
 *                initializes height, left, right, and parent
 * arguments:
 *          Z_Obj - Zipcode object contains node data
 */
ZNode::ZNode(Z_Obj *z){
    zipO = z;
    height = 1;
    left = NULL;
    right = NULL;
    parent = NULL;
}

/* ZNode() - constructor of ZNode
 *                initializes Z_Obj height, left, right, and parent
 * arguments: none
 */
ZNode::ZNode(){
    zipO = NULL;
    height = 1;
    left = NULL;
    right = NULL;
    parent = NULL;
}

/* printZNode() - prints the Node and the data stored in ZipO
 * arguments: none
 * return: none
 */
void ZNode::printZNode(){
    cout << height << ":" << *zipO; 
}

/* operator<(ZNode, ZNode) - overides < used to compare the Z_Obj within nodes
 * arguments: 
 *          ZNode - node before operator
 *          ZNode - node after operator
 * return: bool - true if first node's zipO is less than second node's zipO
 */
bool operator<(ZNode &z, ZNode &y){
    if (z.zipO<y.zipO){
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream& os, const ZNode& z){
    //cout << *(z.zipO);
    //cout << "fix" << endl;
    //cout << zipO->zip << ", ";
}
