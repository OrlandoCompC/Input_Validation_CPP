/*
Date: 2023/10/14
Author:Orlando Companioni
email:companor@sheridancollege.ca

This is the header file for the NameTag class
*/
#ifndef NAMETAG_H
#define NAMETAG_H
#pragma once
#include <iostream>
#include <cstring>
const int MAX=41; // 1 FOR NULL TERMINATOR
const int MIN=20;

namespace fast{

class NameTag{
    char *tag_name;
    char tag_number[6];
    bool hasEmpty=false;

    public:
    //member functions
    std::ostream& print();
    NameTag& read();

    //constructors and destructor
    NameTag();
    NameTag(const char* name);
    NameTag(const char* name, const int extenNumber);
    NameTag(const char* name, const char* extenNumber); //overloaded constructor
    ~NameTag();

    //getter and setter
   void setName( char* name);
   void setStudentNumber(char* extenNumber);
   void setEmpty(); //set empty to true


};

void drawline();
int numGetter();
void drawLongline();
int choiceGetter();
char namecheck();



}//end of namespace fast

#endif