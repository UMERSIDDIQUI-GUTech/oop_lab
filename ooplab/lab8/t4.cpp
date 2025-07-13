#include <iostream>
#include <cstring>
using namespace std;

class Student {
char* name;
public:
Student(const char* n) {
name = new char[strlen(n)+1];
strcpy(name, n);
}
// Faulty copy constructor
Student(const Student& s) {
name = s.name; // shallow copy!
name = new char[strlen(s.name) + 1];
strcpy(name, s.name); 
}
void changing(const char* n){
    delete[] name;

    name= new char[strlen(n)+1];
    strcpy(name, n);
}

void display() {
cout << name << endl;
}
~Student() {
delete[] name;
}
};
int main(){
    Student s1(" Umeree");
    Student s2=s1;
    s1.display();
    s2.display();
    s1.changing(" Chajao");
    s1.display();
    s2.display();
}