#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
class Player
{
private:

public:
    Player(/* args */);
    ~Player();
    virtual char makeMove()=0;
    std::string getName(std::string name){};
};



#endif