// Algorithm: Binary Search
// Language: Java

import java.util.Scanner;

public class BinarySearch {
   public static int binarySearch(int numbers [], int numbersSize, int key) {
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

   public static void main(String [] args) {
      Scanner scnr = new Scanner(System.in);

      int numbers [] = {2, 4, 7, 10, 11, 32, 45, 87};
      final int NUMBERS_SIZE = 8;
      int i = 0;
      int key = 0;
      int keyIndex = 0;

      System.out.print("NUMBERS: ");
      for (i = 0; i < NUMBERS_SIZE; ++i) {
         System.out.print(numbers[i] + " ");
      }
      System.out.println();

      System.out.print("Enter a value: ");
      key = scnr.nextInt();

      keyIndex = binarySearch(numbers, NUMBERS_SIZE, key);

      if (keyIndex == -1) {
         System.out.println(key + " was not found.");
      } 
      else {
         System.out.println("Found " + key + " at index " + keyIndex + ".");
      }

      return;
   }
}