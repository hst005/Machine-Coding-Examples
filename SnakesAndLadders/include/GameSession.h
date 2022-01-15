#ifndef GAMESESSION_H
#define GAMESESSION_H
#include<vector>
using namespace std;

class GameSession
{
    public:
        GameSession();

         vector <Player> &GetPlayersList() { return PlayersList; }
        void SetPlayersList(vector <Player> val) { PlayersList = val; }
        vector <Ladder> GetLaddersList() { return LaddersList; }
        void SetLaddersList(vector <Ladder> val) { LaddersList = val; }
        vector <Snakes> GetSnakesList() { return SnakesList; }
        void SetSnakesList(vector <Snakes> val) { SnakesList = val; }
        void addPlayer(Player &a);
        void AddLadder(Ladder &l);
        void AddSnake(Snakes &s);
        void makeroll(Player &P1);
        void PrintAllPositions();
        Player *winner;
        bool Winnerfound;
    protected:

    private:

        vector <Player> PlayersList;
        vector <Ladder> LaddersList;
        vector <Snakes> SnakesList;
};
void GameSession::addPlayer(Player &a)
{
    PlayersList.push_back(a);
}

void GameSession::AddLadder(Ladder &l)
{
    LaddersList.push_back(l);
}

void GameSession::AddSnake(Snakes &s)
{
    SnakesList.push_back(s);
}
void GameSession::makeroll(Player& P1)
{
    if(winner!=nullptr){
        return ;
    }
    int CurPos=P1.Getpos();
    int NewPos=P1.roll();
    if(NewPos==-1){
        cout<<"Exceeds 100"<<endl;
        return;
    }
    if(NewPos==100){
        cout<<"Winner Found "<<P1.Getid()<<endl;
        winner=&P1;
        return ;
    }
    for(auto i:SnakesList){
        if(i.Getstart()==NewPos){
            NewPos=i.Getto();
            cout<<"Snake hit so coming from "<<i.Getstart()<<" to "<<i.Getto()<<endl;
            break;
        }
    }
    for(auto i:LaddersList){
        if(i.Getstart()==NewPos){
            NewPos=i.Getto();

            cout<<"Ladder hit so going from "<<i.Getstart()<<" to "<<i.Getto()<<endl;
            break;
        }
    }
    P1.Setpos(NewPos);
    cout<<"Player No "<<P1.Getid()<<" new pos is "<<P1.Getpos()<<endl;
}
void GameSession::PrintAllPositions()
{
  //  vector <Player> *templist=&GetPlayersList();
    //for(Player i:PlayersList){
      //  cout<<"Player No "<< i.Getid()<<" is at position "<<i.Getpos()<<endl;
    //}
   /* cout<<PlayersList.size()<<endl;
    for(int i=0;i<PlayersList.size();i++){
        cout<<"Player No "<< PlayersList[i].Getid()<<" is at position "<<PlayersList[i].Getpos()<<endl;
    }*/
    //vector <Player> *templist=&GetPlayersList();
    //for(auto i:*templist){
      //      cout<<"Player No "<< i.Getid()<<" is at position "<<i.Getpos()<<endl;
       // }
      // vector <int>::iterator itr=PlayersList.begin();
      // for(itr;itr!=PlayersList.end();itr++){
       //     cout<<"Player No "<< itr->Getid()<<" is at position "<<i->Getpos()<<endl;
      // }

}

#endif // GAMESESSION_H
