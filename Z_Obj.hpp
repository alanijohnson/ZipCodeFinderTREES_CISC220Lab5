/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Z_Obj.hpp
 * Author: Alani
 *
 * Created on April 12, 2017, 7:58 PM
 */

#ifndef Z_OBJ_HPP_
#define Z_OBJ_HPP_
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Z_Obj {
    friend class ZNode;
    friend class AVLTree;
    int zip;
    string city;
    string state;
    string abbr;
    string county;
    float lat;
    float lon;
public:
    Z_Obj(int z, string ct, string st, string ab, string cnty, float la, float lo);
    void printZ();
    friend ostream& operator<<(ostream& os, const Z_Obj& z);
    // If you want to override << so you can just use cout to print your Z_Objs.
    bool lessThan(Z_Obj *z);
    //compares Z_Obj using zip field
    friend bool operator<(Z_Obj &z, Z_Obj &y);
};
#endif /* Z_OBJ_HPP_ */
