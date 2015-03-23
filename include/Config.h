#ifndef CONFIG_H
#define CONFIG_H


class Config
{
    public:
        Config(int width, int height, int players, int stairs, int snakes);
        virtual ~Config();
        int getWidth();
        int getHeight();
        int getPlayers();
        int getSnakes();
        int getStairs();
    protected:
    private:
        int width, height, players, stairs, snakes;
};

#endif // CONFIG_H
