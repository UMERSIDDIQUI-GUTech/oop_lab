#include <iostream>
using namespace std;

const int MAX_PROJECTS = 10;

class Project {
    string title;
public:
Project(string t){
    title = t;
}
    string getTitle()  {
        return title;
    }
};

class Freelancer {
    string name;
    Project* assigned[MAX_PROJECTS];
    int count = 0;
public:
    Freelancer(string n) {
        name = n;
    }

    void addProject(Project* p) {
        if (count >= MAX_PROJECTS) {
            cout << "Cannot assign more projects to " << name << ".\n";
            return;
        }
    
        for (int i = 0; i < count; ++i) {
            if (assigned[i] == p) {
                cout << "Project " << p->getTitle() << " already assigned to " << name << ".\n";
                return;
            }
        }
        assigned[count++] = p;
    }

    void listProjects() const {
        cout << name << " is working on:";
        for (int i = 0; i < count; ++i) {
            cout << "- " << assigned[i]->getTitle() << endl;
        }
    }
};

int main() {
    Project p1("AI Chatbot");
    Project p2("E-commerce Website");
    Project p3("Mobile App");
    Project p4("A Chatbot");
    Project p5("commerce Website");
    Project p6("Mobile App");
    Project p7("ommerce Website");
    Project p8("Mobile App");
    Project p9("-commerce Website");
    Project p10("Mobile App");
    Project p11("I Chatbot");
    Project p12("-commerce Website");

    Freelancer f1("Ali");
    f1.addProject(&p1);
    f1.addProject(&p1);
    f1.addProject(&p3); 
     f1.addProject(&p4);
    f1.addProject(&p5);
    f1.addProject(&p6);
     f1.addProject(&p7);
    f1.addProject(&p8);
    f1.addProject(&p9);
    f1.addProject(&p10); 
    f1.addProject(&p11);
    f1.addProject(&p12);
    f1.listProjects();

    cout << "\n";



    return 0;
}