// Hirna Derege
// 05.26.2024
// header for stack

#ifndef STACK_H
#define STACK_H

//#include <iostream>
// using namespace std;

class Stack {
    private:
        struct stackNode{
            int value; 
            stackNode* next;
        };
        stackNode* top;
    public:
        Stack();
        ~Stack();
        void push(int);
        int pop();
        int peek();
        bool isEmpty() const;

};

#endif
