#include "Stair.h"

Stair::Stair(int start, int end)
{
    this->start=start;
    this->end=end;
}

int Stair::getStart(){
    return start;
}

int Stair::getEnd(){
    return end;
}

Stair::~Stair()
{
    //dtor
}
