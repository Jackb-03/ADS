#include "Referee.h"
#include "Move.h"
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
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();
    if(move1==move2){
        return nullptr;
    }
    for(int i = 0; i<move1->weakness.size();i++){}
     

    return nullptr;
}