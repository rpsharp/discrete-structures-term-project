#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int iMin = step;
    for (int i = step + 1; i < size; i++) {

      if (array[i] < array[iMin])
        iMin = i;
    }

    swap(&array[iMin], &array[step]);
  }
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
    
        selectionSort(randArray, sz);
        
    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;

    total_time += elapsed_seconds.count();
    }
    running_time = (total_time/1000);
    
    cout << "~~~~~~~~~~~~~~\n"
         << "Total running time: " << total_time << "s\n"
         << "Number of items sorted: " << sz << "\n"
         << "Average Running Time for Selection Sort: " << running_time << "s\n";
}
