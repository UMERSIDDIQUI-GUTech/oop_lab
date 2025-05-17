#include <iostream>
#include <string>
using namespace std;
class Item{
    public:
    string name;
    int price;
public:
Item(string n , int pr){
    name =n;
    price = pr;
}
void itemdetail(){
    cout << " These are the details of item : " << name << " & " << price << endl;
}
};
class Fooditem : public Item{
    public:
    float discount;
public :
Fooditem( float d, string n , int pr) : Item(n,pr){
    discount =d;
}
float calcualteDiscount(){
    float pricee = price - (price  * (discount / 100));
    return pricee;
}
};
class NonFoodItem : public Item{
    public:
    float tax;
NonFoodItem(float t , string n , int pr) : Item(n, pr){
tax=t;
}
float calculateTax(){
    float Ttax= price + (price * (tax/100));
    return Ttax;
}
};
int main(){
    Item i1("Appol" , 10);
i1.itemdetail();
Fooditem f1(30 , " Banana" ,100  );
f1.calcualteDiscount();
cout << " Price after Discount is : " <<  f1.calcualteDiscount() << endl;
NonFoodItem n1(15 , " Perfume " , 1000);
n1.calculateTax();
cout << " Price After applying tax is : " << n1.calculateTax() << endl;
n1.itemdetail();
}