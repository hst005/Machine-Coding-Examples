#ifndef SNAKES_H
#define SNAKES_H
#include<string>
using namespace std;

static int NoOfSnakes=0;
class Snakes
{
    public:
        Snakes(int start,int to) ;

        int Getstart() { return start; }
        int Getto() { return to; }
        int GetSnakeId() { return SnakeId; }

    protected:

    private:
        int start;
        int to;
        int SnakeId;
};

#endif // SNAKES_H
