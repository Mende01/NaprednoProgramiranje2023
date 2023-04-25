//Mende Talevski INKI1010
#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
private:
    double num1, num2;
    int x;
public:
    Calculator(double n1, double n2) {
        num1 = n1;
        num2 = n2;
    }

    double add() {
        return num1 + num2;
    }

    double subtract() {
        return num1 - num2;
    }

    double multiply() {
        return num1 * num2;
    }

    double divide() {
        return num1 / num2;
    }
    double kvadrat() {
        return pow(num1, num2);
    }
    double exp() {
        return pow(x, (num1 + num2));
    }
};

int main() {
    double n1, n2;
    int choice;

    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    Calculator calc(n1, n2);

    cout << "Enter your choice: " << endl;
    cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5.Kvadrat\n6.Exp" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Result = " << calc.add() << endl;
        break;
    case 2:
        cout << "Result = " << calc.subtract() << endl;
        break;
    case 3:
        cout << "Result = " << calc.multiply() << endl;
        break;
    case 4:
        cout << "Result = " << calc.divide() << endl;
        break;
    case 5:
        cout << "Result = " << calc.kvadrat() << endl;
        break;
    case 6:
        cout << "Result = " << calc.exp() << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    return 0;
}
