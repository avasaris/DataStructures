// Example of using Linear Search
// Language: C

#include <stdio.h>
#include <stdbool.h>

int LinearSearch(int numbers[], int numbersSize, int key) {
   int i = 0;
   
   for (i = 0; i < numbersSize; ++i) {
      if (numbers[i] == key) {
         return i;
      }
   }
   
   return -1; /* not found */
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
   
   printf("\nEnter a value: ");
   scanf("%d", &key);
   
   keyIndex = LinearSearch(numbers, NUMBERS_SIZE, key);
   
   if (keyIndex == -1) {
      printf("%d was not found.\n", key);
   }
   else {
      printf("Found %d at index %d.\n", key, keyIndex);
   }
   
   return 0;
}