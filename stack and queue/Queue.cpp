// Hirna Derege
// 05.26.2024
// the is the driver for the queue

#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;


Queue :: Queue(){
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}// end of constructor


void Queue :: enqueue(int num){
    queueNode* newNode = new queueNode;
    newNode->value = num;
    newNode->next = nullptr;

    if(isEmpty()){
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;

}// end of enqueue()


int Queue :: dequeue(){
    if(isEmpty()){
        cout << "queue is empty! " << endl;
        return -1;
    } else {
        int returnVal = front->value;

        queueNode* temp = front;
        front = front->next;
        delete temp;
        numItems--;

        return returnVal;
    }

}// end of dequeue()


bool Queue :: isEmpty() const{
    return numItems == 0;

}// end of isEmpty()

