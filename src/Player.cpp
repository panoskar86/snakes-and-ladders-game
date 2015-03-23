#include "Player.h"
#include <string>
#include <iostream>

Player::Player()
{
    this->position=0;
}

void Player::setName(std::string playerName){
    name = playerName;
}

std::string Player::getName(){
    return name;
}

void Player::setPosition(int pos){
    position = pos;
}

int Player::getPosition(){
    return position;
}

Player::~Player()
{
    //dtor
}
