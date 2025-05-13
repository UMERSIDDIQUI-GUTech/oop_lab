#include <iostream>
#include <string>
using namespace std;


void printRoomInfo(int roomNumber, string guest, bool isBooked) {
cout << "Room: " << roomNumber << endl;
cout << "Guest: " << (isBooked ? guest : "Available") << endl;
cout << "Booked: " << (isBooked ? "Yes" : "No") << endl;
cout << "------------------" << endl;
}
void bookRoom(int roomNumber, string guestName) {
if (roomNumber == 101) {
cout << "Room 101 is already booked." << endl;
} else if (roomNumber == 102) {
cout << "Room 102 is now booked for " << guestName << "." << endl;
}
}
int main() {
int room1Number = 101;
string room1Guest = "Ali";
bool room1Booked = true;
int room2Number = 102;
string room2Guest = "";
bool room2Booked = false;
printRoomInfo(room1Number, room1Guest, room1Booked);
printRoomInfo(room2Number, room2Guest, room2Booked);
bookRoom(102, "Sara");
return 0;
}