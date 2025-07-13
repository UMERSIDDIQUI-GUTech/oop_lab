// Write a class Point with x and y as private members. Implement a default copy
// constructor and demonstrate copying one object to another.

#include <iostream>
using namespace std;
class Point {
private:
    string x;
    int y;      
public:
    // Default copy constructor 
    Point(const Point &p) {
        x = p.x;  // Copy x from the source object
        y = p.y;  // Copy y from the source object
    }
    // Parameterized constructor
    Point(string a, int b) {
        x = a;  // Initialize x with the provided string
        y = b;  // Initialize y with the provided integer
    }
    // Method to display the values of x and y
    void display() {
        cout << "Name: " << x << endl;  // Display the value of x
        cout << "Roll No: " << y << endl;  // Display the value of y
    }
};
int main() {
    Point p1("Umer", 90);  // Create an object p1 with name "Umer" and roll number 90
    Point p2 = p1;         // Use the copy constructor to create p2 as a copy of p1
    p1.display();          // Display the values of p1
    p2.display();          // Display the values of p2
    return 0;              // Return 0 to indicate successful execution
}