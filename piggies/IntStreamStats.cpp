// Hirna Derege
// oct 9, 2024
// implementation, IntStreamStats.cpp

#include <iostream>
#include "IntStreamStats.h"
using namespace std;

zoo :: zoo() {              
    head = nullptr;
} // end of constructor

void zoo :: appendNode(int num){
    Node* newNode;
    newNode = new Node;
    newNode->val = num;
    newNode->next = nullptr;

    if(!head){
        head = newNode;
    } else {
        Node* curr = head;
        Node* prev = nullptr;

        while(curr != nullptr && curr->val < num){
            prev = curr;
            curr = curr->next;
        }

        if(prev == nullptr){
            newNode->next = curr;
            head = newNode;
        } else {
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}// end of appendNode

void zoo :: calcMin(){
    if(head == nullptr){
        cout << "list is empty! " << endl;
    } else {
        cout << head->val << endl;
    }
} // end of min


void zoo :: calcMax(){
    if(head == nullptr){
        cout << "list is empty! " << endl;
    } else {
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        cout << temp->val << endl;
    }
} // end of max

void zoo :: calcAvg(){
    if(head == nullptr){
        cout << "list is empty! " << endl;
    } else {
        int count = 0;
        int sum = 0;
        Node* temp = head;
        while(temp != nullptr){
            sum += temp->val;
            count++;
            temp = temp->next;
        }
        cout << static_cast<double>(sum)/count << endl;
    }

} // end of avg

void zoo :: displayStats() {
    cout << "\nthe minimum number of bags was ";
    calcMin();
    cout << "\nthe average number of bags was ";
    calcAvg();
    cout << "\nthe maximum number of bags was ";
    calcMax();

} // end of display

zoo :: ~zoo() {
    Node* curr = head;
    while(curr){
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
} // end of deconstructor
