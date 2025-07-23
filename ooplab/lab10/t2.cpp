#include <iostream>
using namespace std;
template <typename T>
void bubblusort( T arr[], int size){
    for(int i =0; i < size -1; i++){
        for(int j=0; j < size-1-i;j++){
            if(arr[j]>arr[j + 1 ]){
                T tempo = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= tempo;
            }
        }
    }
}
template <typename T>
void Show(T arr[], int size){
    for(int i=0; i < size ; i++ ){
        cout << arr[i] << endl;
    }
}
int main(){
    int Arr[] = {1, 5, 2, 3, 4};
    int size = 5;
    cout << " Before Sorting " << endl;
    Show(Arr , size);
    bubblusort(Arr, size);
    cout << " After sorting " << endl;
    Show( Arr, size);
}