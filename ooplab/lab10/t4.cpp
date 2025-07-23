#include <iostream>
#include <string>
using namespace std;

template <typename T>
void smartSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temporary = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temporary;
            }
        }
    }
} 
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << "\n";
}
int main(){
     int Arr[]={1,5,7,4,2};
    string arr[] = {" karachi", " qwrerty", " apple" , " banana" , " grape"};
    int size=5;
    smartSort(arr,size);
    smartSort(Arr, size);
    displayArray(Arr , size);
    displayArray(arr, size);


} 