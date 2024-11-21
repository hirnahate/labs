// Hirna Derege
// oct 7, 2024
// zoo, hw1.cpp
// this program will get the number of bags pig eats and will output stats

/*
I have not received unauthorized aid on this assignment. I understand the answers that I have
submitted. The answers submitted have not been directly copied from another source, but
instead are written in my own words.
*/

#include <iostream>
#include "IntStreamStats.h"
using namespace std; 

int main() {
    zoo numBags;
    int n;

    cout << "enter the number of bags the pig ate today:(0> to exit) ";
    cin >> n;
    while(n >= 0){
        numBags.appendNode(n);
        //cout << "enter the number of bags the pig ate today:(0> to exit) ";
        cin >> n;
    }

    numBags.displayStats();

    return 0;
} // end of main
