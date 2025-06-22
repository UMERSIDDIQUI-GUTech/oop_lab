#include <iostream>
#include <string>
using namespace std;

class Product {
    string name;
    float price;
public:
    Product(string n, float p) {
        name = n;
        price = p;
    }
    string getName() const {
        return name;
    }
    float getPrice() const {
        return price;
    }
};
class CartItem {
    Product* product;
    int quantity;
public:
    CartItem(Product* p, int qty) {
        product = p;
        quantity = qty;
    }
    float getTotalPrice() const {
        return product->getPrice() * quantity;
    }
    void display() const {
        cout << product->getName() << " x " << quantity << " = $" << getTotalPrice() << endl;
    }

};
class Cart {   // I have used gpt for this class coz i wasnt able to understand the concept of cart and cartitem
    CartItem* items[100]; 
    int itemCount;
public:
    Cart() {
        itemCount = 0;
    }
    void addItem(Product* p, int qty) {
        if (itemCount < 100) {
            items[itemCount++] = new CartItem(p, qty);
        } else {
            cout << "Cart is full. Cannot add more items." << endl;
        }
    }

    void showCart() const {
        cout << "Cart contains:" << endl;
        for (int i = 0; i < itemCount; ++i) {
            items[i]->display();
        }
    }
    float calculateTotal() const {
        float total = 0.0f;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i]->getTotalPrice();
        }
        return total;
    }
    ~Cart() {
        for (int i = 0; i < itemCount; ++i) {
            delete items[i]; 
        }
    }
};
int main() {
    Product apple("Apple", 0.5f);
    Product banana("Banana", 0.3f);
    Product orange("Orange", 0.8f);

    Cart cart;
    cart.addItem(&apple, 3);
    cart.addItem(&banana, 2);
    cart.addItem(&orange, 5);

    cart.showCart();
    cout << "Total cost: $" << cart.calculateTotal() << endl;

    return 0;
}