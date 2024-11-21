// Hirna Derege
// Class Declaration

#ifndef FANCYLIST_H
#define FANCYLIST_H

#include <iostream>
using namespace std;

class Fancy {
    private:
        struct Node {
            int value;
            Node* next;
        };
        Node* head = nullptr;
    public:
        int displayMenu();
        void appendNode(int);
        void displayList();
        void reverseList();
        void deleteNode(int);
        void destroyList();

};
#endif