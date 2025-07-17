#include <iostream>
#include <cstring>
using namespace std;
class Fraction {
public:
int numerator, denominator;
// Helper function to find GCD
int gcd(int a, int b) {
if (b == 0) return a;
return gcd(b, a % b);
}
// Helper function to simplify fraction
void simplify() {
int g = gcd(abs(numerator), abs(denominator));
numerator /= g;
denominator /= g;
if (denominator < 0) {
numerator = -numerator;
denominator = -denominator;
}
}
public:
// Constructor
Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
if (denominator == 0) {
cout << "Error: Denominator cannot be zero!" << endl;
denominator = 1;
}
simplify();

}// TODO: Implement these operators
// Fraction operator+(const Fraction& other) const;
// Fraction operator-(const Fraction& other) const;
// Fraction operator*(const Fraction& other) const;
// Fraction operator/(const Fraction& other) const;
// bool operator==(const Fraction& other) const;
Fraction operator+(const Fraction& other) const {
int num1 = numerator * other.denominator + denominator * other.numerator;
int denomi = denominator * other.denominator;
cout << num1 << " / " << denomi << endl;
return Fraction(num1, denomi);
}
Fraction operator-(const Fraction& other) const {
int num1 = numerator * other.denominator - denominator * other.numerator;
int denomi = denominator * other.denominator;
cout << num1 << " / " << denomi << endl;
return Fraction(num1, denomi);
}
Fraction operator*(const Fraction& other) const {
int num1 = numerator * other.numerator;
int denomi = denominator * other.denominator;
cout << num1 << " / " << denomi << endl;
return Fraction(num1, denomi);
}
 Fraction operator/(const Fraction& other) const {
if (other.numerator == 0) {
    cout << "Error: Division by zero!" << endl;
    return Fraction(0, 1);
}
int num1 = numerator * other.denominator;
int denomi = denominator * other.numerator;
cout << num1 << " / " << denomi << endl;
return Fraction(num1, denomi);
}
bool operator==(const Fraction& other) const {
return (numerator * other.denominator == denominator * other.numerator);
}
void display() const{
    cout << "(" << numerator << " , " << denominator << ")" ;
}
};
int main() {
Fraction f1(3, 4);
Fraction f2(1, 2);
Fraction f3 = f1 + f2;
f3.display(); 
Fraction f4 = f1 - f2;
f4.display(); 
Fraction f5 = f1 * f2;
f5.display(); 
Fraction f6 = f1 / f2;
f6.display(); 
if (f1 == f2) {
    cout << "Fractions same hain ." << endl;
} else {
    cout << "Fractions alag hain ." << endl;
}
return 0;
}