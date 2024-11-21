
#include <iostream>
#include <string>
#include <fstream>
#include "SlideLine.h"
using namespace std;

// Constructor
SlideLine::SlideLine() {
    head = nullptr;
    rear = nullptr;
    numItems = 0;
} // end of constructor

// Read from file and set up the line of animals
int SlideLine::readFile(char order[], int& n) {
    ifstream inFile;
    string filename;
    cout << "Enter a filename: ";    // baby_animals.in
    cin >> filename;

    inFile.open(filename);
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return -1;
    }

    inFile >> n;
    for (int i = 0; i < n; i++) {
        BabyAnimal* newAnimal = new BabyAnimal;
        inFile >> newAnimal->name >> newAnimal->age;
        newAnimal->timer = newAnimal->age;  // Set timer to the age of the baby animal
        insertAtEnd(newAnimal);            // Insert into the list
        //swapNodes(newAnimal, newAnimal->name, newAnimal->next->name);
    }

    for (int j = 0; j < n; j++) {
        inFile >> order[j];
    }

    inFile.close();
    return n;
} // end of readFile

// Insert an animal at the beginning of the line
void SlideLine::insertAtBeginning(int age, int timer, char name) {
    BabyAnimal* newAnimal = new BabyAnimal(name, age, timer);
    if (isEmpty()) {
        head = newAnimal;
        rear = newAnimal;
    } else {
        newAnimal->next = head;
        head = newAnimal;
    }
    numItems++;
} // end of insertBegin

// Insert an animal at the end of the line
void SlideLine::insertAtEnd(BabyAnimal* node) {
    if (isEmpty()) {
        head = rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
    rear->next = nullptr;  // Ensure the rear's next is null
    numItems++;
} // end of insertEnd

// Delete the animal at the beginning of the line
void SlideLine::deleteFromBeginning() {
    if (isEmpty()) {
        cout << "The line is empty!" << endl;
        return;
    }

    BabyAnimal* temp = head;
    head = head->next;
    delete temp;
    numItems--;

    if (head == nullptr) {
        rear = nullptr;
    }
} // end of delete

// Check if the list is empty
bool SlideLine::isEmpty() const {
    return head == nullptr;
} // end of isEmpty

// Simulate the slide turns
void SlideLine::goSlide() {
    if (isEmpty()) return;

    BabyAnimal* curr = head;
    BabyAnimal* prev = nullptr;

    while (curr != nullptr) {
        curr->slideCount++;  // Increment slide count
        curr->timer--;       // Decrement timer

        // If slideCount reaches 5, the baby animal goes home (delete it)
        if (curr->slideCount >= 5) {
            BabyAnimal* temp = curr;
            curr = curr->next; // Move to the next animal before deleting
            delete temp;
            numItems--;
            if (prev) {
                prev->next = curr;
            } else {
                head = curr;  // If we removed the head, update head pointer
            }
            continue;
        }

        // If the timer reaches zero, reset it and move the animal to the back of the line
        if (curr->timer == 0) {
            curr->timer = curr->age; // Reset the timer to its age
            BabyAnimal* temp = curr;
            curr = curr->next;  // Move to the next node
            if (prev) {
                prev->next = curr;
            } else {
                head = curr;  // If we removed the head, update head pointer
            }
            insertAtEnd(temp);  // Move the current animal to the end of the line
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
} // end of goSLdie

// Display the line and write it to a file
void SlideLine::displayLine() {
    ofstream outFile("baby_animals.out");
    BabyAnimal* temp = head;
    while (temp) {
        cout << temp->name << " ";        // Display on console
        outFile << temp->name << " ";     // Write to file
        temp = temp->next;
    }
    outFile.close();
} // end of displayLine

// Swap nodes (not used in the slide functionality but provided)
void SlideLine::swapNodes(BabyAnimal* newAnimal, char name1, char name2) {
    if (name1 == name2) return;

    BabyAnimal *prevX = nullptr, *currX = nullptr;
    BabyAnimal *prevY = nullptr, *currY = nullptr;
    BabyAnimal *curr = head;

    // Find name1 (currX) in the linked list
    while (curr != nullptr) {
        if (curr->name == name1) {
            currX = curr;
            break;
        }
        prevX = curr;
        curr = curr->next;
    }

    curr = head;

    // Find name2 (currY) in the linked list
    while (curr != nullptr) {
        if (curr->name == name2) {
            currY = curr;
            break;
        }
        prevY = curr;
        curr = curr->next;
    }

    if (currX == nullptr || currY == nullptr) return;

    if (prevX != nullptr) {
        prevX->next = currY;
    } else {
        head = currY;
    }

    if (prevY != nullptr) {
        prevY->next = currX;
    } else {
        head = currX;
    }

    BabyAnimal* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
} // end of swapNodes
