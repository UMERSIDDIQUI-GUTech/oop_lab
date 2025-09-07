#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    protected:
    string regNumber;
    int baseFare;
public:
Vehicle(string reg, int base){
    regNumber= reg;
    baseFare= base;
}
virtual int calculateFare(int km)=0;
virtual void display(int km)=0;
virtual ~Vehicle() {}
};

class Car: public Vehicle{
public:
  Car(string reg) : Vehicle(reg,100) {}
  int calculateFare(int km) override {
    return baseFare + 10 * km;
  }
void display(int km) override {
    cout << " Car [ " << regNumber << " ]  Fare : " << calculateFare(km) << endl; 
}
};

class Bike : public Vehicle{
public:
  Bike(string reg) : Vehicle(reg,50) {}
  int calculateFare(int km) override {
    return baseFare + 5 * km;
  }
void display(int km) override {
    cout << " Bike [ " << regNumber << " ]  Fare : " << calculateFare(km) << endl; 
}
};

class Rickshaw : public Vehicle{
public:
  Rickshaw(string reg) : Vehicle(reg,70) {}
  int calculateFare(int km) override {
    return baseFare + 7 * km;
  }
void display(int km) override {
    cout << " Rickshaw [ " << regNumber << " ]  Fare : " << calculateFare(km) << endl; 
}
};

int main(){
const int km = 5;
Vehicle* sawaari[3]={
    new Car("CITY-111"),
    new Bike("HONDA-222"),
    new Rickshaw("Sazgar-333")
};
for(int i=0;i<3;i++){
    sawaari[i]->display(km) ;
    delete sawaari[i];
}
return 0;
}
