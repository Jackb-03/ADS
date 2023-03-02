#include "Human.h"
#include <iostream>
#include <string>
using namespace std;
Human::Human(/* args */)
{
}

Human::~Human()
{
}

char Human::makeMove(){
    char move;
    cout<< "Enter move: ";
    cin >> move; 
    while(move != 'R' && move != 'P' && move != 'S'){
            cout<< "Please enter 'R', 'P', 'S' ";
            cin >> move; 
    }
        return move;
}

string Human::getName(){
    string name;
    cout<< "Please enter a name";
    cin>>name;
    if(name ==""){
        name = "Human";
    }
    return name;


}




