#include <iostream>
#include <cmath>
using namespace std;
class Polynomial {
private:
    int degree;
    double* coefficients;
public:
    Polynomial(int deg = 0) : degree(deg) {
        coefficients = new double[degree + 1]();
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    void setCoefficient(int deg, double coeff) {
        if (deg <= degree) {
            coefficients[deg] = coeff;
        }
    }

    double getCoefficient(int deg) const {
        return (deg <= degree) ? coefficients[deg] : 0.0;
    }

    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        Polynomial result(maxDegree);
        for (int i = 0; i <= maxDegree; ++i) {
            result.setCoefficient(i, this->getCoefficient(i) + other.getCoefficient(i));
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        Polynomial result(maxDegree);
        for (int i = 0; i <= maxDegree; ++i) {
            result.setCoefficient(i, this->getCoefficient(i) - other.getCoefficient(i));
        }
        return result;
    }

    Polynomial operator*(const Polynomial& other) const {
        Polynomial result(degree + other.degree);
        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                result.setCoefficient(i + j, result.getCoefficient(i + j) + this->getCoefficient(i) * other.getCoefficient(j));
            }
        }
        return result;
    }

    double evaluate(double x) const {
        double result = 0.0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    void display() const {
        for (int i = degree; i >= 0; --i) {
            cout << coefficients[i];
            if (i > 0)
                cout << "x^" << i << " + ";
        }
        cout << endl;
    }
};
int main() {
    Polynomial p1(2); 
    p1.setCoefficient(0, 1); 
    p1.setCoefficient(1, 2); 
    p1.setCoefficient(2, 3); 

    Polynomial p2(1); 
    p2.setCoefficient(0, 4); 
    p2.setCoefficient(1, 5); 

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    cout << "Polynomial 1  ";
    p1.display();
    
    cout << "Polynomial 2  ";
    p2.display();

    cout << "their sum: ";
    sum.display();

    cout << "difference: ";
    diff.display();

    cout << "Multiplying it   ";
    prod.display();

    double x = 2.0;
    cout << "If we put x = 1 so we will get ans  " << x << ": " << p1.evaluate(x) << endl;
    
    return 0;
}