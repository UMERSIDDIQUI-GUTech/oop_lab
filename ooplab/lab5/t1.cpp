#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string wor){
    int a;
    a= wor.length();
    for(int i=0; i <= a/2 ; i++ ){
        if(wor[i] != wor[a-1]){
            cout << wor << " is not a  Palindrome " << endl; 
            return false;
        }
        a--;
    }  
      cout << wor << " is a Palindrome " << endl; 
    return true;
  
}
bool isPalindrome(int num){
    string st = to_string(num);
    return isPalindrome(st);

}
int main(){
     isPalindrome( "madam");
     isPalindrome(111) ;
    return 0;
}