#include <iostream>
#include <string>
using namespace std;

class Book {
    public : 
    string title;
    string author;
    int year;

    Book(){
        title = "Unknown";
        author = " Unknown ";
        year = 0;
    }
    void getinfo(){
        cout << " TItle : " << title << endl;
        cout << " Author : " << author << endl;
        cout << " Year : " << year << endl;
    }

};
int main(){
 Book book1;
 book1.getinfo();
    return 0;


}   