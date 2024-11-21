// Hirna Derege
// 06.02.2024
// hw4.cpp
// this fucntions will create a basic calculator in task one and a 
// sliding window function in task 2

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

// Task One function
int evaluate(string&);
int applyOperator(int, int, char);

// Task Two function
void slidingWindowAvg(string&, int);


// main function
int main(int argc, char* argv[]) {
    string equation;
    cout << "****Task 1****" << endl;
    cout << right;
    cout << setw(40) << "Type the equation (type # to quit): ";
    while (true) {
        cin >> equation;
        if (equation == "#") {
            break;
        }
        cout << setw(34) << "The value of this equation is ";
        cout << evaluate(equation) << endl;
        cout << endl;
        cout << setw(40) << "Type the equation (type # to quit): ";
    }

    string inputFile = argv[1];
    int windowSize = stoi(argv[2]);
   
    cout << "\n****Task 2****" << endl;
    cout << setw(40) << "The averages in each window of size " << windowSize << " are [ ";
    slidingWindowAvg(inputFile, windowSize);
    cout << "]" << endl;

    return 0;
} // end of main

int applyOperator(int operand1, int operand2, char op) {
    if (op == '+')
        return operand1 + operand2;
    else if (op == '-')
        return operand1 - operand2;
    return 0; // should not reach here
}

int evaluate(string& equation){
    Stack numStack;
    Stack signStack;
    
    int i = 0;
    if(equation[i] == '-'){
        int num = 0;
        i++;
        while(i < equation.length() && (equation[i] != '+' && equation[i] != '-')){
            num = num * 10 + (equation[i] - '0');
            i++;
        }
        numStack.push(-num);
    } else if (equation[i] != '+' && equation[i] != '-'){
        int num = 0;
        while(i < equation.length() && ( equation[i] != '+' && equation[i] != '-')){
            num = num * 10 + (equation[i] - '0');
            i++;
        }
        numStack.push(num);
    }

    for(; i < equation.length(); i++){
        if(equation[i] != '+' && equation[i] != '-'){
            int num = 0;
            while (i < equation.length() && equation[i] != '+' && equation[i] != '-'){
                num = num * 10 + (equation[i] - '0');
                i++;
            }
            numStack.push(num);
            i--;
        } else if (equation[i] == '+' || equation[i] == '-'){
            while(!signStack.isEmpty() && (equation[i] == '+' || equation[i] == '-')){
                char sign = signStack.peek();
                signStack.pop();
                int num2 = numStack.peek();
                numStack.pop();
                int num1 = numStack.peek();
                numStack.pop();
                int result = applyOperator(num1, num2, sign);
                numStack.push(result);
            }
            signStack.push(equation[i]);
        }

    }
    while(!signStack.isEmpty()){
        char sign = signStack.peek();
        signStack.pop();
        int num2 = numStack.peek();
        numStack.pop();
        int num1 = numStack.peek();
        numStack.pop();
        int result = applyOperator(num1, num2, sign);
        numStack.push(result);
    }
    return numStack.peek();
}// end of evaluate

void slidingWindowAvg(string& filename, int windowSize){
    ifstream inFile;
    inFile.open(filename);
    if(!inFile){
        cout << "error reading file! " << endl;
        return;
    }

    Queue window;
    int value;
    int sum = 0;
    int count = 0;
    while (inFile >> value){
        if(count < windowSize){
            window.enqueue(value);
            sum += value;
            count++;
        } else {
            int front = window.dequeue();
            sum -= front;
            window.enqueue(value);
            sum += value;
        }
        if(count == windowSize){
            cout << sum / windowSize << " ";
        }
    }
    inFile.close();

} // end of slidingWindow

