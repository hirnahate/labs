// hirna derege
// nov 13, 2023
// assignment 4
// this program will create word guessing game(similar to hangman)
// input: the user will enter their guess, a single character
// output: number of misses, correct guesses (displayed in mystery word) 

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int readWordFile(string fileName, string wordList[]);
// this function will read the file with the name fileName
// and place each word that has been read into wordList[]
// pre: file must exist, each word msut have 8-letters
string pickMysteryWord(string wordList[], int numWords);
// this function selects a word from wordList and returns it
// numWords is the number of words in wordList
// pre: numWords must be greater than zero
int playGame(string mystery);
// this function will run the game with a word from mystery and returns misses
// pre: mystery must contain a word
char getGuess();
// this function will collect the guess from the user and return it
// pre: guess must be a single character and and lowercase letter
void compareBestScore(int totalScore, int &bestScore);
// this function will compare the final total score to the best score
// pre: bestScore must be initalized to a number greater that the first totalScore

int main(){
  const int maxWords = 1000;                            // most amount of words allowed
  string wordList[maxWords];                            // array that holds words
  int numWords = readWordFile("words.txt", wordList);   // holds how many words are in array

  int bestScore = maxWords;  // makes sure first run of total score is less than bestScore
  char playAgain = 'y';      // does user want to pkay again?
  
  while (playAgain == 'y' || playAgain == 'Y'){
    string mysteryWord = pickMysteryWord(wordList, numWords);  // randomly selects a word from the list retturns it
    int totalScore = playGame(mysteryWord);                    // totals scores in game
    compareBestScore(totalScore, bestScore);

    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
  }// end of while

  cout << "Thank you for playing the word playing game! Goodbye!" << endl;
  return 0;
}// end of main

int readWordFile(string fileName, string wordList[]){
  ifstream inFile(fileName);  // read file as fileName
  const int MAX = 1000;       // most numWords can be
  int numWords = 0;           // number of words in wordList

  while (numWords < MAX && inFile >> wordList[numWords]){
    if (wordList[numWords].length() == 8){
      numWords++;
    }// end of if one
   }// end of while

  inFile.close();
  return numWords;
}// end of readWordFile

string pickMysteryWord(string wordList[], int numWords){
  srand(time(0));
  
  int index;   // number randomly selected from numWords
  index = rand() % numWords;

  return wordList[index];
}// end of pickMysteryWord

int playGame(string mystery){
  int misses = 0;                               // number of wrong guesses
  string guessedWord(mystery.length(), '-');    // string mystery hidden by dashes

  cout << "\nWELCOME! Guess the mystery word" << endl;

  // while the mystery word hasnt been guesssed display state of word and number of misses
  while (guessedWord != mystery) {
    cout << "Word: " << guessedWord;
    cout << " Misses: " << misses << endl;
      
    char guess = getGuess();  // char guess gets called back to getGuess();
    bool correct = false;     // checks if guess is right or wrong

    // if guess is correct then reveal where it is in mystery
    for (int i = 0; i < static_cast<int>(mystery.length()); i++){
      if (mystery[i] == guess){
        correct = true;
        guessedWord[i] = guess;
      }// end of if
    }// end of for

    // if guess is wrong add to misses and let user know
    if (!correct) {
      misses++;
      cout << "MISS! The letter " << guess << " is not in the word." << endl;
    }// end of if

    // if guess is correct then let user know
    else {
      cout << "The letter " << guess << " is in the word!" << endl;
    }// end of else
    
    cout << endl;
  }// end of while
  
  // display final stats
  cout << "Congrats!! You have completed the word!" << endl
       << "The word is " << mystery << endl << "You had " << misses
       << " misses." << endl;
  
  return misses;
}// end of playGames

char getGuess(){
  char guess;                 // single character that will hold user input
  bool guessIsLower = false;  // makes sure the users guess is a lowercase letter

  // if guess meets preconditions continue 
  while(!guessIsLower){
    cout << "enter a guess(one lowercase letter): ";
    cin >> guess;

    // if guess does not meet preconditions then ask user to try again
    if (islower(guess)) {
      guessIsLower = true;
    } else {
      cout << "invaild guess. enter a letter from a - z: " << endl;
    }
  }// end of while
      
    return guess;
}// end of getGuess

void compareBestScore(int totalScore, int &bestScore){
  // calculates and compares the best score and prints messages for each situation
  if (totalScore < bestScore){
     cout << "you beat the best score!" << endl;
     bestScore = totalScore;
  } else if (totalScore == bestScore) {
     cout << "you matched the best score with " << bestScore << " misses." << endl;
  } else {
     cout << "The best score is " << bestScore << " misses." << endl;
  }
    
}// end of compareBestScore
