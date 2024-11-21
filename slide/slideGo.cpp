// Hirna Derege
// oct 14, 2024
// main file, hw2.cpp
// this program will

/*
I have not received unauthorized aid on this assignment. I understand the answers that I have
submitted. The answers submitted have not been directly copied from another source, but
instead are written in my own words.
*/

#include <iostream>
#include "SlideLine.h"
using namespace std;

int main() {
    SlideLine line;
    int n;
    char order[n];

    // Read the input from the file and set up the line
    line.readFile(order, n);

    // Process the baby animals' slide turns
    for(int i = 0; i < 5 * n; i++){
        line.goSlide();

    }
    // Display the final line and save it to the output file
    line.displayLine();

    return 0;
}
