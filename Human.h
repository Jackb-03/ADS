#ifndef Human_h
#define Human_h
#include "/home/jack/ADS/Player.h"
#include<string>
#include<iostream>

class Human: public Player
{
private:
    /* data */
public:
    std::string name="Human";
    Human(std::string Name);
    ~Human();
    char makeMove();
    std::string getName();

};




#endif