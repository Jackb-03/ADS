#ifndef Move_h
#define Move_h
#include <string>
#include <vector>
#include "Referee.h"


class Move
{
private:
public:
    std::string moveName;
    std::vector<Move> weakness;

    Move(std::string name){
        moveName = name;
    };

    void tellRefMoves(Move move, Referee name);

    void addWeakness(Move weakness);

    std::string getName()

    ~Move();

    
};






#endif