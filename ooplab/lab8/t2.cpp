// Task 2: Create a class ArrayHolder that contains a pointer to a dynamically allocated array.
// Implement:
// ● A default constructor
// ● A copy constructor (first as a shallow copy, then as a deep copy)
// ● A destructor

#include <iostream>
#include <cstring>
using namespace std;
class ArrayHolder{
    int* arr;
    int arrsize;
    public:
    ArrayHolder(int arrsize){
this->arrsize=arrsize;
 arr= new int[arrsize];
cout << " Enter array elements " << endl;
for(int i=0; i <arrsize ; i++){
   cin >>  arr[i];
}
}
ArrayHolder(){
    arrsize = 6;
    arr = new int[arrsize];
    cout << " Enter 6 elements "  << endl;
    for(int i=0; i < arrsize ; i++){
        cin>> arr[i];
    }
}


ArrayHolder(const ArrayHolder& other){
    cout << " Copy constructor called" << endl;
arrsize = other.arrsize;
arr= new int[arrsize];

for(int i=0 ; i < arrsize ; i++){
    arr[i]= other.arr[i];
}
}
~ArrayHolder(){
    delete[] arr;
    arr= NULL; 
}
void display(){
    for(int i=0 ;i<arrsize; i++){
        cout << " arr " << arr[i] << ' ' << endl;
    }
    cout << endl;
}

};
int main(){
    ArrayHolder a1(5);
    a1.display();
    ArrayHolder a2=a1;
    a2.display();
    
}