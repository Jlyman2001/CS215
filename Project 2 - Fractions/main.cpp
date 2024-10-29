#include <iostream>
#include "fraction.h"

using namespace std;

int main() {


    Fraction f1(9, 8);
    Fraction f2(4, 6);
    Fraction result;

    cout << "The product of " << f1 << " and " << f2 << " is " << f1.multipliedBy(f2) << endl;
    cout << "The quotient of " << f1 << " and " << f2 << " is " << f1.dividedBy(f2) << endl;
    cout << "The sum of " << f1 << " and " << f2 << " is " << f1.addedTo(f2) << endl;
    cout << "The difference of " << f1 << " and " << f2 << " is " << f1.subtract(f2) << endl;

    if (f1 == f2) {
        cout << "The two Fractions (" << f1 << " and " << f2 << ") are equal." << endl;
    }
    else {
        cout << "The two Fractions (" << f1 << " and " << f2 << ") are not equal." << endl;
    }

    Fraction f3(30, 40);
    Fraction f4 = f1.multipliedBy(f2);

    if (f3 == f4) {
        cout << "The two Fractions (" << f3 << " and " << f4 << ") are equal." << endl;
    }
    else {
        cout << "The two Fractions (" << f3 << " and " << f4 << ") are not equal." << endl;
    }


    Fraction f5; //0
    Fraction f6 = f5.multipliedBy(f4);
    cout << "The product of " << f5 << " and " << f4 << " is " << f6 << endl;

    f5 = f3.dividedBy(f4); //1
    cout << "The quotient of " << f3 << " and " << f4 << " is " << f5 << endl;

    f5 = Fraction(24, 30);
    f6 = Fraction(42, 35);
    cout << "The sum of " << f5 << " and " << f6 << " is " << f5.addedTo(f6) << endl;
    return 0;
}
