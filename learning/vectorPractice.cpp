// Hirna Derege
// oct 20, 2024
// vectors, stack, queue, lab4.cpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// function to return size of vector, O(1)
int stackSize(vector<char> x){
    return x.size();
    
} // end of stackSize

// function to check if signs are mathcing
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
} // end of isMatching

// main function
int main() {
    string input;
    vector<char> stack;

    cout << "enter value you want stored in stack:(0 to quit) ";
    cin >> input;

    for(char sign : input){
        if(sign == '(' || sign == '{' || sign == '['){
            stack.push_back(sign);
        } else if(sign == ')' || sign == '}' || sign == ']'){
            if(stack.empty() || !isMatching(stack.back(), sign)){
                cout << "no! " << endl;
                return 0;
            }
            stack.pop_back();
        }
    }
    
    if(stack.empty())
        cout << "yes! list is balanced" << endl;
    else  
        cout << "no! " << endl;

    return 0;
} // end of main