// You are building a base class Sensor that:
// ● Has private attributes: id (string), value (float)
// ● Has a constructor that sets the id
// ● Provides setValue() and getValue() methods
// ● A protected method isThresholdExceeded(float threshold)
// Create a subclass TemperatureSensor that:
// ● Has a method TriggerAlarm() that checks if temperature > threshold using the base
// method
// ● If threshold is exceeded, print "ALERT: [id] temperature exceeded!"
// Write a main() that sets value and triggers the alarm appropriately.

#include <iostream>
#include <string>
using namespace std;
class Sensor {
private:
    string id;
    float value;      
public:
    Sensor(string i) {
        id = i;
    }
    void setValue(float v) {
        value = v;
    }
    float getValue() {
        return value;
    }
    bool isThresholdExceeded(float threshold) {
        return value > threshold;
    }
};
class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(string i) : Sensor(i) {}
    void TriggerAlarm(float threshold) {
        if (isThresholdExceeded(threshold)) {
            cout << "ALERT: " << getValue() << " temperature exceeded!" << endl;
        }
    }
};
int main() {
    TemperatureSensor tempSensor("TempSensor1");
    tempSensor.setValue(90.0);
    float threshold = 70.0;
    tempSensor.TriggerAlarm(threshold);
    return 0;
}