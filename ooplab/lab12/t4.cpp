#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
public:
    vector<int> coeffs;
    
    Polynomial(vector<int> c) {
        coeffs = c;
    }
    
    Polynomial operator+(Polynomial other) {
        int maxSize = max(coeffs.size(), other.coeffs.size());
        vector<int> result(maxSize, 0);
        
        for (int i = 0; i < coeffs.size(); i++) {
            result[i] += coeffs[i];
        }
        
        for (int i = 0; i < other.coeffs.size(); i++) {
            result[i] += other.coeffs[i];
        }
        
        return Polynomial(result);
    }
    
    Polynomial operator-(Polynomial other) {
        int maxSize = max(coeffs.size(), other.coeffs.size());
        vector<int> result(maxSize, 0);
        
        for (int i = 0; i < coeffs.size(); i++) {
            result[i] += coeffs[i];
        }
        
        for (int i = 0; i < other.coeffs.size(); i++) {
            result[i] -= other.coeffs[i];
        }
        
        return Polynomial(result);
    }
    
    Polynomial operator*(Polynomial other) {
        vector<int> result(coeffs.size() + other.coeffs.size() - 1, 0);
        
        for (int i = 0; i < coeffs.size(); i++) {
            for (int j = 0; j < other.coeffs.size(); j++) {
                result[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        
        return Polynomial(result);
    }
    
    void print() {
        for (int i = coeffs.size() - 1; i >= 0; i--) {
            if (coeffs[i] != 0) {
                cout << coeffs[i];
                if (i > 0) {
                    cout << "x^" << i;
                }
                if (i > 0) cout << " + ";
            }
        }
        cout << endl;
    }
};

int main() {
    Polynomial p1({1, 2, 3});
    Polynomial p2({2, 1});
    
    cout << "P1: ";
    p1.print();
    
    cout << "P2: ";
    p2.print();
    
    Polynomial sum = p1 + p2;
    cout << "P1 + P2: ";
    sum.print();
    
    Polynomial diff = p1 - p2;
    cout << "P1 - P2: ";
    diff.print();
    
    Polynomial product = p1 * p2;
    cout << "P1 * P2: ";
    product.print();
    
    return 0;
}
