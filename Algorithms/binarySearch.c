// Algorithm: Binary Search
// Language: C

#include <stdio.h>

int BinarySearch(int numbers[], int numbersSize, int key) {
   int mid = 0;
   int low = 0;
   int high = 0;
   
   high = numbersSize - 1;
   
   while (high >= low) {
      mid = (high + low) / 2;
      if (numbers[mid] < key) {
         low = mid + 1;
      }
      else if (numbers[mid] > key) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }
   
   return -1; // not found
}

int main(void) {
   int numbers[] = { 2, 4, 7, 10, 11, 32, 45, 87 };
   const int NUMBERS_SIZE = 8;
   int i = 0;
   int key = 0;
   int keyIndex = 0;
   
   printf("NUMBERS: ");
   for (i = 0; i < NUMBERS_SIZE; ++i) {
      printf("%d ", numbers[i]);
   }
   printf("\n");
   
   printf("Enter a value: ");
   scanf("%d", &key);
   
   keyIndex = BinarySearch(numbers, NUMBERS_SIZE, key);
   
   if (keyIndex == -1) {
      printf("%d was not found.\n", key);
   }
   else {
      printf("Found %d at index %d.\n", key, keyIndex);
   }
   
   return 0;
}