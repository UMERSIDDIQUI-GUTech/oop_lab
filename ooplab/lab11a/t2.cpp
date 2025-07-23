#include <iostream>
#include <stdexcept>
using namespace std;
int main(){
int ind=6;
int arr[4]={1,2,3,4};
try{
if(ind < 0 || ind > 5 ){ 
    throw runtime_error("Error in index range!");       
}
cout << " Good" << endl;
}
catch (const runtime_error& e) {
cout << "Error: " << e.what() << endl;
}
return 0;
}