#include <iostream>
#include <string>

using namespace std;
class Media{
    protected:
    string title;
public:
Media(string title){
    this->title = title;

}
virtual void display()=0;

};

class Book : public Media{
private:
    string authorName;
    string isbn;
public:
Book(string title, string authorName , string isbn): Media(title), authorName(authorName), isbn(isbn) {}
 void display() override {
    cout << "Book Title : " << title << endl;
    cout << "Author Name: " << authorName << endl;
    cout << "ISBN : " << isbn << endl; 
 } 
};

class Magazine : public Media {
private:
 string monthName;
 int year;

 public:
 Magazine(string title, string monthName, int year ): Media(title), monthName(monthName), year(year) {}

 void display() override {
    cout << "Magazine title:" << title << endl;
    cout << "Month NAme : " << monthName << endl;
    cout << "Year : " << year << endl;
 }

} ;

class CD : public Media{
    private: 
    int capacity;
public:
CD(string title , int capacity): Media(title ) , capacity(capacity){}
 
void display() override{
    cout << " CD Title : " << title << endl;
    cout << " CD capacity : " << capacity << " MB" << endl;
}
};

class Shelf {
private:
    Media** items;
    int currentSize;
    int maxSize;

public:
    Shelf(int maxSize) : maxSize(maxSize), currentSize(0) {
        items = new Media*[maxSize];
    }

    void insert(Media* media) {
        if (currentSize < maxSize) {
            items[currentSize] = media;
            currentSize++;
        } else {
            cout << "Shelf is full. Cannot insert more items." << endl;
        }
    }

    void displayContents() {
        for (int i = 0; i < currentSize; i++) {
            items[i]->display();
            cout << endl;
        }

        
    }
    
    ~Shelf() {
        for (int i = 0; i < currentSize; i++) {
            delete items[i];
        }
        delete[] items;
    }
};

int main() {
    Shelf shelf(10);

    while (true) {
        cout << "1. Create Book" << endl;
        cout << "2. Create Magazine" << endl;
        cout << "3. Create CD" << endl;
        cout << "4. View Media Items" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, authorName, isbn;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, authorName);
                cout << "Enter ISBN: ";
                getline(cin, isbn);

                Book* book = new Book(title, authorName, isbn);
                shelf.insert(book);
                break;
            }
            case 2: {
                string title, monthName;
                int year;
                cout << "Enter magazine title: ";
                  cin.ignore();
                getline(cin, title);
                cout << "Enter month name: ";
                getline(cin, monthName);
                cout << "Enter year: ";
                cin >> year;

                Magazine* magazine = new Magazine(title, monthName, year);
                shelf.insert(magazine);
                break;
            }
            case 3: {
                string title;
                int capacity;
                cout << "Enter CD title: ";
                  cin.ignore();
                getline(cin, title);
                cout << "Enter capacity (MB): ";
                cin >> capacity;

                CD* cd = new CD(title, capacity);
                shelf.insert(cd);
                break;
            }
            case 4:
                shelf.displayContents();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

  return 0;
}
