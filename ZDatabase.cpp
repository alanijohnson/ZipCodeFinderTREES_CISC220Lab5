/* 
 * File:   ZDatabase.cpp
 * Author: Alani
 * 
 * Contains: ZDatabase methods to build database from zipcode file
 *           and methods to interact with data (access data)
 * 
 * Created on April 12, 2017, 8:20 PM
 */

#include "Z_Obj.hpp"
#include "ZNode.hpp"
#include "ZDatabase.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <istream>
using namespace std;

/* ZDatabase(string, bool) - constructor for ZDatabase class
 *          creates a binary search tree (balanced or unbalanced)
 *          reads in data from file
 *          enters retrieve data mode - user enters zip codes
 * 
 * arguments:
 *          string - filename - file that contains zipcode data
 *          bool - flag - determines whether or not tree is balanced
 *                  true - AVL Balanced Tree
 *                  false - Unbalanced Binary Search Tree
 */
ZDatabase::ZDatabase(string filename, bool flag) {
    ztree = new AVLTree(flag);  //create tree
    ifile = filename;
    readFile(); //read in data
    getZips();  //enter data retrieval mode
    
    //print tree
    cout << "In order: " << endl;
    ztree->printIO(ztree->root);
    cout << endl << "PreOrder:" << endl;
    ztree->PrintPre(ztree->root);
    cout << endl << "PostOrder:" << endl;
    ztree->PrintPost(ztree->root);
}

/* ZDatabase(string, bool) - constructor for ZDatabase class
 *          creates a binary search tree (balanced or unbalanced)
 *          reads in data from file
 *          enters retrieve data mode - user enters zip codes
 * 
 * arguments:
 *          string - filename - file that contains zipcode data
 *          bool - flag - determines whether or not tree is balanced
 *                  true - AVL Balanced Tree
 *                  false - Unbalanced Binary Search Tree
 */
ZDatabase::ZDatabase(string filename, string outfile, bool flag) {
    ztree = new AVLTree(flag);  //create tree
    ifile = filename;
    ofile = outfile;
    readFile(); //read in data
    getZips();  //enter data retrieval mode
    
    //print tree
    cout << "In order: " << endl;
    ztree->printIO(ztree->root);
    cout << endl << "PreOrder:" << endl;
    ztree->PrintPre(ztree->root);
    cout << endl << "PostOrder:" << endl;
    ztree->PrintPost(ztree->root);
}


/* getZips() - zipcode retrieval mode
 *          allows user to enter zipcode and prints data
 *          -1 terminates mode
 * 
 * arguments: none
 * return: none
 */
void ZDatabase::getZips() {
    //prompt user
    cout << "Enter a zip" << endl;
    int z;
    cin >> z;
    while (z > -1) { //-1 stop condition to end mode
        ZNode *x = ztree->findZip(z, ztree->root); //find zipcode within the data and save node
        if (x) { //if node isn't null prints node
            cout << endl;
            x->printZNode();
        } else { //prints error message if node is NULL
            cout << endl << z << " not found." << endl;
        }
        
        //ask for new zip code
        cout << "Enter a zip" << endl;
        cin >> z;
    }
}

/* readFile() - reads in data from file containing zipcode data
 * 
 * arguments: none
 * return: none
 */
void ZDatabase::readFile() {
    ifstream file(ifile.c_str());
    string line = "";
    string zip = "";
    string city = "";
    string county = "";
    string abbr = "";
    string state = "";
    string lats = "";
    string lons = "";
    getline(file, line);
    while (getline(file, line)) {
        unsigned int start = 0;
        unsigned int end = line.find('\t');
        if (end > start) {
            if (end != line.npos) {
                zip = line.substr(start, end - start);
                start = end + 1;
                end = line.find('\t', start);
            }
            if (end != line.npos) {
                city = line.substr(start, end - start);
                start = end + 1;
                end = line.find('\t', start);
            }
            if (end != line.npos) {
                state = line.substr(start, end - start);
                start = end + 1;
                end = line.find('\t', start);
            }
            if (end != line.npos) {
                abbr = line.substr(start, end - start);
                start = end + 1;
                end = line.find('\t', start);
            }
            if (end != line.npos) {
                county = line.substr(start, end - start);
                start = end + 1;
                end = line.find('\t', start);
            }
            if (end != line.npos) {
                lats = line.substr(start, end - start);
                start = end + 1;
                end = line.find('\t', start);
            }
            if (end != line.npos) {
                lons = line.substr(start, end - start);
            }
            float lat = atof(lats.c_str());
            float lon = atof(lons.c_str());
            int zz = atoi(zip.c_str());
            Z_Obj *z = new Z_Obj(zz, city, state, abbr, county, lat, lon);
            ztree->addNode(z, ztree->root);
        }
    }
}


