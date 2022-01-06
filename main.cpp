#include <iostream>
#include"Users.h"
#include"Transaction.h"
#include"Splitwise.h"

using namespace std;

int main()
{
    Users User1("Alan");
    Users User2("Jake");
    Users User3("Ross");
    Users User4("Harry");
    vector <Users*> Userlist1;
    Userlist1.push_back(&User1);
    Userlist1.push_back(&User2);
    Userlist1.push_back(&User3);
    Userlist1.push_back(&User4);
    vector <int> share1;
    share1.push_back(100);
    share1.push_back(300);
    share1.push_back(500);
    vector <Users*> Userlist2;

    Userlist2.push_back(&User1);
    Userlist2.push_back(&User2);
    Userlist2.push_back(&User3);
    vector <int> share2;
    share2.push_back(200);
    share2.push_back(370);
    share2.push_back(880);
    Splitwise SP1;

    User1.GetAllBalances();
    SP1.PerformOperation(1000,&User1,Userlist2,Equally,"Food");
    User4.GetAllBalances();
    User1.GetAllBalances();
    SP1.PerformOperation(1450,&User1,Userlist2,Exactly,"Food",share2);

    User1.GetAllBalances();
/*
    cout<<"User 1 balances are"<<endl;
    User1.GetAllBalances();
    cout<<"User 2 balances are"<<endl;
    User2.GetAllBalances();
    cout<<"User 3 balances are"<<endl;
    User3.GetAllBalances();

    SP1.PerformOperation(900,&User1,Userlist1,Exactly,"Food",share1);

    cout<<"User 1 balances are"<<endl;
    User1.GetAllBalances();
    cout<<"User 2 balances are"<<endl;
    User2.GetAllBalances();
    cout<<"User 3 balances are"<<endl;
    User3.GetAllBalances();

*/
    //SP1.PerformOperation(1200,&User1,Userlist1,Equally);
    return 0;
}
/*
Sample Input
SHOW
SHOW user1
EXPENSE user1 1000 4 user1 user2 user3 user4 EQUAL
SHOW user4
SHOW user1
EXPENSE user1 1250 2 user2 user3 EXACT 370 880
SHOW
SHOW user1
SHOW
*/
