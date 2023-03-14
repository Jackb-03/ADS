#include "Move.h"
#include "Referee.h"
#include <string>
#include <iostream>
using namespace std;
Move::Move(string moveName)
{
    this->moveName = moveName;
};

void Move::tellRefMoves(Move move, Referee name)
{
    name.knownMoves.push_back(move);
    
};

void Move::addWeakness(Move weakness)
{
    this->weakness.push_back(weakness);
    
};

std::string getName(){
        return this->moveName;
    };


Move::~Move()
{
}