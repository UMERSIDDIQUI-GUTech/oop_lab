#include <iostream>
#include <string>
using namespace std;
 class Sensor{
    private :
    string id;
float value;
public:
Sensor(string i){
    id =i;
}
void setValue(float v){
    value =v;
}
float getValue(){
    return value;
}
string getId(){
    return id;
}
protected:
bool isThresholdExceeded(float threshold){
  return value > threshold;
}
 };
 class TemperatureSensor :  public Sensor{
    public : 
    TemperatureSensor(string i) : Sensor(i){}
    void TriggerAlarm(float threshold){
    if(isThresholdExceeded(threshold)){
        cout << " Alert : " << getId() << " temperature exceeded !" << endl;
    }  
    else {
        cout << " Temperature is cool" << endl;
    }
    }
 };

 int main(){
    float threshold = 97;
    TemperatureSensor s1(" Cristiano Ronaldo ");
    s1.setValue(98);
    s1.TriggerAlarm(97);
 }