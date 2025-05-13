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
    name = n;
    age=a;
    grade =g;
}
void setName(string n){
    name=n;
}
void setAge(int a){
    age=a;
}

void setGrade(string g){
    grade=g;
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
    Student s1("Umer" , 20 , "C");
    s1.setName("Jain");
    s1.setAge(10);
    s1.setGrade("C++");
    cout << s1.getname() << endl;
    cout <<  s1.getage()<< endl;
    cout << s1.getgrade()<< endl;
}