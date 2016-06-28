#include "Stack.h"
#include <iostream>
#include <stdexcept>

#define CAPACITY 25

using namespace std;


// Constructor
template <typename T> 
Stack<T>::Stack() {
	t = -1;
}

// Destructor
template <typename T>
Stack<T>::~Stack() {

}

template <typename T>
void Stack<T>::push(const T& x) {

	if (size() == CAPACITY) {
 		throw overflow_error("Stack overflow");
 	}
 	else { 
 		S[++t] = x;
	}
}

template <typename T>
T& Stack<T>::top() {

	if (is_empty()) {
		throw underflow_error("Stack is Empty");
	}
	else {
		return S[t];
	}

}

template <typename T>
void Stack<T>::pop() {

	if (is_empty()) {
		throw underflow_error("Stack is Empty");
	}
	else {
	  	S[t] = 0;
	  	t--;
	}

}

template <typename T>
bool Stack<T>::is_empty() const {

	return (t<0);

}

template <typename T>
int Stack<T>::size() {

	return t+1;

}

template <typename T>
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


