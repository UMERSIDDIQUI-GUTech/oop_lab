#include <iostream>
#include <string>
using namespace std;

class Birthday {
    int day;
    int month;
    int year;
public: 
    
    Birthday(int d, int m, int y) {
        day = d;
        month = m;  
        year = y;
    }

    void show() {
        cout << "Date of Birth: " << day << "/" << month << "/" << year << endl;
    }
};

class Person {
    string name;
    string city;
    Birthday birthday; 
public:
    Person(string n, string c, Birthday b) : name(n), city(c), birthday(b) {}
    void display() {
        cout << "Name: " << name << endl;
        cout << "City: " << city << endl;
        birthday.show(); 
    }
};
int main() {
    Birthday b(15, 8, 1995);
    Person p("Cr7", "Spain", b);
    p.display();
    
    return 0;
}