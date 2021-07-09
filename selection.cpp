#include <iostream>
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
    
    int sz;
    cout<<"Enter the size of array:";
    cin>>sz;
    
    int randArray[sz];
    for(int i=0;i<sz;i++)
      randArray[i]=rand()%1000;
  
    cout << "Original Array in Random Order:\n";
    printArray(randArray, sz);
    
    selectionSort(randArray, sz);
  
    cout << "Sorted Array in Ascending Order:\n";
    printArray(randArray, sz);
}
