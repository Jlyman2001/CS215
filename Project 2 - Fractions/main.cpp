#include <iostream>
#include "fraction.h"

using namespace std;

int main() {


    Fraction f1(12, 8);
    Fraction f2(-4, 3);
    Fraction result;


    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)) {
        cout << "The two Fractions (f1 and f2) are equal." << endl;
    }
    else {
        cout << "The two Fractions (f1 and f2) are not equal." << endl;
    }

    Fraction f3(-9, 8);
    Fraction f4 = f1.dividedBy(f2);

    if (f3.isEqualTo(f4)) {
        cout << "The two Fractions (";
        f3.print();
        cout << " and ";
        f4.print();
        cout << ") are equal." << endl;
    }
    else {
        cout << "The two Fractions (";
        f3.print();
        cout << " and ";
        f4.print();
        cout << ") are not equal." << endl;
    }

    return 0;
}
