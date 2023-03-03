#include "Human.h"
#include <iostream>
#include <string>
using namespace std;

Human::Human()
{
    
}


Human::Human(string name)
{
    this->name = name;
}

Human::~Human()
{
}

char Human::makeMove(){
    char move;
    cout<< "Enter move: ";
    cin >> move; 
    while(move != 'R' && move != 'P' && move != 'S'){
            cout<< "Enter move: ";
            cin >> move; 
    }
        return move;
}

string Human::getName(){
    return this->name;



}




