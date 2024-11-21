// Hirna Derege
// 04.28.2024
// hw2.cpp
// this program will create a class IntegerSet for which each object can hold integers in the 
// range 0 through 100.  This customized set is represented internally as an array of ones 
// and zeros; array elements a[i] is 1 if integer i is in the set. 


// main function calling all
#include <iostream>
#include "IntegerSet.h"
using namespace std;

int main(int argc, char *argv[]) {
    // Create sets A and B
    IntegerSet setA;
    IntegerSet setB;

    // Input for set A
    cout << "Enter set A: " << endl;
    int num;
    while (true) {
        cout << "Enter an element (Type x to stop): ";
        cin >> num;
        if (cin.fail() || cin.peek() == 'x') {
            cin.clear(); // clear the fail state
            cin.ignore(10000, '\n'); // ignore remaining characters
            break; // exit the loop
    }
    setA.insertElement(num);
}

    cout << "Entry complete\n";

    // Input for set B
    cout << "\nEnter set B: " << endl;
     while (true) {
        cout << "Enter an element (Type x to stop): ";
        cin >> num;
        if (cin.fail() || cin.peek() == 'x') {
            cin.clear(); // clear the fail state
            cin.ignore(10000, '\n'); // ignore remaining characters
            break; // exit the loop
    }
    setB.insertElement(num);
}
    cout << "Entry complete\n\n";

    // Union of sets A and B
    cout << "Union of A and B is:\n";
    (setA.unionOfsets(setB)).printSet();
    cout << endl;

    // Intersection of sets A and B
    cout << "\nIntersection of A and B is:\n";
    (setA.intersectOfsets(setB)).printSet();
    cout << endl;

    // Check equality of sets A and B
    cout << "\nSet A is ";
    if (!setA.isEqualTo(setB)) {
        cout << "not ";
    }
    cout << "equal to set B\n";

    // Insert an element into set A
    int element;
    cout << "What element would you like to insert into set A?: ";
    cin >> element;
    setA.insertElement(element);
    cout << "Set A is now:\n";
    setA.printSet();
    cout << endl;

    // Delete an element from set A
    cout << "\nDeleting " << element <<" from set A...\n";
    setA.deleteElement(element);
    cout << "Set A is now:\n";
    setA.printSet();
    cout << endl;

    // Test with a specific array
    int newArr[] = {25, 67, 2, 9, 99, 105, 45, -5, 100, 1};
    int newArrSize = sizeof(newArr) / sizeof(newArr[0])+1;
    IntegerSet setArr(newArr, newArrSize);

    cout << "\nNow creating a set of specific values and testing the bounds limits." << endl;
    IntegerSet setC(newArr, 11);
    cout << "Creating array of size 10: ";
    setArr.printSet();
    cout << "\nSet C is:\n";
    setC.printSet();
    cout << endl;

    return 0;
}
