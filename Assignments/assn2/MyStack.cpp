/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: assn2
 * Filename : MyStack.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <iostream>
#include <stdexcept>
#include "MyStack.h"
#define CAPACITY 5

using namespace std;

// Constructor
MyStack::MyStack() {
	t = -1;
}

// Destructor
MyStack::~MyStack() {
	// No dynamic Memory allocation
	// unnecessary
}

/*	Adds a new element x at the top of the MyStack
*/
void MyStack::push( string x ) {

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
string& MyStack::top() {

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
void MyStack::pop() {

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
bool MyStack::is_empty() const {

	return (t<0);

}

/*	Returns how many elements are in the stack 
*/
int MyStack::size() {

	return t+1;

}

/* 	Prints all elements in the stack
*/
void MyStack::print() {

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