#include "Player.h"
#include "Referee.h"
#include "Human.h"
#include "Computer.h"
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{

    Computer* c;
    string computerN = c->getName();
    Human* h;
    string humanN = h->getName();
    Referee r;

    Player* winner;
    winner = r.refGame(h, c);

    if(winner == h){
        cout<<humanN<< " Wins";
    }
    else if(winner == c){
        cout<<computerN<< " Wins";
    }
    else{
        cout<<"Draw";
    }



    return 0;
}
