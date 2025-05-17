
#include <iostream>
#include <string>
using namespace std;
class Parcel{
private :
string parcelid;
protected :
int weight;
public: 
Parcel(string p , int w){
parcelid = p;
weight =w;
}
void getParcelid(){
    cout << " Your parcel id is : " << parcelid;
}
};
class Timedparcel : public Parcel{
    protected: 
    float deliverspeed;
    public : 
    float distance;
    float time;
Timedparcel(float ds , float d , string parc , int weg) : Parcel(parc , weg){
 deliverspeed = ds;
 distance = d;

}
float Getestimatetime(){
    return   time = distance / deliverspeed; 
}
};

class InternationalParcel : public Timedparcel{
public : 
int customsdelay;
InternationalParcel( int cd , float deliverspeed ,float distance ,  string parcelid , int weight) : Timedparcel ( deliverspeed , distance , parcelid , weight){
customsdelay = cd;
}
float GetTotalDeliveryTime(){
    return customsdelay + Getestimatetime();
}
};


int main(){
InternationalParcel t1(150, 10, 12 , "56 " , 4);
cout << t1.Getestimatetime() << endl ;  
cout << t1.GetTotalDeliveryTime();
    return 0;
};

