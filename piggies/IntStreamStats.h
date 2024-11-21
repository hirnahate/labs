// Hirna Derege
// oct 9, 2024
// header file, zoo.cpp

#ifndef INTSTREAMSTATS_H
#define INTSTREAMSTATS_H

class zoo {
    private:        
        struct Node {
            int val;
            Node* next;
        };
        Node* head;
    public:
        zoo();                      // end of constructor
        ~zoo();                     // end of deconstructor
        void appendNode(int num);
        void displayStats();
        void calcMin();
        void calcMax();
        void calcAvg();
};

#endif