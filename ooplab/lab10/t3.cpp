#include <iostream>
using namespace std;
template <typename T1 , typename T2>
class Pair {
private:
T1 one;
T2 two;
public:
Pair(T1 o , T2 t){
    one =o;
    two=t;
}
void showvalue() {
cout << "Value: " << one << endl;
cout << "Value: " << two << endl;
}
 void swap() {
       T1 temp = one;
        one = two; 
         two = temp;
    }
};
int main() {
    Pair<int, double> p(6, 8.1);
    p.showvalue();
    p.swap();
    p.showvalue();
    return 0;
}




























