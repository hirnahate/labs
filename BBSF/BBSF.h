// Hirna Derege
// nov 11, 2024
// header file, BBSF.h

#ifndef BBSF_H
#define BBSF_H

#include <vector>
#include <iostream>
using namespace std;

class BBSF {
    private:
        struct Tree{
            int val;
            Tree* left;
            Tree* right;

            Tree(int n = 0) : val(n), left(nullptr), right(nullptr) {}
        };

        struct Node{
            int bstSize;
            Tree* bstRoot;
            Node* next;

            Node(int size = 0) : bstSize(size), bstRoot(nullptr), next(nullptr) {}
        };
        Node* head;
        int size;

    public:
        using Tree = struct Tree;
        using Node = struct Node;
        Node* getHead() const { return head; }
        int getSize() const { return size; }

        Node* insertNode(int);
        Tree* insert(Tree*, int);

        void deleteBST(int);
        bool searchBST(Tree*, int);
        Tree* parentSearch(Tree*, int);
        Tree* pointerSearch(Tree*, int);
        void merge();

        Tree* deleteFromBST(Tree*, int);
        Tree* pointerSearchBSF(int);
        Tree* minimum(Tree*);   
        void inOrder(Tree* , vector<int>&);
};

#endif
