#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;
class Student
{
    string name;
    int id;
    float marks;

public:
    void Addstudent()
    {
        cin.ignore();
        cout << " Enter Name:" << endl;
        getline(cin, name);
        cout << "Enter student id: " << endl;
        cin >> id;
        cout << "Enter marks: " << endl;
        cin >> marks;
       ofstream outfile("students.txt", ios::app); // Append mode
        if (!outfile) {
            cerr << "Error opening file!" << endl;
            return;
        }
        outfile << name << " " << id << " " << marks << endl;
        outfile.close();

        cout << "Student added successfully!\n";
    //    outfile.close();
    }
    void displayAll()
    {

    }
    void searchStudent()
    {
       
    }
    void updateStudent()
    {

    }
    void deleteStudent(){

    }
};
int main()
{
    
  
}