#include <iostream>
using namespace std;
int main(){
    try{
        int age;
        cout << " Enter your age:" << endl;
        cin >> age;
        if(age<0){
            throw age;
        }
        else if(age>150){
            throw " Your age is unrealistic";
        }
    }
     catch(int ag){
        cout << " Invalid age entered" << ag << endl;
     }
     catch( const char*agee){
        cout << "string exception" << agee << endl;
     }
    }