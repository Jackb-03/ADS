#include "Referee.h"
#include <iostream>
#include <string>
using namespace std;



Referee::Referee(/* args */)
{
}

Referee::~Referee()
{
}

Player* Referee::refGame(Player* player1, Player* player2){
    char move1 = player1->makeMove();
    char move2 = player2->makeMove();
    if(move1==move2){
        return nullptr;
    }
    else if(move1 == 'P'){
        return player1;
    }
    else if(move1 == 'S'){
        return player2;
    }

    return nullptr;
}