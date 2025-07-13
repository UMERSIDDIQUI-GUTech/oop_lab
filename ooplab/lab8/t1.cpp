// Write a class Point with x and y as private members. Implement a default copy
// constructor and demonstrate copying one object to another.
#include <iostream>
#include <string>
using namespace std;
class Point{
    private:
    string x;
    int y;
    public:

    Point(string x, int y){
        this-> x = x;
        this-> y = y;
    }
    void display(){
        cout << " Name : " << x << endl;
        cout << "  ROll nO : " << y << endl;
    }
};
int main(){
    Point p1(" Umer ", 90);
    Point p2 = p1;
    p1.display();
    p2.display();
}