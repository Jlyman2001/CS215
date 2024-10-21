//#include <iostream>
#include "dynamicarray.h"
using namespace std;

int main() {
    DynamicArray a;

    // Loop to append 200 through 220 to a (21 elements total)
    for (int i = 200; i < 221; i++) {
        a.append(i);
    }

    a.print();

    cout << "\nPrinting capacity of new array:\n";
    cout << a.cap() << endl << endl;

    int indices[] = { 19, 3, 15, 0, 21 };
    // Loop to access some arbitrary elements of a
    for (int i = 0; i < 5; i++) {
        cout << a.at(indices[i]) << " ";
    }
    cout << endl;

    // Print sum
    cout << "\nTesting sum\n";
    cout << a.sum() << endl;

    // Test remove:
    if (!a.remove(220)) cout << "Uh-oh, can't remove 220\n";
    if (a.remove(102)) cout << "Uh-oh, shouldn't be able to remove 102\n";

    // More tests: first, add 220 back in
    a.append(220);

    cout << "\nEliminating elements, one by one, from array, and testing resize.\n";
    int capacities[] = { 40,             // len is 20
                        32, 32, 32, 32, // len is 19, 18, 17, 16
                        25, 25, 25,     // len is 15, 14, 13
                        20, 20, 20,     // len is 12, 11, 10,
                        16, 16, 12, 12, 10, // len is 9, 8, 7, 6, 5
                        10, 10, 10, 10, 10 // 4, 3, 2, 1, 0
    };
    for (int i = 0; i < 21; i++) {
        a.remove(200 + i);
        if (a.cap() != capacities[i]) {
            cout << "Resize error! Removed " << 100 + i << ", capacity is " << a.cap()
                << ", should be " << capacities[i] << endl;
        }
    }

    cout << "\nAdding 252 to array. Final print should print just 252.\n";
    a.append(252);
    a.print();
    cout << endl;


    return 0;

}
