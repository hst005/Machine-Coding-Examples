#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include <stdlib.h>
#include<time.h>
using namespace std;

static int NoOfPlayers=0;
class Player
{
    public:
        Player(string);

        string Getname() { return name; }
        int Getid() { return id; }
        int Getpos() { return pos; }
        void Setpos(int val) { pos = val; }
        bool operator==(Player &a);
        int roll();
    protected:

    private:
        string name;
        int id;
        int pos;
};
bool Player::operator==(Player& a)
{
        if(this->Getid()==a.Getid()){
            return true;
        }

        return false;
}

int Player::roll()
{
    int DiceNo=(rand()%6)+1;
    cout<<"No rolled out is "<<DiceNo<<endl;
    int PossiblePos=pos+DiceNo;
    if(PossiblePos>100){
        return -1;
    }

    return PossiblePos;

}

#endif // PLAYER_H
