#include <iostream>
#include <cmath>
using namespace std;
class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    bool operator==(const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    // cmath is used because c++ is not taking this thing  without library i have asked this from GPT
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex add = c1 + c2;
    Complex minus = c1 - c2;
    Complex multiply = c1 * c2;
    cout << "c1 : " << c1 << endl;
    cout << "c2 : " << c2 << endl;
    cout  << add << endl;
    cout <<  minus << endl;
    cout  << multiply << endl;
    if (c1 == c2)
        cout << "c1 and c2 bilkul same hain boss." << endl;
    else
        cout << "c1 and c2 bilkul alag hain boss." << endl;
    cout << c1.magnitude() << endl;

    return 0;
}
