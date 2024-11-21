// hirna derege
// database.cpp
// dec 3, 2023
// this prgoram will create an inventory database

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Item {
  string name;
  double price;
  int quanity;
};// end of struct

const int SIZE = 7;
const int ITEM_NOT_FOUND = -1;

int findItem (const Item array[], int size, const string& itemName){
  for (int i = 0; i < size; i++){
    if (array[i].name == itemName) {
      return i;
    }// end of if
  }// end of for
  return ITEM_NOT_FOUND;
}// end of findItem

void swapItems(Item& a, Item& b) {
  Item temp = a;
  a = b;
  b = temp;
}// end of swapItems

int main(){
  ifstream inFile;
  Item items[SIZE];
  int numItems = 0;
  string name;
  int ans;
  string itemName;
  double newPrice;
  
  inFile.open("collection.txt");
  while (inFile >> items[numItems].name && numItems < SIZE) {
    inFile >> items[numItems].price;
    inFile >> items[numItems].quanity;
    numItems++;
  }// end of while
  inFile.close();

  cout << "Hello!" << endl;

  while (true) {
    cout << "\nMenu\n1. Print item details.\n2. Print items with low inventory.\n3. Print all items in";
    cout << " order.\n4. Add Inventory.\n5. Update price.\n6. Sell item.\n7. Exit.";
    cout << "\nSelect one: ";
    cin >> ans;

    if (ans == 1){
      cout << "What is the name of your item? ";
      cin >> itemName;
      cout << endl;
      
      int index = findItem(items, numItems, itemName);
      if (index != ITEM_NOT_FOUND){
        cout << "\nItem name: " << items[index].name << endl;
        cout << "Price: $" << items[index].price << endl;
        cout << "Quantity: " << items[index].quanity << endl;
        cout << endl;
      }// end of if
      else 
        cout << "Item does not exist." << endl;
      
    }// end of if

    else if (ans == 2) {
      // print items with low inventory
      int lowest;
      cout << "What is the threshold quantity? ";
      cin >> lowest;
      cout << endl;
      
      for (int i = 0; i < SIZE; i++){
        if (items[i].quanity <= lowest){
          cout << "Item name: " << items[i].name << endl;
          cout << "Price: $" << items[i].price << endl;
          cout << "Quantity: " << items[i].quanity << endl;
          cout << endl;
        }// end of if
      }// end of for
    }// end of else if 2
    
    else if (ans == 3) {
      // print items in order aph
      for (int i = 0; i < SIZE - 1; i++){
        for (int j = 0; j < SIZE - 1; j++){
          if (items[j].name > items[j+1].name){
            swapItems(items[j], items[j+1]);
          }// end of if
        }// end of j for
      }// end of i for
      cout << "Items in alphabetical order:" << endl;
      for (int i = 0; i < SIZE; i++){
        cout << "\nItem name: " << items[i].name << endl;
        cout << "Price: $" << items[i].price << endl;
        cout << "Quantity: " << items[i].quanity << endl;
      }// end of for  
    }// end of else if 3

    else if (ans == 4){
      // add inventory. name of item and how many. if exist add. if not ask for price. print mess
      string newItem;
      int newQuan;
      double newPrice;
      bool itemExists = false;
      
      cout << "What is the name of the item you would like to add? ";
      cin >> newItem;
      cout << "How many is available? ";
      cin >> newQuan;
      
      for (int i = 0; i < SIZE; i++){
        if (newItem == items[i].name){
          items[i].name += newQuan;
          itemExists = true;
          cout << "Inventory updated successfully!";
          break;
        }// end of if
      }// end of for 1
      
      if (!itemExists) {
        cout << "What is the price? ";
        cin >> newPrice;
        
        int index = -1;
        for (int i = 0; i < SIZE; i++){
          if (items[i].name.length() == 0) {
            index = i;
            break;
          }// end of if
        }// end of for 2
        
        if (index != -1){
          items[index].name = newItem;
          items[index].quanity = newQuan;
          items[index].price = newPrice;   
        }// end of index if 
        cout << "Inventory updated successfully!" << endl;
      }// end of itemExists if
      
      ofstream outFile("collection.txt");
      if (!outFile) {
        cout << "Error opening file." << endl;
        return 1;
      }// end of if

      for (int i = 0; i < numItems; i++) {
        if (items[i].name.length() > 0){
          outFile << items[i].name << " " << items[i].price << " " << items[i].quanity << endl;
        }// end of if
      }// end of for
      outFile.close();
    }// end of else if 4
      
    else if (ans == 5){
      cout << "What is the name of your item? ";
      cin >> itemName;

      int index = findItem(items, numItems, itemName);
      if (index != ITEM_NOT_FOUND){
        cout << "What is the new price? ";
        cin >> newPrice;
        items[index].price = newPrice;
        cout << "Your new price has been updated!" << endl;
        cout << endl;
      }// end of if

      else
        cout << "Item does not exist." << endl;
      
    }// end of else if 5

    else if (ans == 6){
      //sell item! name of item and how many are sold. update. print error if not enough 
      string itemSold;
      int numSold;
      bool itemExists = false;
      bool enoughItems = false;
      
      cout << "What is the name of the item you want to sell? ";
      cin >> itemSold;
      
      for (int i = 0; i < SIZE; i++){
        if (itemSold == items[i].name){
          itemExists = true;
          cout << "How many were sold? ";
          cin >> numSold;
          
          if (items[i].quanity >= numSold){
            items[i].quanity -= numSold;
            enoughItems = true;
            break;
          }// end of inner if
          else {
            cout << "Insufficient quantity. ";
          }
        }// end of out if
      }// end of for
      
        if (!itemExists){
          cout << "Item does not exist." << endl;
        }// end of if

        if (enoughItems){
          cout << "Sale was successfull!" << endl;
        }// end of if
    }// end of else if 6

    else if (ans == 7){
      return 0;
    }// end of else if 7
  
    else{
      cout << "Invalid input" << endl;
    }// end of else
  }// end of while
  return 0;  
}// end of main
