#include <iostream>
using namespace std;
int main() {
    int i;
cout << " Enter a positive integer" << endl;
cin >> i;
try {
if (i < 0)
throw "Negative numbers are not allowed!"; 
cout << i ;
}
catch (const char* msg) {
cout << "Exception: " << msg << endl;
}
return 0;
}