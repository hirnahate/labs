// Hirna Derege
// nov 11, 2024
// main file, hw5.cpp

#include <iostream>
#include <sstream>
#include "BBSF.h"
using namespace std;

string displayMenu(){
    string choice;
    cout << "\n************ Menu ************" << endl;
    cout << "I <num> - insert <num>" << endl;
    cout << "D <num> - delete <num> " << endl;
    cout << "S <num> - search for <num>, if found print yes, else no" << endl;
    cout << "P <num> - search for <num>, if founf print size of <num>'s BST, else 0" << endl;
    cout << "NUM - prints total num of elements in BSF" << endl;
    cout << "SOR - prints all elements in BBSF (sorrted)" << endl;
    cout << "TER - deletes all the elements in BBSF and exits" << endl;

    cout << "what operation would you like to execute? ";
    getline(cin, choice);

    return choice;
} // end of displayMenu

int main(){
    BBSF tree;  
    string operation;

    displayMenu();
    while(true){
        operation = displayMenu();

        stringstream sym(operation);
        string choice;
        int num;

        sym >> choice;
        if(choice == "I" || choice == "i"){
            if(sym >> num)
                tree.insertNode(num);
            else    
                cout << "invalid input. please enter a char and a int " << endl;
        } 
        
        else if(choice == "D" || choice == "d"){
            if(sym >> num)
                tree.deleteBST(num);
            else    
                cout << "invalid input. please enter a char and a int " << endl;
        } 
        
        else if(choice == "S" || choice == "s"){
            if(sym >> num)
                if(tree.searchBST(tree.getHead()->bstRoot, num))
                    cout << num << " is a member of the forest! " << endl;
                else 
                    cout << num << " is not a member of the forest. " << endl;
            else    
                cout << "invalid input. please enter a char and a int " << endl;
        } 
        
        else if(choice == "P" || choice == "p"){
            if(sym >> num){
                BBSF :: Tree* parentBST = tree.parentSearch(tree.getHead()->bstRoot, num);
                if(parentBST)
                    cout << "the BST containig " << num << " parent is " << parentBST << endl;
                else 
                    cout << num << " is not a member of the forest. " << endl;
            } else    
                cout << "invalid input. please enter a char and a int " << endl;
        } 

        else if(choice == "NUM" || choice == "num")
            cout << "total number of elements in the forest: " << tree.getSize() << endl;

        else if (choice == "SOR" || choice == "sor"){
            vector<int> sorted;
            BBSF :: Node* curr = tree.getHead();
            while(curr){
                tree.inOrder(curr->bstRoot, sorted);
                curr = curr->next;
            }

            cout << "sorted elements of forest: ";
            for(int i : sorted)
                cout << i << " ";
            cout << endl;
        } 

        else if(choice == "TER" || choice == "ter"){
            cout << "terminating program and clearing binary search forest..." << endl;
            delete tree.getHead();
            break;
        } 

        else    
            cout << "invalid choice, try again " << endl;
    }

    return 0;
} // end of main
