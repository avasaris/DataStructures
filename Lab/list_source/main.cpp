/**
 * UCR CS&E
 * CS014 Lab 1
 * main.cpp
 */

#include <iostream>
#include "List.h"
#include "Iterator.h"
#include "Node.h"

#define fibo_number 11

int fibonacci(int n);

using namespace std;

int main()
{
	
	/* Instantiate two Lists */
	/*List myList;
	List myList2;
	*/
	/* Try to print an empty List */
	/*cout << "\nTest printing an empty list:";
	myList.print();
	
	cout << "\nPushing back first " << fibo_number << " Fibonacci numbers:";
	for(int i = 0; i < fibo_number; i++)
	{
		myList.push_back(fibonacci(i));
		myList.print();
	}
	
	cout << "\nReverse myList pushing front contents of myList into myList2:";
	for(Iterator iter = myList.begin(); !iter.is_equal(myList.end()); iter.next_pos())
	{
		myList2.push_front(iter.get_value());
		myList2.print();
	}
	
	*/	
	
	List myList3;
	List myList4;
	
	cout << "myList3: ";
	myList3.print();
	cout << endl;
	
	cout << "myList4: ";
	myList4.print();
	cout << endl;
	
	myList3.sorted_insert(8);
	myList3.sorted_insert(6);
	myList3.sorted_insert(7);
	myList3.sorted_insert(5);
	myList3.sorted_insert(3);
	myList3.sorted_insert(0);
	myList3.sorted_insert(9);
	
	myList4.push_back(6);
	myList4.push_back(7);
	myList4.push_back(5);
	myList4.push_back(3);
	myList4.push_back(0);
	myList4.push_back(9);
	myList4.push_front(8);
	
	cout << "myList3: ";
	myList3.print();
	cout << endl;
	
	cout << "myList4: ";
	myList4.print();
	cout << endl;
	
	cout << "myList3 reversed: ";
	myList3.print_reverse();
	cout << endl;
	
	cout << "myList4 reversed: ";
	myList4.print_reverse();
	cout << endl;
	
	cout << "myList4 8 count: " << myList4.count(8) << endl;
	cout << "myList4 9 count: " << myList4.count(9) << endl;
	
	myList4.insertAfter(3,11);
	myList4.insertAfter(3,8);
	myList4.insertAfter(100,999);
	myList4.insertAfter(-5,9);
	
	myList4.insertBefore(3,42);
	myList4.insertBefore(9, 8);
	myList4.insertBefore(100, 8);
	myList4.insertBefore(-2,0);
	
	cout << "myList4 8 count: " << myList4.count(8) << endl;
	cout << "myList4 9 count: " << myList4.count(9) << endl;
	cout << "myList4 888 count: " << myList4.count(888) << endl;
	
	cout << "myList4: ";
	myList4.print();
	cout << endl;
		
	cout << "myList4 reversed: ";
	myList4.print_reverse();
	cout << endl;
		
	return 0;
}

/**
 * Local Fibonacci function for filling and testing Lists 
 * @param n the Fibonacci number to calculate
 * @return fibonacci(n)
 */
int fibonacci(int n)
{
	if((n == 0) | (n == 1))
	{
		return n;
	}
	else
	{
		return fibonacci(n-2) + fibonacci(n-1);
	}
}