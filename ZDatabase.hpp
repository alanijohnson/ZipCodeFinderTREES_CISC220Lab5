
/* 
 * File:   ZDatabase.hpp
 * Author: Alani
 * 
 * Contains: Header file for ZDatabase.cpp
 *          
 * Created on April 12, 2017, 8:20 PM
 */

#ifndef ZDATABASE_HPP_
#define ZDATABASE_HPP_
#include "Z_Obj.hpp"
#include "ZNode.hpp"
#include "AVLTree.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

class ZDatabase {
    string ifile;
    string ofile;
    AVLTree *ztree;
public:
    //Constructor for Database
    ZDatabase(string filename, bool flag);
    //Constructor for Database
    ZDatabase(string filename, string outname, bool flag);
    //reads in text file of zip codes, file should contain zipcodes separated by tabs
    void readFile();
    //find zip code in database and print pertinent information
    void getZips();
};
#endif /* ZDATABASE_HPP_ */

