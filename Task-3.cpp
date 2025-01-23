// Create a program that:
// 1. Defines a struct for book information (title, author, ISBN, available status)
// 2. Implements functions to:
// ○ Add new books to the library
// ○ Check out books (change availability status)
// ○ Return books
// ○ Display all books
// 3. Stores the library database in a file named "library.txt"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool available;
};  

void addBook() {
    Book book;
    cout << "Enter title: ";
    cin >> book.title;
    cout << "Enter author: ";
    cin >> book.author;
    cout << "Enter ISBN: ";
    cin >> book.ISBN;
    book.available = true;

    ofstream file("library.txt", ios::app);
    file << book.title << " " << book.author << " " << book.ISBN << " " << book.available << endl;
    file.close();
    cout << "Book added successfully!\n";
}

void checkOutBook() {
    string ISBN;
    cout << "Enter ISBN: ";
    cin >> ISBN;

    ifstream file("library.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string title, author;
            bool available;
            sscanf(line.c_str(), "%[^ ] %[^ ] %[^ ] %d", title.c_str(), author.c_str(), ISBN.c_str(), &available);
            if (ISBN == ISBN) {
                available = false;
                break;  
            }
        }
        file.close();

        ofstream file("library.txt");    
        file << title << " " << author << " " << ISBN << " " << available << endl;
        file.close();
        cout << "Book checked out successfully!\n";
    } else {
        cout << "Error opening file.\n";
    }
}

void returnBook() {
    string ISBN;
    cout << "Enter ISBN: ";
    cin >> ISBN;

    ifstream file("library.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string title, author;
            bool available;
            sscanf(line.c_str(), "%[^ ] %[^ ] %[^ ] %d", title.c_str(), author.c_str(), ISBN.c_str(), &available);
            if (ISBN == ISBN) {
                available = true;
                break;  
            }
        }
        file.close();

        ofstream file("library.txt");    
        file << title << " " << author << " " << ISBN << " " << available << endl;
        file.close();
        cout << "Book returned successfully!\n";
    } else {
        cout << "Error opening file.\n";
    }    
}