// Hirna Derege
// gizmo.cpp
// This program will sell you gizmos and give you the best price

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  int gizmo, sinGizmo, eiGizmo, sixGizmo;
  double subTotal, ship, total;
  
  // ask user how many they would like
  cout << "How many gizmos do you want to purchase: ";
  cin >> gizmo;

  // will print how many packs to purchase
    sixGizmo =  gizmo / 16;
    gizmo %= 16;
    eiGizmo = gizmo / 8;
    gizmo %= 8;
    sinGizmo = gizmo;

      cout << endl;
      cout << " " <<  sixGizmo << " 16-packs\n " << eiGizmo << " 8-packs\n " << sinGizmo
       << " solo gizmo(s)"<< endl;

    //this statement will calculate subtotal and check if shipping cost applies
      subTotal = (sixGizmo * 19.19) + (eiGizmo * 9.99) + (sinGizmo * 1.29);

      if (subTotal >= 75.00)
        ship = 0.00;
      else
        ship = 5.00;

    // these line will produce a reicept of the final costs
      total = subTotal + ship;

      cout << endl;
      cout << fixed << setprecision(2);
      cout << left;
      cout << setw(10) << "Subtotal:" << "$" <<  subTotal << endl;
      cout << setw(10) << "Shipping:" << "$" << ship << endl;
      cout << setw(10) << "Total:" << "$"  << total << endl;

      
  
  return 0;

}
