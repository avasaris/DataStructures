#ifndef __STACK_H_
#define __STACK_H_

#include <iostream>
#include <stdexcept>
using namespace std;
#define CAPACITY 25

template <class T>
class Stack {
	public:
		Stack();
		~Stack();
		void push( T ); 	// adds a new element x at the top of the stack.

		T& top(); 				// Returns a reference to the next(top) element in the stack,
									// if the stack is not already empty.

		void pop();					// Removes the element on top of the stack, reducing the 
									// stack's size by 1 if the stack is not already empty.

		bool is_empty() const; 		// tests whether the stack size is zero Primarily used to ensure 
									// that a pop() or top() operation is not performed on an empty 
									// instance of a Stack. Returns true if stack is empty, false 
									// otherwise

		int size();
		void print();

	private:
		int t;
		T S[CAPACITY];

};

#include "Stack.tpp"

#endif
