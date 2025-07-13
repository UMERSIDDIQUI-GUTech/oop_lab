#include <iostream>
#include <cstring>
using namespace std;

class CityInfo {
public:
    char* location;

    CityInfo() {
        location = NULL;
    }

    CityInfo(const char* l) {
        location = new char[strlen(l) + 1];
        strcpy(location, l);
    }

    CityInfo(const CityInfo& other) {
        location = new char[strlen(other.location) + 1];
        strcpy(location, other.location);
    }

    ~CityInfo() {
        delete[] location;
    }
};

class Citizen {
    char* fullName;
    CityInfo city;

public:
    Citizen() {
        fullName = NULL;
    }

    Citizen(const char* cityName, const char* personName) : city(cityName) {
        fullName = new char[strlen(personName) + 1];
        strcpy(fullName, personName);
    }

    Citizen(const Citizen& original) : city(original.city) {
        fullName = new char[strlen(original.fullName) + 1];
        strcpy(fullName, original.fullName);
    }

    void modifyDetails(const char* newCity, const char* newName) {
        delete[] city.location;
        delete[] fullName;

        city.location = new char[strlen(newCity) + 1];
        strcpy(city.location, newCity);

        fullName = new char[strlen(newName) + 1];
        strcpy(fullName, newName);
    }

    void print() {
        cout << "Full Name: " << fullName << " | Location: " << city.location << endl;
    }

    ~Citizen() {
        delete[] fullName;
    }
};

int main() {
    Citizen a("islamabad", "bilal");
    Citizen b = a;
    Citizen c = a;

    cout << "== Before Change ==\n";
    a.print();
    b.print();
    c.print();

    a.modifyDetails("multan", "zayan");

    cout << "\n== After Changing Citizen A ==\n";
    a.print();
    b.print();
    c.print();

    return 0;
}
