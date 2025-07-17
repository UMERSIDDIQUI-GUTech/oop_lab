#include <iostream>
#include <string>
using namespace std;
class Teacher; 
class Student {
private:
    string name;    
public:
    Student(const string& na) : name(na) {}
    friend void printNames(const Student& st, const Teacher& te);
};
class Teacher {
private:
    string name;
public:
    Teacher(const string& naa) : name(naa) {}
    friend void printNames(const Student& stu, const Teacher& tea);
};
void printNames(const Student& s, const Teacher& t) {
    cout << "Student: " << s.name << endl;

    cout << "Teacher: " << t.name << endl;
}
int main() {
    Student s("Bablu");
    Teacher t("zain urf ilyas ");
    printNames(s, t);
    return 0;
}