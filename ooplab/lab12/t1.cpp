#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

class Book {
private:
    string isbn, author, title;
    
public:
    Book(string isbn, string author, string title) {
        this->isbn = isbn;
        this->author = author;
        this->title = title;
    }
    

    string getIsbn() const {
        return isbn;
    }
    
    string getAuthor() const {
        return author;
    }
    
    string getTitle() const {
        return title;
    }
    
    void print() {
        cout << " ISBN: " << isbn << " Title: " << title << " Author: " << author << endl;
    }
};

int search(unordered_map<string, Book>& library, const string& author, multimap<string, Book>& searchResult) {
    int count = 0;
    searchResult.clear();
    
    for (pair<string, Book> bookPair : library) {
        Book book = bookPair.second;
        
        if (book.getAuthor() == author) {
            searchResult.insert({author, book});
            count++;
        }
    }
    
    return count;
}

int main() {
    unordered_map<string, Book> library;
    library.insert({"9635280258938", Book("9635280258938", "Asad", "Mercury")});
    library.insert({"4702599831795", Book("4702599831795", "Asad", "Venus")});
    library.insert({"8417392305289", Book("8417392305289", "Asad", "Earth")});
    library.insert({"4323267170016", Book("4323267170016", "Taimoor", "Mars")});
    library.insert({"8951093252041", Book("8951093252041", "Unknown", "Saturn")});
    library.insert({"5580166798252", Book("5580166798252", "Taimoor", "Jupiter")});
    
   
    cout << "All books in the library:" << endl;
    for (pair<string, Book> bookPair : library) {
        bookPair.second.print();
    }
    
    multimap<string, Book> searchResult;
    string searchAuthor = "Asad";
    
    int bookCount = search(library, searchAuthor, searchResult);
    
    cout << "\nSearch results for author '" << searchAuthor << "':" << endl;
    cout << "Found " << bookCount << " book(s)" << endl;
    for (pair<const string, Book>& resultPair : searchResult) {
        resultPair.second.print();
    }
    
    searchAuthor = "Taimoor";
    bookCount = search(library, searchAuthor, searchResult);
    
    cout << "\nSearch results for author '" << searchAuthor << "':" << endl;
    cout << "Found " << bookCount << " book(s)" << endl;
    for (pair<const string, Book>& resultPair : searchResult) {
        resultPair.second.print();
    }
    
    return 0;
}
