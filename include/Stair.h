#ifndef STAIR_H
#define STAIR_H


class Stair
{
    public:
        Stair(int start, int end);
        virtual ~Stair();
        int getStart();
        int getEnd();
    protected:
    private:
        int start,end;
};

#endif // STAIR_H
