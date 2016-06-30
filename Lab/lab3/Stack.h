/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: lab3
 * Filename : Stack.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#ifndef __STACK_H_
#define __STACK_H_

#include <iostream>
#include <stdexcept>
using namespace std;
#define CAPACITY 5

template <class T>
class Stack {
	public:
		Stack();
		~Stack();
		void push( T ); 	
		T& top(); 				
		void pop();		
		bool is_empty() const; 
		int size();
		void print();

	private:
		int t;
		T S[CAPACITY];

};

// Constructor
template <class T> 
Stack<T>::Stack() {
	t = -1;
}

// Destructor
template <class T>
Stack<T>::~Stack() {
	// No dynamic Memory allocation
	// unnecessary
}

/*	Adds a new element x at the top of the stack
*/
template <class T>
void Stack<T>::push( T x) {

	if (size() == CAPACITY) {
 		throw overflow_error("Stack overflow");
 	}
 	else { 
 		S[++t] = x;
	}
}

/* 	Returns a reference to the next(top) element in the stack,
	if the stack is not already empty
*/
template <class T>
T& Stack<T>::top() {

	if (is_empty()) {
		throw underflow_error("Stack is Empty");
	}
	else {
		return S[t];
	}

}

/*	Removes the element on top of the stack, reducing the 
	stack's size by 1 if the stack is not already empty.
*/
template <class T>
void Stack<T>::pop() {

	if (is_empty()) {
		throw underflow_error("Stack is Empty");
	}
	else {
	  	t--;
	}

}

/*	tests whether the stack size is zero Primarily used to ensure 
	that a pop() or top() operation is not performed on an empty 
	instance of a Stack. Returns true if stack is empty, false 
	otherwise
*/
template <class T>
bool Stack<T>::is_empty() const {

	return (t<0);

}

/*	Returns how many elements are in the stack 
*/
template <class T>
int Stack<T>::size() {

	return t+1;

}

/* 	Prints all elements in the stack
*/
template <class T>
void Stack<T>::print() {

	if ( size() == 0 ) {
    	throw underflow_error("Stack is Empty");
  	}
  	else {
	  	cout << "Stack: ";
	  	for (int i=0; i<size(); i++) {
	  		cout << S[i] << " ";
	  	}
	  	cout << endl;
	}
}

#endif
