#ifndef FIDAKI_H
#define FIDAKI_H
#include "Config.h"
#include <iostream>
#include "Player.h"
#include "Snake.h"
#include <vector>
#include "Stair.h"

class Fidaki
{
    public:
        Fidaki(int a);
        virtual ~Fidaki();
        Player getPlayer(int i);
        bool nextMove();
    protected:
    private:
        std::vector<Player> players;
        std::vector<Stair> stairs;
        std::vector<Snake> snakes;
        int randomInRange( int min,  int max);
        int dice();
        int length;
        bool checkIfStairExists(int position);
        int getEndLocationOfStairStartingAt(int start);
        int getTailOfSnake(int head);
        bool checkIfSnakeHeadExists(int position);
        int width,height,numberOfPlayers,numberOfSnakes,numberOfStairs;
};

#endif // FIDAKI_H
