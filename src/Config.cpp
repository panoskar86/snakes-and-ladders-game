#include "Config.h"
#include <iostream>

using namespace std;

Config::Config(int width, int height, int players, int stairs, int snakes)
{
    this->width = width;
    this->height = height;
    this->players = players;
    this->stairs = stairs;
    this->snakes = snakes;
}

int Config::getWidth(){
    return width;
}

int Config::getHeight(){
    return height;
}

int Config::getStairs(){
    return stairs;
}

int Config::getSnakes(){
    return snakes;
}

int Config::getPlayers(){
    return players;
}

Config::~Config()
{
    //dtor
}
