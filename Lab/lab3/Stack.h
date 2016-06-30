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

// Constructor
template <class T> 
Stack<T>::Stack() {
	t = -1;
}

// Destructor
template <class T>
Stack<T>::~Stack() {

}

template <class T>
void Stack<T>::push( T x) {

	if (size() == CAPACITY) {
 		throw overflow_error("Stack overflow");
 	}
 	else { 
 		S[++t] = x;
	}
}

template <class T>
T& Stack<T>::top() {

	if (is_empty()) {
		throw underflow_error("Stack is Empty");
	}
	else {
		return S[t];
	}

}

template <class T>
void Stack<T>::pop() {

	if (is_empty()) {
		throw underflow_error("Stack is Empty");
	}
	else {
	  	S[t] = 0;
	  	t--;
	}

}

template <class T>
bool Stack<T>::is_empty() const {

	return (t<0);

}

template <class T>
int Stack<T>::size() {

	return t+1;

}

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