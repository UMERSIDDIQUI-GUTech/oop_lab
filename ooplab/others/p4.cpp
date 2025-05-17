// 5: Design an inheritance structure for a grocery shopping system. The base class
// should be Item, and the derived classes should be FoodItem and NonFoodItem.
// ● The FoodItem class should have a method calculateDiscount().
// ● The NonFoodItem class should have a method applyTax().
// Create instances of both FoodItem and NonFoodItem and test the methods.


#include <iostream>
#include <string>
using namespace std;
class Item {
    private:
        string name;
        float price;
    public:
        Item(string n, float p) : name(n), price(p) {}
        string getName() {
            return name;
        }
        float getPrice() {
            return price;
        }
};
class FoodItem : public Item {
    private:
        float discount;
    public:
        FoodItem(string n, float p, float d) : Item(n, p), discount(d) {}
        float calculateDiscount() {
            return getPrice() * (discount / 100);
        }
};
class NonFoodItem : public Item {
    private:
        float tax;
    public:
        NonFoodItem(string n, float p, float t) : Item(n, p), tax(t) {}
        float applyTax() {
            return getPrice() * (tax / 100);
        }
};
int main() {
    FoodItem apple("Apple", 1.0, 10); // 10% discount
    NonFoodItem soap("Soap", 2.0, 5); // 5% tax

    cout << "Food Item: " << apple.getName() << ", Price: $" << apple.getPrice() << ", Discount: $" << apple.calculateDiscount() << endl;
    cout << "Non-Food Item: " << soap.getName() << ", Price: $" << soap.getPrice() << ", Tax: $" << soap.applyTax() << endl;

    return 0;
}