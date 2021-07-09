#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

void swap(int array[], int pos1, int pos2) {
     int temp = array[pos1];
     array[pos1] = array[pos2];
     array[pos2] = temp;
}

void bubbleSort(int array[], int size){
    for (int j = size; j > 0; j--)
       for (int i = 1; i < j; i++) {
         if (array[i-1] > array[i])
             swap(array, i-1, i);
       }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
    srand( (unsigned)time( NULL ) );
    
    double running_time = 0;
    double total_time = 0;
    int sz;
    cout<<"Enter the size of array: ";
    cin>>sz;
    
    for (int j=0; j<1000; j++){
    int randArray[sz];
    for(int i=0; i<sz; i++)
      randArray[i]=rand()%(sz*100);
    
    auto start = chrono::system_clock::now();
    
        bubbleSort(randArray, sz);
        
    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;

    total_time += elapsed_seconds.count();
    }
    running_time = (total_time/1000);
    
    cout << "~~~~~~~~~~~~~~\n"
         << "Total running time: " << total_time << "s\n"
         << "Number of items sorted: " << sz << "\n"
         << "Average Running Time for Bubble Sort: " << running_time << "s\n";
}
