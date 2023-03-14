#ifndef Computer_h
#define Computer_h
#include "Player.h"
#include "Move.h"

#include<string>
#include<iostream>


class Computer: public Player
{
private:
    /* data */
public:
    Computer(/* args */);
    ~Computer();
    Move * makeMove();
    std::string getName();
    
};



#endif