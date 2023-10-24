/*
Date: 2023/10/14
Author:Orlando Companioni
email:companor@sheridancollege.ca

This is the implementation file for the NameTag class
here all the member functions and standard functions are implemmented and the constructors and destructor

CITAIONS:

https://en.cppreference.com/w/cpp/string/basic_string/to_string :   I used the to_string to convert the int into a string
This way it would be easier for me to convert it into a c string using the function 
and then change it to N/A if needed 
 
//c_str converts the string into a c string I learned this in class

*/

#include <iostream> 
#include <cstring>
#include <string>
#include "NameTag.h"

#define CRT_SECURE_NO_WARNINGS
using namespace std;
namespace fast{

NameTag::NameTag(){
    tag_name=nullptr;
}//end of no arg constructor

NameTag::NameTag(const char* name){
    if(name!=nullptr){
        tag_name=new char[MAX];
        strcpy(tag_name, name);
        strcpy(tag_number, "N/A");
    }
    else{
    tag_name=nullptr;
    hasEmpty=true;
    }
    
}//end of no arg constructor

NameTag::NameTag(const char* name, const int extenNumber){
    string stuNum;
    if (name!=nullptr){
        tag_name=new char[MAX];
        strcpy(tag_name, name);
        if(extenNumber>=10000 && extenNumber<=99999){
            stuNum=to_string(extenNumber);//setting what we get from the function into a string
            strcpy(tag_number, stuNum.c_str()); //c_str converts the string into a c string");
        }
        else{
            hasEmpty=true;
        }
        
    }
    else{
        hasEmpty=true;
    }
}//end of overloaded constructor

NameTag::NameTag(const char* name, const char *extenNumber){
    if (name!=nullptr){
        tag_name=new char[MAX];
        strcpy(tag_name, name);
        if(extenNumber!=nullptr){
            strcpy(tag_number, extenNumber);
        }
        else{
            strcpy(tag_number, "N/A");
        }
        
    }
    else{
        tag_name=nullptr;
        tag_number[0]='\0';
    }
}//end of overloaded constructor

void NameTag::setName(char* name){
    if (name!=nullptr){
        tag_name=new char[MAX];
        strcpy(tag_name, name);
    }
    else{
        tag_name=nullptr;
        hasEmpty=true;
    }
}//end of setName

void NameTag::setStudentNumber(char* extenNumber){
    if (extenNumber!=nullptr){
        strcpy(tag_number, extenNumber);
    }
    else{
        strcpy(tag_number, "N/A");
    }

}//end of setStudentNumber


NameTag::~NameTag(){
    delete [] tag_name;     //memory is deallocated here
    tag_name=nullptr; 
}//end of destructor

void NameTag::setEmpty(){
    tag_name=nullptr;
    tag_number[0]='\0';
    hasEmpty=false;
}

std::ostream& NameTag::print(){
    std::ostream& COUT=std::cout;
    char temp[41];
    if (tag_name!=nullptr){
        int size=strlen(tag_name);
        if (size>39){
            strncpy(temp, tag_name, 40);
            temp[40]='\0';
            strcpy(tag_name, temp);
        }
    if(hasEmpty==false){
        if (size<MIN){
            drawline();
            for(int i=0;i<5;i++){
                if(i==1){
                    COUT<<"| ";
                    COUT.width(20);
                    COUT<<left<<tag_name;
                    COUT<<right;
                    COUT<<" |"<<endl;
                }
                else if(i==3){
                    COUT<<"| ";
                    COUT<<left<<"Extention: ";
                    COUT.width(9);//was 20
                    COUT<<left<<tag_number;
                    COUT<<right;
                    COUT<<" |"<<endl;
                }
                else{
                    COUT<<"| ";
                    COUT.width(22);
                    COUT.fill(' ');
                    COUT<<" |"<<endl;
                }
            }
            drawline();
        }
        else{
            drawLongline();
            for(int i=0;i<5;i++){
                if(i==1){
                    COUT<<"| ";
                    COUT.width(41);
                    COUT<<left<<tag_name;
                    COUT<<right;
                    COUT<<"|"<<endl;
                }
                else if(i==3){
                    COUT<<"| ";
                    COUT<<left<<"Extention: ";
                    COUT.width(30);// was 41
                    COUT<<left<<tag_number;
                    COUT<<right;
                    COUT<<"|"<<endl;
                }
                else{
                    COUT<<'|';
                    COUT.width(43);
                    COUT<<'|'<<endl;
                }
            }
            drawLongline();
            }
        }
    }
    if(hasEmpty==true){
        cout<<"EMPTY NAMETAG!"<<endl;
    }
    return COUT;
}//end of displayTag

NameTag& NameTag::read(){
    char temp[41];
    char fullBufer[70];
    char choice;
    string stuNum;
    bool flag=false;
    char extenNumber[6];
    while(flag==false){
        cout<<"Please enter the name: ";
        noName: //jump statement to go back if the name is empty
        cin.getline(fullBufer, 1000);
        strncpy(temp, fullBufer, 40);
        temp[40]='\0'; //adding the null terminator

        if(temp[0]=='\0'){
            goto noName; //will jump where it can get user info again.
        }
        else{
            flag=true;
        }
    }
    if (temp[0]!='\0'){
        if (choiceGetter()==1){
            stuNum=to_string(numGetter());//setting what we get from the function into a string
            strcpy(extenNumber, stuNum.c_str()); //c_str converts the string into a c string
        }
        else{
            strcpy(extenNumber, "N/A");
        }
    }
    NameTag* user1 = new NameTag(temp, extenNumber);
    return *user1;
}//end of read


void drawline(){
    cout<<"+----------------------+"<<endl;
    
}//end of drawline

void drawLongline(){
    cout<<"+------------------------------------------+"<<endl;
}//end of drawLongline


int numGetter(){
    int extenNumber;
    bool flag = false;
    cout << "Please enter a 5 digit phone extension: ";
    while(!flag){
        cin >> extenNumber;
        if(cin.fail()){  // cin.fail() checks to see if the value in the cin stream is the correct type, if not it returns true, false otherwise.
            cout << "Bad integer value, try again: ";
            cin.clear(); // clear the error
            cin.ignore(1000, '\n'); // clear buffer
        }
        else if(extenNumber < 10000 || extenNumber > 99999){
            cout << "Invalid value [10000<=value<=99999]: ";
            cin.clear(); // clear the error
            cin.ignore(1000, '\n'); // clear buffer
        }
        else{
            flag = true;
        }
    }
    return extenNumber;
}//end of numGetter

int choiceGetter(){
    int choice;
    int choiceSize;
    char userChoice[5];
    bool flag = false;
    cout << "Would you like to enter an extension? (Y/N): ";
    while(flag==false){
        cin >> userChoice;
        choiceSize=strlen(userChoice);
        if(choiceSize>1){
            cout<<"Only (Y) or (N) are acceptable, try again: ";
            cin.clear(); // clear the error
            cin.ignore(1000, '\n'); // clear buffer
        }
        else if(choiceSize==1){
            if (userChoice[0]== 'Y' || userChoice[0]== 'y'){
                cin.ignore(1000, '\n'); // clear buffer
                choice = 1;
                flag = true;
                
            }
            else if(userChoice[0] == 'N' || userChoice[0] == 'n'){
                cin.ignore(1000, '\n'); // clear buffer
                choice = 0;
                flag = true;
            }
            else{
                cout << "Only (Y) or (N) are acceptable, try again: ";
                cin.clear(); // clear the error
                cin.ignore(1000, '\n'); // clear buffer
            }
    }
    }
    return choice;
}//end of choiceGetter



}//end of namespace fast