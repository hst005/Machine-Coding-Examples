#ifndef USERS_H
#define USERS_H

#include<vector>
#include<string>
using namespace std;
static int NoOfUsers=0;
class Users
{
    public:
        //Users() {}
        Users(string name);
        int GetUserId() { return UserId; }
        string Getname() { return name; }
        int GetAmtOwed() { return AmtOwed; }
        void SetAmtOwed(int val) { AmtOwed = val; }
        void UpdateBalance(Users *TransWith,int amt);
        void GetAllBalances();
    protected:

    private:
        int UserId;
        string name;
        int AmtOwed;
        vector<double> AllBalances;
};

void Users::UpdateBalance(Users *TransWith,int amt){
    int NoOfFriends=AllBalances.size();

    int TransWithUserID=TransWith->GetUserId();
    for(int i=NoOfFriends;i<TransWithUserID+1;i++){
        AllBalances.push_back(0);
    }
    AllBalances[TransWithUserID]+=amt;

}

void Users::GetAllBalances(){
    int NoOfFriends=AllBalances.size();
    for(int i=0;i<NoOfFriends;i++){
        cout<<AllBalances[i]<<endl;
    }
}
Users::Users(string name)
{
    this->name=name;
    this->UserId=NoOfUsers++;
    AmtOwed=0;
    AllBalances.clear();
}


#endif // USERS_H


/*
User1 User2 User3
TotalAmountShared=1000
PaidBy User1

User2 USer3
amt=100
Paidby user2
show();
user=667

*/

