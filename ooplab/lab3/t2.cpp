#include <iostream>
#include <string>
using namespace std;
class Car {
    public :
    string brandd;
    string model;
    int year;

    Car(string a, string b, int c){
        brandd =a;
        model = b;
        year= c;
    }
};
int main(){
    Car car1("Honda", "Civic", 2020);
    Car car2( "Toyota ", "Corolla", 2025);
    cout << "Car 1 details:" << car1.brandd << endl;
    cout  << car1.model << endl;
    cout  << car1.year << " \n" << endl;
    cout << "Car 2 details:\n" << car2.brandd << endl;
    cout  << car2.model << endl;
    cout  << car2.year << endl;
}