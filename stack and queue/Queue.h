// Hirna Derege
// 05.26.2024
// header for queue

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    private:
        struct queueNode{
            int value;
            queueNode* next;
        };
        queueNode* front;
        queueNode* rear;
        int numItems;
    public:
        Queue();
        void enqueue(int);
        int dequeue();
        bool isEmpty() const;
};

#endif
