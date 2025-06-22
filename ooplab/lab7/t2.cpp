#include <iostream>
#include <string>
using namespace std;

class Light {
    string location;
    bool isOn;
public:
    Light(string loc) {

    location=loc; 
    isOn = false; 
    }

    void turnOn() {
        isOn = true;
    }

    void turnOff() {
        isOn = false;
    }
 
    string getStatus() const {
        return location + " Light is " + (isOn ? "ON" : "OFF");
    }
};
class Thermostat {
    float temperature;  
public:
    Thermostat(){
        temperature = 20.0f;
    }

    void setTemperature(float temp) {
        temperature = temp;
    }

    float getTemperature() const {
        return temperature;
    }
};
class SmartHome {
    Light livingRoomLight;
    Light kitchenLight;
    Thermostat thermostat;
public:
    SmartHome() : livingRoomLight("Living Room"), kitchenLight("Kitchen") {}

    void turnOnLivingRoomLight() {
        livingRoomLight.turnOn();
    }

    void turnOffLivingRoomLight() {
        livingRoomLight.turnOff();
    }

    void turnOnKitchenLight() {
        kitchenLight.turnOn();
    }

    void turnOffKitchenLight() {
        kitchenLight.turnOff();
    }

    void setThermostatTemperature(float temp) {
        thermostat.setTemperature(temp);
    }

    void statusReport() const {
        cout << livingRoomLight.getStatus() << endl;
        cout << kitchenLight.getStatus() << endl;
        cout << "Thermostat temperature: " << thermostat.getTemperature() << "Â°C" << endl;
    }
};
int main() {
    SmartHome home;
    home.turnOnLivingRoomLight();
    home.setThermostatTemperature(22.5f);
    home.statusReport();
    cout << "\n";
    home.turnOffLivingRoomLight();
    home.turnOnKitchenLight();
    home.setThermostatTemperature(20.0f);
    home.statusReport();

    return 0;
}