#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int sing1(int* a , int n){
    for(int i = 0; i < n;  i++){
        int f = 0;
        for(int j = 0; j < n; j++){
            if(i != j && a[i] == a[j]){
                f = 1;
                break;
            }
        }
        if(f == 0)
            return a[i];
    }
    return -1;
} // end of sing

int sing2(int* a, int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        s = s^a[i];
    }
    return s;
} // end of sing2

int main(){
    int k[] = {100, 1000, 2000, 5000};
    
    cout << setw(5) << "\nk value" << setw(20) << "iteration" << setw(20) << "sing1 time" << setw(20) << "sing2 time" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
    double sum1 = 0, sum2 = 0;
    for(int i = 0; i < 4; i++){
        int* a = new int[2*k[i] + 1];
        int n = 2*k[i];
      
        for(int j = 0; j < k[i]; j++){
            a[j] = j;
            a[j + k[i]] = j;
        }
        
        a[n] = n;

        for(int h = 1; h <= 3; h++){
            clock_t begin = clock();
            sing1(a, n+1);
            clock_t end = clock();
            double sing1Time = end - begin;
            sum1 += sing1Time;

            clock_t begin2 = clock();
            sing2(a, n+1);
            clock_t end2 = clock();
            double sing2Time = end2 - begin2;
            sum2 += sing2Time;

            cout << right;
            cout << setw(7) << k[i] << setw(20) << h << setw(20) << sing1Time << setw(20) << end2-begin2 << endl;
        }
        delete[] a;
    }
    cout << "\naverages: " << sum1/3 << " " << sum2/3 << endl;  //avg for each num

    return 0;
} // end of main

