/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alani
 *
 * Created on April 12, 2017, 7:56 PM
 */

#include <stdlib.h>
#include <string>
#include "ZDatabase.hpp"
using namespace std;

int main() {
    string g = "zipcodesfile.txt";
    string h = "ziptestfile.txt"; // for testing purposes
    cout << "BINARY SEARCH TREE:" << endl << "__________________________" << endl;
    ZDatabase *zdb = new ZDatabase(g, "zipout.txt", false);
    //ZDatabase *zdb = new ZDatabase(h, false); 
    cout << endl << "AVL TREE:" << endl << "__________________________" << endl;
    ZDatabase *zdb2 = new ZDatabase(g, "zipout.txt", true);
    //ZDatabase *zdb2 = new ZDatabase(h, true);
    return 0;
}

