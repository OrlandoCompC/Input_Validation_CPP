/*
Date: 2023/10/14
Author:Orlando Companioni
email:companor@sheridancollege.ca

This is the main file for the part 2 of the assignment. This program will create 6 NameTag objects 
and then it will print them out.
Then it will ask the user to enter a name and a number and it will create a NameTag object 
with the user input and then it will print it out.
*/

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "NameTag.h"

using namespace std;
using namespace fast;

int main() {
    NameTag nt[6] = {
       "A very very very long name to be cut short!!!", // one argument constructor
       {"Fred Soley", 12345} ,       // two argument constructor with good data
       {nullptr, 23456},    // two argument constructor with bad name
       {"Bad number", 1234},  // two argument constructor with bad number
       {"Bad number", 123456}  // two argument constructor with bad number
       // default constructor (sixth element)
    };
    int i;
    for (i = 0; i < 6; i++) {
        nt[i].print();
        cout << endl;
    }
    
    nt[1].read().print();
    nt[3].read().print();
    nt[5].read().print();
    return 0;
}//end of main