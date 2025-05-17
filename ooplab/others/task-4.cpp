#include <iostream>
#include <string>
using namespace std;
class Employee{
    private:
    string name;
    int salary;
    string position;
    public:
    Employee(string n , int s , string pos){
        name = n;
        salary = s;
        position = pos;
    }
    Employee(){
        name = "Zain";
        salary = 1020;
        position = "MD ";

    }
void details(){
    cout << "Name :" << name << endl;
    cout << "Salary :" << salary << endl;
    cout << "Position:" << position << endl;
}
};

int main(){
Employee emp1( " Yusuf ",1000 , "CEO");
emp1.details();

Employee emp2;
emp2.details();

}