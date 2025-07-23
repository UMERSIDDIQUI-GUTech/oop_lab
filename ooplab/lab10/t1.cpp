#include <iostream>
using namespace std;
template <typename T>
T calculate(T a, T b , char work){
    T result{};//was stuck then took help from gpt to know the purpose of line 5:
    if( work == '+'){
        return a+ b;
    }
    else if (work == '-'){
        return a-b;
    }
    else if (work == '*'){
        return a*b;
    }
    else if (work == '/'){
        if(b == 0){
            cout << "Infinite answer will occur ";
             return T{};
        }
        else{
            return a/b;
        }
    }
}
int main(){
cout << " Addition : " << calculate <double> (21,20.5, '+') << endl;
cout << " Subtraction : " << calculate <double> (100,59.9, '-') << endl;
cout << " Multiplication : " << calculate <int> (7,9, '*') << endl;
cout << " Division : " << calculate <double> (21.22,0, '/') << endl;
cout << " Again Division : " << calculate <double> (25,5, '/') << endl;
return 0;
}