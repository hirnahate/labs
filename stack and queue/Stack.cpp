// Hirna Derege
// 05.26.2024
// driver for stack

#include <iostream>
#include "Stack.h"
using namespace std;


Stack :: Stack(){
    top = nullptr;
    
}// end of constructor

Stack :: ~Stack(){
    stackNode* curr = top;
    stackNode* next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        delete curr;
        curr = next;
    }
    top = nullptr;

}// end of deconstructor


void Stack :: push(int num){
    stackNode* newNode = new stackNode;
    newNode->value = num;

    if(isEmpty()){
        top = newNode;
        newNode->next = nullptr;
    } else {
        newNode->next = top;
        top = newNode;
    }

}// end of push()

int Stack :: pop(){
    stackNode* temp = nullptr;

    if(isEmpty()){
        //cout << "stack is empty! " << endl;
        return -1;
    } else {
        int returnVal = top->value;
        temp = top->next;
        delete top;
        top = temp;
        return returnVal;
    }

}// end of pop()

int Stack :: peek(){
    if(isEmpty()){
        //cout << "stack is empty! " << endl;
        return -1;
    } else {
        int returnVal = top->value;
        return returnVal;
    }

}// end of peek()


bool Stack :: isEmpty() const{
    return top == nullptr;
    
}// end of isEmpty()