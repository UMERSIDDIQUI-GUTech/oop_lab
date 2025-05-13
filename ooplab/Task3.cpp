#include <iostream>
#include <string>
using namespace std;
class Student{
    private:
    string name;
    int age;
    string grade;
    public:
    Student(string n, int a, string g){
        name= n;
        age= a;
        grade=g;
    }
    void setName(string n){
        name = n;
    }
    void setAge(int a){
        age = a;
    }
    void setGrade(string g){
        grade= g;
    }
    string getname(){
        return name;
    }
    int getage(){
        return age;
    }

    string getgrade(){
        return grade;
    }
    
};
int main(){
    Student stud1("Umer", 20, "A" );
    stud1.setName("Zain");
    stud1.setAge(19);
    stud1.setGrade("B");
   cout <<  stud1.getname() << endl;
   cout << stud1.getage()<< endl;
   cout << stud1.getgrade() << endl;


    return 0;


}

