
#include <iostream>
#include <string>
using namespace std;

// Base class Parcel
class Parcel {
private:
    string parcelID;
protected:
    float weight;  // in kg
public:
    Parcel(string p, float w) {
        parcelID = p;
        weight = w;
    }
    string GetParcelID() {
        return parcelID;
    }
};

// Class TimedParcel inherits from Parcel
class TimedParcel : public Parcel {
protected:
    float deliverySpeed;  // in km/h
public:
    TimedParcel(string p, float w, float ds) : Parcel(p, w) {
        deliverySpeed = ds;
    }
    float GetEstimatedTime(float distance) {
        return distance / deliverySpeed;
    }
};

// Class InternationalParcel inherits from TimedParcel
class InternationalParcel : public TimedParcel {
private:
    float customsDelay;  // in hours
public:
    InternationalParcel(string p, float w, float ds, float cd) : TimedParcel(p, w, ds) {
        customsDelay = cd;
    }
    float GetTotalDeliveryTime(float distance) {
        return GetEstimatedTime(distance) + customsDelay;
    }
};

int main() {
    // Create an InternationalParcel
    InternationalParcel parcel("P001", 5.5, 60.0, 2.0);
    
    // Test with a distance of 120 km
    float distance = 120.0;
    
    cout << "Parcel ID: " << parcel.GetParcelID() << endl;
    cout << "Distance: " << distance << " km" << endl;
    cout << "Total delivery time: " << parcel.GetTotalDeliveryTime(distance) << " hours" << endl;
    
    return 0;
}

