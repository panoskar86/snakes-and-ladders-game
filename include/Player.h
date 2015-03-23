#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
    public:
        Player();
        virtual ~Player();
        std::string getName();
        void setName(std::string playerName);
        void setPosition(int pos);
        int getPosition();
    protected:
    private:
        std::string name;
        int position;
};

#endif // PLAYER_H
