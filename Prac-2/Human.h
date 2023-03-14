#ifndef Human_h
#define Human_h
#include "Player.h"
#include "Move.h"

#include<string>
#include<iostream>

class Human: public Player
{
private:
    /* data */
public:
    std::string name="Human";
    
    Human();
    Human(std::string ref);
    ~Human();
    Move * makeMove(Referee name);
    std::string getName();

};




#endif