// Hirna Derege
// hw1.cpp
// 04.14.2024
// this program will display 2022 covid data


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

struct Info {
    string date, state;
    int fips, cases, deaths;
    double rate;
};

// function prototypes
void readFile(Info* [], int&);
int displayMenu();
void displayAll(Info* [], int);
int mostCases(Info* [], int);
int mostDeaths(Info* [], int);
void stateAvgs(Info* [], int);

int main(){
    int choice;
    int x = 100;  
    Info *arr[x]; 
    int count = 0;

    arr[count] = new Info; 
    readFile(arr, count);

    do{
        choice = displayMenu();
        switch(choice) {
            case 1:
            displayAll(arr, count);
            break;

            case 2:
            mostCases(arr, count);
            break;

            case 3:
            mostDeaths(arr, count);
            break;

            case 4:
            stateAvgs(arr, count);
            break;

            case 5:
            cout << "\nExiting program..." << endl;
            break;

            default:
            cout << "Invalid choice!" << endl;       
        }
    } while(choice != 5);

    return 0;
}// end of main

void readFile(Info *arr[], int &count){
    ifstream inFile;
    string fileName;

    do{
        cout << "Enter file name: "; // covid_input1 or covid_input2
        cin >> fileName;
        inFile.open(fileName);
    } while(!inFile);
    
    count = 0;
    while (getline(inFile, arr[count]->date, ',') &&
           getline(inFile, arr[count]->state, ',') &&
           (inFile >> arr[count]->fips).ignore(1, ',') &&
           (inFile >> arr[count]->cases).ignore(1, ',') &&
           (inFile >> arr[count]->deaths)) {
        count++;
        arr[count] = new Info;   // allocate memory for each Info struct
        inFile.ignore();         // ignore the newline character
    }

    inFile.close();
} // end of readFile



int displayMenu(){
    int choice;
    cout << "\n************ Menu ************" << endl;
    cout << "1. Display the COVID info of all states" << endl;
    cout << "2. Display the COVID info of the state that has the most cases" << endl;
    cout << "3. Display the COVID info of the state that has the most deaths" << endl;
    cout << "4. Display the statistics of all states" << endl;
    cout << "5. Exit the program" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
} // end of displayMenu

void displayAll(Info *arr[], int count){
    cout << endl;
    cout << setw(25) << "**States**" << setw(26) << "**Cases**" << setw(26) << "**Deaths**" << endl;
    for(int i = 0; i < count; i++){
        cout << setw(25) << arr[i]->state << " " << setw(25);
        cout << setw(25) << arr[i]->cases << " " << setw(25);
        cout << setw(25) << arr[i]->deaths << setw(25) << endl;
    }

} // end of displayAll

int mostCases(Info* arr[], int count){

    for (int i = 0; i < count - 1; i++){
        for (int j = 0; j < count - i - 1; j++){
            if(arr[j]->cases > arr[j+1]->cases){
                swap(arr[j]->cases, arr[j+1]->cases);
                swap(arr[j]->deaths, arr[j+1]->deaths);
                swap(arr[j]->state, arr[j+1]->state);
            }
        }
    }
    cout << endl;
    cout << arr[count-1]->state << " has the most cases: " << arr[count-1]->cases << endl;
    return count;
} // end of mostCases
    
int mostDeaths(Info* arr[], int count){

    // bubble sorting 
    for (int i = 0; i < count - 1; i++){
        for (int j = 0; j < count - i - 1; j++){
            if(arr[j]->deaths > arr[j+1]->deaths){
                swap(arr[j]->cases, arr[j+1]->cases);
                swap(arr[j]->deaths, arr[j+1]->deaths);
                swap(arr[j]->state, arr[j+1]->state);
            }
        }
    }
    cout << endl;
    cout << arr[count-1]->state << " has the most deaths: " << arr[count-1]->deaths << endl;
    return count;
} // end of mostDeaths

void stateAvgs(Info* arr[], int count){

    //total cases... avg per state
    int totalCases = 0;
    for (int i = 0; i < count; i++)
        totalCases += arr[i]->cases;
    int avgCases = 0;
    avgCases = totalCases/count;

    cout << endl;
    cout << "(a)  There are " << totalCases << " cases in total, " << avgCases << " on average." << endl;

    // total death... avg per state
    int totalDeaths = 0;
    for (int i = 0; i < count; i++)
        totalDeaths += arr[i]->deaths;
    int avgDeaths = 0;
    avgDeaths = totalDeaths/count;

    cout << "(b)  There are " << totalDeaths << " deaths in total, " << avgDeaths << " on average." << endl;

    // death rate for all states(death/cases * 100)
    double deathRate = 0.0;
    deathRate = static_cast<double>(totalDeaths) / totalCases * 100;

    cout << "(c)  The average death rate for all states is " << setprecision(3) << deathRate << "%" << endl;

    // of all states >100 cases, higheset death rate
    
    double highRate = 0.0;
    string highState;
    for(int i = 0; i < count; i++){
        if (arr[i]->cases > 100){
            arr[i]->rate = static_cast<double>(arr[i]->deaths) / arr[i]->cases * 100;
            if (arr[i]->rate > highRate) {
                highRate = arr[i]->rate;
                highState = arr[i]->state;
            }
        }
    }

    cout << "(d)  Among all states that have more than 100 cases, " << highState 
         << " has the highest death rate of " << setprecision(3) << highRate << "%" << endl;

} // end of stateAvgs