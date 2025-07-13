#include<iostream>
#include <cstring>
using namespace std;
class resume
{
    char *name;
    char *skills;

public:

    resume() : name(nullptr), skills(nullptr){}

    resume(const char *n, const char *s)
    {
        name = new char[strlen(n + 1)];
        strcpy(name, n);
        
        skills = new char[strlen(s + 1)];
        strcpy(skills, s);
    }

    resume(const resume &original)
    {
        name = new char[strlen(original.name + 1)];
        strcpy(name,original.name);
        
        skills = new char[strlen(original.skills + 1)];
        strcpy(skills,original.skills);
    }

    void updateName(const char *n){
        name = new char[strlen(n + 1)];
        strcpy(name, n);
    }

    void displayDetails(){
        cout << name << " : " << skills << endl;
    }

    ~resume() {
        delete[] name;
        delete[] skills;
        cout << "heap memory khalli walli\n";
    }
};

int main()
{
    resume r1("ahsan" , "prompt engineer");
    resume r2 = r1;
    
    cout << "Initial r1 and r2 values :\n";

    r1.displayDetails();
    r2.displayDetails();
    
    r1.updateName("jain");
    
    cout << "\nr1 and r2 values after change :\n";

    r1.displayDetails();
    r2.displayDetails();

    return 0;
}