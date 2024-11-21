// Hirna Derege
// mathQuiz.cpp
// oct 13,2023
// This program will simulate a math quiz asking the user how many problems
// what numbers to use and if they want to add, subtract, or multiply

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
  int digit;
  int quest;
  int method;
  int sum = 0;
  int correct = 0;
  srand(time(0));

  cout << "How many digits would you like in your problem (1-3)? ";
  cin >> digit;
  cout << endl;
  cout << "Would you like to 1. add, 2. subtract, or 3. multiply (1-3)? ";
  cin >> method;
  cout << endl;
  cout << "How many problems would you like? ";
  cin >> quest;
  cout << endl;
  
  // these loop will generate the random numbers and keep track of how many questions there are
  for (int i = 0; i < quest; i++)
    {
      int numOne = (rand() % 100);
      int numTwo = (rand() % 100);
      string symbol;

      // these lines will take the random numbers and make them 1, 2, or 3 digits long
      if (digit == 1){
        numOne = numOne % 10;
        numTwo = numTwo % 10;
      } else if (digit == 2) {
        numOne = numOne % 100;
        numTwo = numTwo % 100;
      } else if (digit == 3){
        numOne = numOne;
        numTwo = numTwo;
      }
      
      // these lines will take the user input and see which method was chosen
      if (method == 1) {
        sum = numOne + numTwo;
        symbol = "+";
      } else if (method == 2) {
        sum = numOne - numTwo;
        symbol = "-";
      } else if (method == 3) {
        sum = numOne * numTwo;
        symbol = "*";
      }

      // this line prints questions on screen/displays question for user
      cout << "Question " << i + 1 << ". " << numOne << " " << symbol << " "<< numTwo << " = ";
      int userSum;
      cin >> userSum;

      // this statement will check users answers and keep count how money they get correct
      if (userSum == sum){
        cout << "Correct!" << endl;
        correct++;
      } else {
        cout << "Incorrect, the answer is " << sum << endl;
      }
     }

     // final message printed to user
      cout << "\nYou got " << correct << " out of " << quest << " answers right!";
      cout << endl;
      cout << "Thank you, goodbye!" << endl;

      // end of program    
      return 0;


}
