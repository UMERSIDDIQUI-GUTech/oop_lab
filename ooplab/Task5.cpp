#include <iostream>
#include <string>
using namespace std;

class Hotelroom{
    public:
    int roomnum;
    string guestname;
    bool isbooked;

    Hotelroom( int num, string naam, bool boked){
        roomnum = num;
        guestname = naam;
        isbooked = boked;
    }
    void printroominfo(){
        cout << "Room: " << roomnum << endl;
        cout << "Guest: " << (isbooked ? guestname : " Available ")<< endl;
        cout << "Booked:  " << (isbooked ? " yes " : " no ") << endl;
        cout << "----------------" << endl;
    }
    void bookroom( string naam){
        if(isbooked){
            cout << "Room: " << roomnum << " is already booked " <<endl;
        }
            else{
                guestname = naam;
                isbooked = true;
                cout << "Room: " << roomnum << " is booked for " << guestname << endl;
            }
           
        
        }
};
int main(){
    Hotelroom room1(101, "King", true);
    Hotelroom room2(102, " ", false);
    room2.printroominfo();
    room2.bookroom("Ronaldo");
    room2.printroominfo();
  
    return 0;
}