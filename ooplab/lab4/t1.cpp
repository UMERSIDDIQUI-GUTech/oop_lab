#include <iostream>
#include <string>
using namespace std;
class Employee{
    public:
    string name;
    int age;
    int salary;
    
Employee(){
    name = " Umer";
    age = 19;
    salary = 10000; 

}
void work(){
    cout <<  " Your work is to clean " << endl;
}
};
class Manager : public Employee{
    public:
    void conductmeeting(){
        cout << " We have a meeting at 12 !" << endl;
    }
};
class Developer : public Employee{
    public : 
    void writecode(){
        cout << " Write a cpp code " << endl;
    }
    };
int main(){
    Employee e;
    Manager m;
    Developer d;
    // e.work();
    d.writecode();
    d.work();
    m.conductmeeting();
    m.work();
    return 0;
}