#ifndef SPLITWISE_H
#define SPLITWISE_H
#include"Users.h"
#include"Transaction.h"

class Splitwise
{
    public:
        //Splitwise() {}

        vector <Transaction> GetTransactionList() { return TransactionList; }
        void SetTransactionList(vector <Transaction> val) { TransactionList = val; }
        vector <Users*> GetAllUsers() { return AllUsers; }
        void SetAllUsers(vector <Users*> val) { AllUsers = val; }
        void PerformOperation(int Amt,Users *PaidBy,vector <Users*> AmongUsers,TransactionType TType,string description);
        void PerformOperation(int Amt,Users *PaidBy,vector <Users*> AmongUsers,TransactionType TType,string description,vector <int> share);
        void PrintAllBalances();

    protected:

    private:
        vector <Transaction> TransactionList;
        vector <Users*> AllUsers;

};
void Splitwise::PerformOperation(int Amt, Users* PaidBy, vector<Users*>AmongUsers, TransactionType TType, string description)
{
    Transaction T1(Amt,PaidBy,AmongUsers,TType,description);
    TransactionList.push_back(T1);
}

void Splitwise::PerformOperation(int Amt, Users* PaidBy, vector<Users*>AmongUsers, TransactionType TType, string description, vector<int>share)
{
    Transaction T1(Amt,PaidBy,AmongUsers,TType,description,share);
    TransactionList.push_back(T1);
}



#endif // SPLITWISE_H
