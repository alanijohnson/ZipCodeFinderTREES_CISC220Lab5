
/* 
 * File:   Z_Obj.cpp
 * Author: Alani
 * 
 * contains methods necessary to store zipcode data
 * 
 * Created on April 12, 2017, 7:58 PM
 */

#include "Z_Obj.hpp"

/* Z_Obj(int z, string ct, string st, string ab, string cnty, float la, float lo) - constructor of Z_Obj
 *                stores zip code data
 * arguments:
 *           int - zip code
 *           string - county
 *           string - state
 *           string - state abbreviation
 *           float - latitude
 *           float - longitude
 */
Z_Obj::Z_Obj(int z, string ct, string st, string ab, string cnty, float la, float lo) {
    zip = z;
    city = ct;
    state = st;
    abbr = ab;
    county = cnty;
    lat = la;
    lon = lo;
}

void Z_Obj::printZ() {
    //didn't need methods
}

bool Z_Obj::lessThan(Z_Obj* z){
    //didn't need methods
}


/* operator<(Z_Obj, Z_Obj) - overides < used to compare the zipcodes within Z_Obj
 * arguments: 
 *          Z_Obj - node before operator
 *          Z_Obj- node after operator
 * return: bool - true if first Z_Obj's zip (zipcode) is less than second Z_Obj's zip (zipcode)
 */
bool operator<(Z_Obj &z, Z_Obj &y){
    if (z.zip<y.zip){
        return true;
    } else {
        return false;
    }
}

/* operator<<(ostream, Z_Obj) - overides << used to print Z_Obj data
 * arguments: 
 *          ostream
 *          Z_Obj - zipcode data object to print
 */
ostream& operator<<(ostream& os, const Z_Obj& z){
    cout << z.zip << ", " << z.city << ", " << z.state << ", " << z.abbr << ", "
            << z.county << ", " << z.lat << " " << z.lon << endl;
}


