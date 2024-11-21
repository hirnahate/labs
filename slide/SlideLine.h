// Hirna Derege
// oct 14, 2024
// header file, slideline.h

#ifndef SLIDELINE_H
#define SLIDELINE_H
#include <string>
#include <fstream>

// Define the linked list class
class SlideLine {
    private:
        // Structure for a node in the linked list
        struct BabyAnimal {
            int age;
            char name;
            int timer;
            int slideCount;
            BabyAnimal* next;
        
            BabyAnimal(char n = ' ', int a = 0, int t = 0) : name(n), age(a), timer(t), slideCount(0), next(nullptr) {}

            /*
            BabyAnimal(char name, int age){
                this->name = name;
                this->age = age;
                this->timer = age;
                this->slideCount = 0;
                this->next = nullptr;
            }
            */
            
        };
        // Pointer to the first node in the list
        BabyAnimal* head;
        BabyAnimal* rear;
        int numItems;

    public:
        // Constructor initializes head to NULL
        SlideLine();
        bool isEmpty() const;
        void insertAtBeginning(int age, int timer, char name);
        void insertAtEnd(BabyAnimal* node);
        void deleteFromBeginning();
        void goSlide();
        int readFile(char order[], int& n);
        void displayLine();
        void swapNodes(BabyAnimal* newAnimal, char name1, char name2);
};

#endif


