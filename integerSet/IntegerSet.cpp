// create functions...
#include <iostream>
#include "IntegerSet.h"
using namespace std;

// empty set constructor, 
IntegerSet :: IntegerSet(){
    size = 101;
    arr = new int[size];
    emptySet();
}

// array size constructor, recieves arr of ints and size of the arr
IntegerSet :: IntegerSet(int arrTwo[], int arrSize){
    size = arrSize;
    arr = new int[size];
    for (int i = 0; i < size; i++){
        arr[i] = arrTwo[i];
    }
}

// deconstructor
IntegerSet :: ~IntegerSet() {
        delete[] arr;
}


// functions

// creates a third set that is the 
// set-theoretic union of two existing sets
IntegerSet IntegerSet :: unionOfsets(const IntegerSet& setA) const{
    IntegerSet setB;
    for (int i = 0; i < size; i++){
        setB.arr[i] = arr[i] || setA.arr[i];
    }
    return setB;
} // end of unionOfsets

// creates a third set which is the 
// set-theoretic intersection of two existing sets

IntegerSet IntegerSet :: intersectOfsets(const IntegerSet& setA) const{
    IntegerSet setB;
    for (int i = 0; i < size; i++){
        setB.arr[i] = arr[i] && setA.arr[i];
    }
    return setB;
}// end of interOfsets

// inserts a new integer k into a set (be setting a[k] to 1).
void IntegerSet :: insertElement(int k){
    if (validEntry(k))
        arr[k] = 1;
} // end of insertElement

// deletes integer m (by setting a[m] to 0).
void IntegerSet :: deleteElement(int m){
    if(validEntry(m))
        arr[m] = 0;
} // end of deleteElement

// prints a set as a list of numbers separated by spaces. 
// Print only those elements that are present in the set
void IntegerSet :: printSet() const{ 
    cout << " { ";
    for (int i = 0; i < size; i++){
        if(i != 0 ){
            cout << arr[i] << " ";
        } else {
            cout << "-" << " ";
        }
    }
    cout << " }";
} // end of printSet

//  determines whether two sets are equal.
bool IntegerSet :: isEqualTo(const IntegerSet& setA) const{
    for(int i = 0; i < size; i++){
        if(arr[i] != setA.arr[i]){
            return false;
        }
    }
    return true;
} // isEqualTo

// sets all elements of set to 0.
void IntegerSet :: emptySet(){
    for (int i = 0; i < size; i++){
        arr[i] = 0;
        
    }
} // end of emptySet

// reads value from user into the set.
void IntegerSet :: inputSet(){
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
} // end of inputSet

// determines a valid entry to the set 
// (i.e., in the range 0 through 100).
bool IntegerSet :: validEntry(int n) const{
    return (n >= 0 && n <= 100);
} // end of validEntry
