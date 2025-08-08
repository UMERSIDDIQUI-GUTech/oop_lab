#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

class Student {
private:
    string name;
    string rollNo;
    
public:
    Student(string rollNo, string name) {
        this->rollNo = rollNo;
        this->name = name;
    }
    
    string getName() const {
        return name;
    }
    
    string getRollNo() const {
        return rollNo;
    }
    
    bool operator<(const Student& other) const {
    
        string thisRoll = rollNo;
        string otherRoll = other.rollNo;
        

        for (char& c : thisRoll) {
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
        }
        
        for (char& c : otherRoll) {
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
        }
        
        return thisRoll < otherRoll;
    }
    
    void print() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << endl;
    }
};

string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}

int main() {
    set<Student> students;
    

    ifstream file("students.txt");
    
    if (!file.is_open()) {
        cout << "Error: Could not open students.txt file." << endl;
        cout << "Creating sample data..." << endl;
        
        students.insert(Student("24g-bCs007", "hUzAiFa"));
        students.insert(Student("24g-bCs003", "bArIrA"));
        students.insert(Student("24G-BcS001", "Abdur Rehman"));
        students.insert(Student("24G-BcS002", "AhSaN"));
        students.insert(Student("24g-bCs004", "fAtImA"));
    } else {
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                string rollNo = trim(line.substr(0, commaPos));
                string name = trim(line.substr(commaPos + 1));
                
                if (!rollNo.empty() && !name.empty()) {
                    students.insert(Student(rollNo, name));
                }
            }
        }
        file.close();
    }
    
    cout << "Students sorted by roll number (case-insensitive):" << endl;
    cout << "================================================" << endl;
    
    for (const Student& student : students) {
        student.print();
    }
    
    cout << "\nTotal number of students: " << students.size() << endl;
    
    return 0;
}
