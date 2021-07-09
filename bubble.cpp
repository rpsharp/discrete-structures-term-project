#include <iostream>
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
    
    int sz;
    cout<<"Enter the size of array:";
    cin>>sz;
    
    int randArray[sz];
    for(int i=0;i<sz;i++)
      randArray[i]=rand()%1000;
  
    cout << "Original Array in Random Order:\n";
    printArray(randArray, sz);
    
    bubbleSort(randArray, sz);
  
    cout << "Sorted Array in Ascending Order:\n";
    printArray(randArray, sz);
}
