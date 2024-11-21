// Hirna Derege
// driver program || hw3.cpp

#include <iostream>
#include "FancyList.h"
using namespace std;

int main(int argc, char *argv[]){
    Fancy list;
    int choice;
    do{
        choice = list.displayMenu();
        switch(choice) {
            case 1:
            int num;
            while (true) {
            cout << "Type a number for appending (type x to stop): ";
            cin >> num;
                if (cin.fail() || cin.peek() == 'x') {
                    cin.clear(); // clear the fail state
                    cin.ignore(10000, '\n'); // ignore remaining characters
                    break; // exit the loop
                }
            list.appendNode(num);
            }
            break;

            case 2:
            cout << "Current list is: ";
            list.displayList();
            break;

            case 3:
            list.reverseList();
            break;

            case 4:
            int gone;
            cout << "Delete n-th node from the end of the list, your n is: ";
            cin >> gone;
            cout << "Current list after deleting the " << gone << " -th node from the end is: ";
            list.deleteNode(gone);
            break;

            case 5:
            list.destroyList();
            return 0;
            break; 

            default:
            cout << "Invalid entry  " << choice << endl;
             
        }
    } while(choice != 5);

    return 0;
}// end of main