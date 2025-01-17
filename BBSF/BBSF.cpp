// Hirna Derege
// nov 11, 2024
// implementation, BBSF.cpp

#include <iostream>
#include <vector>
#include <sstream>
#include "BBSF.h"
using namespace std;

BBSF :: Node* BBSF :: insertNode(int n){
    if(!head){
        head = new Node();
        head->bstRoot = new Tree(n);
        head->bstSize = 1;
        size++;
        return head;
    }

    Node* minimum = head;
    for(Node* curr = head; curr != nullptr; curr = curr->next){
        if(searchBST(curr->bstRoot, n)){
            cout << "already in forest! " << endl;
            return nullptr;
        }

        if(curr->bstSize < minimum->bstSize)
            minimum = curr;
    }

    minimum->bstRoot = insert(minimum->bstRoot, n);
    minimum->bstSize++;
    size++;
    return head;
} // end of insertNode

BBSF :: Tree* BBSF :: insert(Tree* root, int n){
    if(!root)
        return new Tree(n);

    if (n < root->val) 
        root->left = insert(root->left, n);
    else if (n > root->val) 
        root->right = insert(root->right, n);

    return root;
} // end of insert

void BBSF :: deleteBST(int n){
    Node* prev = nullptr;
    Node* curr = head;

    while(curr) {
        if(searchBST(curr->bstRoot, n)){
            curr->bstRoot = deleteFromBST(curr->bstRoot, n);
            curr->bstSize--;
            size--;

            if(curr->bstSize == 0){
                if(prev)
                    prev->next = curr->next;
                else   
                    head = curr->next;
                delete curr;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "element is not in forest!" << endl;
} // end of deleteBST

BBSF :: Tree* BBSF :: deleteFromBST(Tree* root, int n){
    if(!root)   
        return nullptr;
    if (n < root->val) {
        root->left = deleteFromBST(root->left, n);
    } else if (n > root->val) {
        root->right = deleteFromBST(root->right, n);
    } else {
        if(!root->left){
            Tree* temp = root->right;
            delete root;
            return temp;
        } else if(!root->right){
            Tree* temp = root->left;
            delete root;
            return temp;
        }

        Tree* temp = minimum(root->right);
        root->val = temp->val;
        root->right = deleteFromBST(root->right, temp->val);
    }
    return root;
} // end of deleteFromBST

bool BBSF::searchBST(Tree* root, int n) {
    if (!root)
        return false;
    if (root->val == n)
        return true;
    return n < root->val ? searchBST(root->left, n) : searchBST(root->right, n);
} // end of searchBST

BBSF :: Tree* BBSF :: parentSearch(Tree* root, int n){
    Node* curr = head;
    while(curr){
        if(searchBST(curr->bstRoot, n))
            return curr->bstRoot;
        curr = curr->next;
    }
    return nullptr;
} // end of parentSearch

BBSF :: Tree* BBSF :: pointerSearch(Tree* root, int n){
    if(!root)
        return nullptr;
    if(root->val < n)
        root->left = pointerSearch(root->left, n);
    else if (root->val > n)
        root->right = pointerSearch(root->right, n);
    else
        return root;

    return nullptr;
} // end of pointerSearch

void BBSF :: merge(){
    if(!head)
        return;

    vector<int> elements;
    Node* curr = head;
    while(curr){
        inOrder(curr->bstRoot,elements);
        curr = curr->next;
    }

    Tree* merged = nullptr;
    for(int val : elements)
        merged = insert(merged, val);

    head = new Node(elements.size());
    head->bstRoot = merged;
    size = elements.size();
} // end of merge

BBSF :: Tree* BBSF :: minimum(Tree* root){
    while(root && root->left != nullptr)
        root = root->left;
    return root;
} // end of minimum

void BBSF :: inOrder(Tree* root, vector<int>& elements){
    if(!root)
        return;

    inOrder(root->left, elements);
    elements.push_back(root->val);
    inOrder(root->right, elements);
} // end of inOrder
