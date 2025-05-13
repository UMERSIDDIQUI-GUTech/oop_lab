

#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int year;
    float price;
    bool isAvailable;

    Book(string t, string auth, int y, float p, bool avail) {
        title = t;
        author = auth;
        year = y;
        price = p;
        isAvailable = avail;
    }

    void getInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
        cout << "Is Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
    void setPrice(float newPrice) {
        price = newPrice;
    }
    void toggleAvailability() {
        isAvailable = !isAvailable;
    }
};
int main() {
    Book book1("Why GU Tech", "Rauf Malick", 2024, 1000, true);
    Book book2("The Unknown Mystery", "Zain Celebrity", 2025, 5000, true);
    Book book3("The Truth", "Umer Sidd", 2022, 1500, false);

    cout << "Book 1 Details:" << endl;
    book1.getInfo();
    cout << endl;

    cout << "Book 2 Details:" << endl;
    book2.getInfo();
    cout << endl;

    cout << "Book 3 Details:" << endl;
    book3.getInfo();
    cout << endl;

    book1.setPrice(1999);
    book1.toggleAvailability();
    
    cout << "After updating price and toggling availability for Book 1:" << endl;
    book1.getInfo();

    return 0;
}