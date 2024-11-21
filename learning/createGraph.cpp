// Hirna Derege
// oct 18, 2023
// creatGraph.cpp
// this program will diplay data, a graph, and stats from the file graph.txt

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

  ifstream inFile; // collect data from file
  string name; // will hold names of each value
  int amount; // will hold amount
  int scale; // holds the scale to which the graph will be on
  char symbol; // holds the symbol that will be displayed on the graph
  
  // open file
  inFile.open("graph.txt");
 
  if(!inFile) {
    cout << "Error: Unable to open to file" << endl;
    return 1;
  }// end of if for file failure

  if (!(inFile >> scale)) {
    cout << "Error: Invalid scale value." << endl;
    inFile.close();
    return 1;
  }// end of if for file scale failure
  
  int highestAmount = 0; // will hold the data type with the largest amount 
  int lowestAmount; // will hold the data type with the smallest amount
  string highestName; // will attach the highestAmount to its corelating name (according to the file)
  string lowestName; // will attach the lowestAmount to its corelating name(attf)
  double sum = 0.0; // will sum all of the amounts
  int count = 0; // will count the number of amounts
  
  // these line will read the file and display the graph
  cout << right << fixed;
  while (inFile >> name >> amount >> symbol){
    cout << endl;
    cout << setw(10) << name << "|";
    int numSymbol = amount / scale;
    if (amount % scale > scale / 2)
      numSymbol++;
    for (int i = 0; i < numSymbol; i++)
      cout << symbol;
   
    //these lines will read the file and see what the biggest and smallest values are
    cout << right << setw(11) << fixed;
    if (amount > highestAmount){
      highestAmount = amount;
      highestName = name;
   }else if (amount < lowestAmount){
      lowestAmount = amount;
      lowestName = name;

    }// end of else if to find biggest and smallest
  sum += amount;
  count++;
  }// end of while loop to display the graph        

   
  // closing file                                                                             
  inFile.close();  

  // these lines will produce the average                                               
  double avg = 0.0; // wil calculate the average of all values
  if (count > 0){
    avg = sum / count;
  }//end of if to calculate avg
    
  // these lines will print the bar
  cout << endl;
  cout << "+";
  for (int i = 0; i <= (highestAmount / scale); i++){
    cout << "-";
  }// end of for loop bar
  
  cout << endl;

  // these lines will display the stats
  cout << right << fixed << setprecision(1) << endl;
  cout << "Most: " << setw(10) << highestName << " (" << highestAmount << ")" << endl    
       << "Least: " << setw(10) << lowestName << " (" << lowestAmount << ")"  << endl
       << "Average: " << setw(7) << avg << endl;

    
  
  return 0;
}// end of main
