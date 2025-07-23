#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    double a, b;
    char operation;

    while (true) {
        cout << "Enter first num: ";
        cin >> a;

        cout << "Enter second num: ";
        cin >> b;

        cout << "Enter +, -, *, / : ";
        cin >> operation;

        try {
            if (operation == '/') {
                if (b == 0) {
                    throw runtime_error("Division by zero is not allowed.");
                }
            }

            double result;
            switch (operation) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result =  a / b;
                    break;
                default:
                    throw runtime_error("Invalid operation.");
            }

            cout << "Result: " << result << endl;
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
            continue; 
        }
        break; 
    }

    return 0;
}

