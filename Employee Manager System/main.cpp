#include <iostream>
#include<bits/stdc++.h>

using namespace std;

static int NoOfEmployees=0;
class employee;
class employee{
    int EmpId;
    int ManagerId;
    string name;
    int age;
    vector <employee*> ListOfEmployees;
public:
    employee(string name,int ManagerId,int age){
        this->name=name;
        this->ManagerId=ManagerId;
        this->age=age;
        this->EmpId=NoOfEmployees++;
    }
    int getId();
    int getManagerId();
    string getName();
    int getAge();
    vector<employee*> getListOfAllEmployees();
    void AddJuniorEmployee(employee *Emp);
};

class DB{
    unordered_map<int,employee*> Database;
    employee *YoungestEmployee;
public:
    void AddTopManager(string name,int age);
    void AddEmployee(string name,int ManagerId,int age);
    void PrintAllJuniorEmployees(int EmpId);
    string GetEmployeeName(int EmpId);
    int GetEmployeeAge(int EmpId);
    string GetManagerName(int EmpId);
    employee *GetYoungestEmployee();
    string GetYoungestEmployeeName();
    void GetAllEmpsGreaterAge(int age);
};


    int employee:: getId(){
        return EmpId;
    }
    int employee::getManagerId(){
        return ManagerId;
    }
    string employee:: getName(){
        return name;
    }
    int employee::getAge(){
        return age;
    }
    vector<employee*> employee::getListOfAllEmployees(){
        return ListOfEmployees;
    }
    void employee::AddJuniorEmployee(employee *Emp){
        ListOfEmployees.push_back(Emp);
    }
    void DB::AddTopManager(string name,int age){
        employee *NewEmp=new employee(name,-1,age);
        Database[NewEmp->getId()]=NewEmp;
        YoungestEmployee=NewEmp;
    }
    void DB::AddEmployee(string name,int ManagerId,int age){
        employee *NewEmp=new employee(name,ManagerId,age);
        Database[NewEmp->getId()]=NewEmp;
        Database[ManagerId]->AddJuniorEmployee(NewEmp);
        if(age<YoungestEmployee->getAge()){
            YoungestEmployee=NewEmp;
        }

    }

    void DB::PrintAllJuniorEmployees(int EmpId){
        vector <employee*> temp=Database[EmpId]->getListOfAllEmployees();
        vector <employee*> ::iterator itr=temp.begin();
       if(temp.size()==0){
            cout<<"No Junior Employee";
        }
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]->getId()<<" "<<temp[i]->getName()<<endl;
        }
        cout<<endl;
    }

    string DB::GetEmployeeName(int EmpId){
        return Database[EmpId]->getName();
    }
    int DB::GetEmployeeAge(int EmpId){
        return Database[EmpId]->getAge();
    }
    string DB::GetManagerName(int EmpId){
        int ManID= Database[EmpId]->getManagerId();
        return GetEmployeeName(ManID);
    }
    employee * DB::GetYoungestEmployee(){
        return YoungestEmployee;
    }
    string DB::GetYoungestEmployeeName(){
        return YoungestEmployee->getName();
    }

    void DB::GetAllEmpsGreaterAge(int age){
        unordered_map<int,employee*>::iterator itr=Database.begin();
        for(itr ;itr!=Database.end();itr++){
            if(itr->second->getAge()>age){
                    cout<<itr->second->getId()<<" "<<itr->second->getName()<<endl;
            }
        }
    }
int main()
{
    DB Details;
    Details.AddTopManager("Sam",23);
    Details.AddEmployee("Harsimran",0,30);
    Details.AddEmployee("Harry",1,20);
    Details.AddEmployee("Har",1,110);
    Details.AddEmployee("Hars",2,40);
    Details.AddEmployee("Jake",2,10);
    Details.AddEmployee("Farrah",4,10);

    Details.PrintAllJuniorEmployees(0);
    Details.PrintAllJuniorEmployees(1);
    Details.PrintAllJuniorEmployees(2);
    Details.PrintAllJuniorEmployees(3);
    Details.PrintAllJuniorEmployees(4);
    Details.PrintAllJuniorEmployees(5);

    cout<<Details.GetEmployeeName(0)<<endl;
    cout<<Details.GetEmployeeName(1)<<endl;
    cout<<Details.GetEmployeeName(2)<<endl;
    cout<<Details.GetEmployeeName(3)<<endl;
    cout<<Details.GetManagerName(1)<<endl;

    cout<<Details.GetManagerName(2)<<endl;
    cout<<Details.GetManagerName(3)<<endl;
    cout<<Details.GetManagerName(4)<<endl;
    cout<<Details.GetManagerName(5)<<endl;
    cout<<Details.GetYoungestEmployeeName()<<endl;
    Details.GetAllEmpsGreaterAge(30);

    return 0;
}
