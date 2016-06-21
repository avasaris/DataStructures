// Algorithm: Selection Sort
// Language: C++

#include <iostream>
using namespace std;

void SelectionSort(int numbers[], int numbersSize) {
   int i = 0;
   int j = 0;
   int indexSmallest = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 0; i < numbersSize; ++i) {
      
      // Find index of smallest remaining element
      indexSmallest = i;
      for (j = i + 1; j < numbersSize; ++j) {
         
         if ( numbers[j] < numbers[indexSmallest] ) {
            indexSmallest = j;
         }
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      temp = numbers[i];
      numbers[i] = numbers[indexSmallest];
      numbers[indexSmallest] = temp;
   }
}

int main() {
   int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
   const int NUMBERS_SIZE = 8;
   int i = 0;
   
   cout << "UNSORTED: ";
   for (i = 0; i < NUMBERS_SIZE; ++i) {
      cout << numbers[i] << ' ';
   }
   cout << endl;
   
   SelectionSort(numbers, NUMBERS_SIZE);
   
   cout << "SORTED: ";
   for (i = 0; i < NUMBERS_SIZE; ++i) {
      cout << numbers[i] << ' ';
   }
   cout << endl;
   
   return 0;
}