#include "Computer.h"
#include <iostream>
#include <string>
using namespace std;

Computer::Computer(/* args */)
{
}

Computer::~Computer()
{
}

string Computer::getName(){
    return "Computer";
}

char Computer::makeMove(){
    return 'R';
}