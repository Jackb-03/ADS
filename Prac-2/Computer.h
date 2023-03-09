#ifndef Computer_h
#define Computer_h
#include "Player.h"
#include<string>
#include<iostream>


class Computer: public Player
{
private:
    /* data */
public:
    Computer(/* args */);
    ~Computer();
    char makeMove();
    std::string getName();
    
};



#endif