#include "Snake.h"

Snake::Snake(int tail, int head)
{
    this->tail=tail;
    this->head=head;
}

int Snake::getHead(){
    return head;
}

int Snake::getTail(){
    return tail;
}

Snake::~Snake()
{
    //dtor
}
