#include <iostream>
#include <string>
using namespace std;
class Person{
    public:
    string name;
    int age;
public:
void setName(string name){
    this-> name = name;
}
void setAge(int age){
    this-> age = age;
}
string getName(){
    return name;
}
int getAge(){
    return age;
}
};
class Student :virtual public Person{
public:
void study(){
    cout << " student is studying " << endl;
}
};
class Teacher : virtual public Person{
    public:
    void teach(){
        cout << " Teacher is teaching " << endl;
    }
};

class TeachingAssistant : public Student , public Teacher{

};
int main(){
TeachingAssistant t;
t.setName("Gutech");
t.setAge(15);
cout << t.getName() << endl;
cout <<  t.getAge() << endl;
t.study();
t.teach();

}