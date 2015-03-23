#ifndef SNAKE_H
#define SNAKE_H


class Snake
{
    public:
        Snake(int tail, int head);
        virtual ~Snake();
        int getHead();
        int getTail();
    protected:
    private:
        int head;
        int tail;
};

#endif // SNAKE_H
