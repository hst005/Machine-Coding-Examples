#include <iostream>
#include"Ladder.h"
#include"Player.h"
#include"Snakes.h"
#include"GameSession.h"
using namespace std;
Ladder::Ladder(int start ,int to){
    this->start=start;
    this->to=to;
    this->LadderID=NoOfLadders++;


}

Player::Player(string name){
    this->name=name;
    this->id=NoOfPlayers++;
    this->pos=0;
}

Snakes::Snakes(int start ,int to){
    this->start=start;
    this->to=to;
    this->SnakeId=NoOfSnakes++;
}

GameSession::GameSession(){
    PlayersList.clear();
    LaddersList.clear();
    SnakesList.clear();
    winner=nullptr;
    Winnerfound=false;
}
int main()
{
    Player P1("Alan");
    Player P2("Jake");
    Player P3("Charlie");
    Ladder L1(10,20);
    Ladder L2(30,40);
    Ladder L3(40,50);
    Snakes S1(25,20);
    Snakes S2(65,60);
    Snakes S3(85,80);
    GameSession GS1;
    GS1.AddLadder(L1);
    GS1.AddLadder(L2);
    GS1.AddLadder(L3);
    GS1.AddSnake(S1);
    GS1.AddSnake(S2);
    GS1.AddSnake(S3);
    GS1.addPlayer(P1);
    GS1.addPlayer(P2);
    GS1.addPlayer(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);

    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);

    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);
    GS1.makeroll(P1);
    GS1.makeroll(P2);
    GS1.makeroll(P3);

    GS1.PrintAllPositions();
    cout<<"P1 pos "<<P1.Getpos();


    return 0;
}
