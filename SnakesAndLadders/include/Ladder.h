#ifndef LADDER_H
#define LADDER_H

static int NoOfLadders=0;
class Ladder
{
    public:
        Ladder(int start,int to);

        int Getstart() { return start; }
        int Getto() { return to; }
        int GetLadderID() { return LadderID; }

    protected:

    private:
        int start;
        int to;
        int LadderID;
};

#endif // LADDER_H
