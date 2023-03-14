#include "Player.h"
#include "Move.h"

class Referee
{
private:
public:
    vector<Move> knownMoves;

    Referee(/* args */);
    ~Referee();
    Player* refGame(Player* player1, Player* player2);
};


