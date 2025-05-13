#include <iostream>
#include <string>
using namespace std;

class Book {
    public : 
    string title;
    string author;
    int year;

    Book(string t , string a , int y){
        title = t;
        author = a;
        year = y;
    }
    void getinfo(){
        cout << " TItle : " << title << endl;
        cout << " Author : " << author << endl;
        cout << " Year : " << year << endl;
    }

};
int main(){
    string title , author;
    int year;
    cout << " Enter title : " << endl;
    cin >> title;
    cout << " Enter Author : " << endl;
    cin >> author; 
    cout << " Enter Year : " << endl;
    cin >> year;
 Book book1(title , author , year);
 book1.getinfo();
    return 0;
}