#include "Fidaki.h"
#include <iostream>
#include "Player.h"
#include <stdlib.h>
#include <limits>
#include <time.h>

using namespace std;

Fidaki::Fidaki(int a)
{
   cout << "Map width:";
   cin >> width;
   cout << "Map height:";
   cin >> height;
   cout << "Number of players:";
   cin >> numberOfPlayers;
   cout << "Number of snakes:";
   cin >> numberOfSnakes;
   cout << "Number of stairs:";
   cin >> numberOfStairs;

   srand((unsigned)(time(0)));

   length = width * height;

   //Init players
   for (int i = 0; i < numberOfPlayers; i++){
        cout << "Give name for player " << i + 1 << " : ";
        string name;
        cin >> name;
        players.push_back(Player());
        players.at(i).setName(name);
   }

   //Init stairs
   for (int i = 0; i < numberOfStairs; i++){
        int start = randomInRange(1,length);
        int end = randomInRange(start, length);
        stairs.push_back(Stair(start,end));
        cout << "Stair from "<< stairs.at(i).getStart() << " to " << stairs.at(i).getEnd() << endl;
   }
   //Init snakes
   for (int i = 0; i < numberOfSnakes; i++){
        int head = randomInRange(1,length);
        int tail = randomInRange(1, head);
        snakes.push_back(Snake(tail, head));
        cout << "Snake from "<< snakes.at(i).getTail() << " to " << snakes.at(i).getHead() << endl;
   }
}

Player Fidaki::getPlayer(int i){
    return players[i];
}

int Fidaki::dice(){
    return randomInRange(1,6);
}

bool Fidaki::checkIfStairExists(int position){
    for(int i=0;i<stairs.size();i++){
        if(position == stairs.at(i).getStart()){
            return true;
        }
    }
    return false;
}

bool Fidaki::checkIfSnakeHeadExists(int position){
    for(int i=0;i<snakes.size();i++){
        if(position == snakes.at(i).getHead()){
            return true;
        }
    }
    return false;
}

int Fidaki::getEndLocationOfStairStartingAt(int start){
    for(int i=0;i<stairs.size();i++){
        if(start == stairs.at(i).getStart()){
            return stairs.at(i).getEnd();
        }
    }
}

int Fidaki::getTailOfSnake(int head){
    for(int i=0;i<snakes.size();i++){
        if(head == snakes.at(i).getHead()){
            return snakes.at(i).getTail();
        }
    }
}

bool Fidaki::nextMove(){
    for(int i=0;i<players.size();i++){
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        int d = dice();
        cout << "Dice for player " << players.at(i).getName() << " equals " << d ;
        players.at(i).setPosition(players.at(i).getPosition() + d);
        cout << ". New position: " << players.at(i).getPosition() ;
        if(checkIfSnakeHeadExists(players.at(i).getPosition())){
            players.at(i).setPosition(getTailOfSnake(players.at(i).getPosition()));
            cout << " New position after beign eaten by a snake: " << players.at(i).getPosition() ;
        }
        else if(checkIfStairExists(players.at(i).getPosition())){
            players.at(i).setPosition(getEndLocationOfStairStartingAt(players.at(i).getPosition()));
            cout << " New position after using a stair: " << players.at(i).getPosition() ;
        }
        if(players.at(i).getPosition() >= length){
            cout << endl << "GAME OVER: " << players.at(i).getName() << " is the WINNER!";
            return false;
        }
    }
    return true;
}

Fidaki::~Fidaki()
{
    //dtor
}

int Fidaki::randomInRange (int min, int max)
{
   int r = min + (rand() % (int)(max - min + 1));
   return r;
}
