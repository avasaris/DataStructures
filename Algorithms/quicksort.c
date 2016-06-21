// Algorithm: Quicksort
// Language: C

#include <stdbool.h>
#include <stdio.h>

int Partition(int numbers[], int i, int k) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   /* Pick middle element as pivot */
   midpoint = i + (k - i) / 2;
   pivot = numbers[midpoint];
   
   l = i;
   h = k;
   
   while (!done) {
      
      /* Increment l while numbers[l] < pivot */
      while (numbers[l] < pivot) {
         ++l;
      }
      
      /* Decrement h while pivot < numbers[h] */
      while (pivot < numbers[h]) {
         --h;
      }
      
      /* If there are zero or one elements remaining,
       all numbers are partitioned. Return h */
      if (l >= h) {
         done = true;
      }
      else {
         /* Swap numbers[l] and numbers[h],
          update l and h */
         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;
         
         ++l;
         --h;
      }
   }
   
   return h;
}

void Quicksort(int numbers[], int i, int k) {
   int j = 0;
   
   /* Base case: If there are 1 or zero elements to sort,
    partition is already sorted */
   if (i >= k) {
      return;
   }
   
   /* Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
   j = Partition(numbers, i, k);
   
   /* Recursively sort low partition (i to j) and
    high partition (j + 1 to k) */
   Quicksort(numbers, i, j);
   Quicksort(numbers, j + 1, k);
   
   return;
}

int main(void) {
   int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
   const int NUMBERS_SIZE = 8;
   int i = 0;
   
   printf("UNSORTED: ");
   for(i = 0; i < NUMBERS_SIZE; ++i) {
      printf("%d ", numbers[i]);
   }
   printf("\n");
   
   /* Initial call to quicksort */
   Quicksort(numbers, 0, NUMBERS_SIZE - 1);
   
   printf("SORTED: ");
   for(i = 0; i < NUMBERS_SIZE; ++i) {
      printf("%d ", numbers[i]);
   }
   printf("\n");
   
   return 0;
}