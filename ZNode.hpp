/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Z_NODE.hpp
 * Author: Alani
 *
 * Created on April 12, 2017, 8:17 PM
 */

#ifndef ZNODE_HPP_
#define ZNODE_HPP_
#include "Z_Obj.hpp"
#include <string>
#include <cstdlib>
using namespace std;

class ZNode {
    friend class AVLTree;
    Z_Obj *zipO; //changed from zip to zipO
    int height; // max(left->height,right->height) + 1
    ZNode *left;
    ZNode *right;
    ZNode *parent;
public:
    ZNode(Z_Obj *z);
    ZNode();
    //prints the zipcode associated with the node
    void printZNode();
    //compares nodes by comparing Z_Obj
    friend bool operator<(ZNode &z, ZNode &y);
    friend ostream& operator<<(ostream& os, const ZNode& z);
};
#endif /* ZNODE_HPP_ */

