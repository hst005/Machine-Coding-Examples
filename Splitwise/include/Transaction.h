#ifndef TRANSACTION_H
#define TRANSACTION_H
#include"Users.h"
static int NoOfTransactions=0;
enum TransactionType{Equally,Exactly};
class Transaction
{
    public:
        Transaction() {}
        Transaction(int Amt,Users *PaidBy,vector <Users*> AmongUsers,TransactionType TType,string description);

        Transaction(int Amt,Users *PaidBy,vector <Users*> AmongUsers,TransactionType TType,string description,vector <int> share);
        TransactionType GetTType() { return TType; }
        vector <Users*> GetAmongUsers() { return AmongUsers; }
        void SetAmongUsers(vector <Users*> val) { AmongUsers = val; }
        vector <int> GetShare() { return Share; }
        int GetTId(){ return TId;}
        int GetAmt(){ return Amt;}
        string Getdescription(){return description;};
        void Setdescription(string val){description=val;}
        bool CheckValidInput(int Amt,vector <int> &share,int UsersInvolved);
    protected:

    private:
        TransactionType TType;
        vector <Users*> AmongUsers;
        vector <int> Share;
        int Amt;
        Users *PaidBy;
        string description;
        int TId;
};
Transaction::Transaction(int Amt, Users* PaidBy, vector<Users*>AmongUsers, TransactionType TType, string description="")
{
    this->Amt=Amt;
    this->PaidBy=PaidBy;
    this->AmongUsers=AmongUsers;
    this->TType=TType;
    this->description=description;
    Share.clear();
    int UsersInvolved=AmongUsers.size();
    double AmtChange=Amt/UsersInvolved;
    for(int i=0;i<UsersInvolved;i++){
        //User CurrUser=*AmongUsers[i];
        if(AmongUsers[i]->GetUserId()==PaidBy->GetUserId()){
            for(int j=0;j<UsersInvolved;j++){
                if(i!=j){
                    AmongUsers[j]->UpdateBalance(AmongUsers[i],-1*AmtChange);
                    AmongUsers[i]->UpdateBalance(AmongUsers[j],AmtChange);
                }
            }
        }
    }
}
bool Transaction::CheckValidInput(int Amt,vector <int> &share,int UsersInvolved){
    int sum=0;
    for(int i=0;i<UsersInvolved;i++){
        sum+=share[i];
    }
    if(sum==Amt){
        return true;
    }
    else{
        return false;
    }
}
Transaction::Transaction(int Amt, Users* PaidBy, vector<Users*>AmongUsers, TransactionType TType, string description, vector<int>share)
{
    this->Amt=Amt;
    this->PaidBy=PaidBy;
    this->AmongUsers=AmongUsers;
    this->TType=TType;
    this->Share=share;
    this->description=description;
    int UsersInvolved=AmongUsers.size();
    if(!CheckValidInput(Amt,share,UsersInvolved)){
        cout<<"Invalid Input"<<endl;

    }
    else{
    for(int i=0;i<UsersInvolved;i++){
        //int CurrUser=*AmongUsers[i];
        if(AmongUsers[i]->GetUserId()==PaidBy->GetUserId()){
            for(int j=0;j<UsersInvolved;j++){
                if(i!=j){
                    int AmtChange=share[j];
                    AmongUsers[j]->UpdateBalance(AmongUsers[i],-1*AmtChange);
                    AmongUsers[i]->UpdateBalance(AmongUsers[j],AmtChange);
                }
            }
        }
    }
    }
}

#endif // TRANSACTION_H
