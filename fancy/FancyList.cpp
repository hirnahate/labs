// Hirna Derege
// class implecation

#include <iostream>
#include "FancyList.h"
using namespace std;

int Fancy :: displayMenu(){
    int choice;

    cout << "\n********* FancyList Menu *********" << endl;
    cout << "1. Create a list" << endl;
    cout << "2. Display the list" << endl;
    cout << "3. Reverse the list" << endl;
    cout << "4. Delete the n-th node from the end of the list" << endl;
    cout << "5. Exit the program" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;

    return choice;
}// end of displayMenu

void Fancy :: appendNode(int num){
    Node* newNode;
    newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;

    if(!head){
        head = newNode;
    } else {
        Node* curr = head;
        Node* prev = nullptr;

        while(curr != nullptr && curr->value < num){
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

void Fancy :: displayList(){
    Node* curr = nullptr;
    curr = head;

    while(curr){
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}// end of displayList


void Fancy :: reverseList(){
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        head = prev;
    }

    cout << "Current list after reversing is: ";
    displayList();

}// end of reverseList


void Fancy :: deleteNode(int num){
    Node* curr = nullptr;
    Node* prev;

    if(!head)
        return;
    if(head->value == num){
        curr = head->next;
        delete head;
        head = curr;
    } else {
        curr = head;
        while (curr != nullptr && curr->value != num){
            prev = curr;
         curr = curr->next;
        }
        if (curr){
            prev->next = curr->next;
            delete curr;
        }
    }

    displayList();
}// end of deleteNode

void Fancy :: destroyList(){
    Node* curr = head;

    cout << "Deallocating..." << endl;
    while(curr){
        cout << "Deleting " << curr->value << endl;
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
}// end of destroyList

