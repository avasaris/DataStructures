#include "Stack.h"
#include <iostream>
#include <stdexcept>

#define CAPACITY 25

using namespace std;


// Constructor 
Stack::Stack() {

	t = -1;

}

// Destructor
Stack::~Stack() {

}

void Stack::push(const int& x) {
	size() == CAPACITY ? throw overflow_error("stack overflow") : S[++t] = x;
	
}

int& Stack::top() {

	if (is_empty()) {
		throw underflow_error("Stack is Empty");
	}
	else {
		return S[t];
	}

}

void Stack::pop() {

	if (is_empty()) {
		throw underflow_error("Stack is Empty");
	}
	else {
	  	S[t] = 0;
	  	t--;
	}

}

bool Stack::is_empty() const {

	return (t<0);

}

int Stack::size() {

	return t+1;

}

void Stack::print() {

	if ( size() == 0 ) {
    	throw underflow_error("Stack is Empty");
  	}

  	cout << "Stack: ";
  	for (int i=0; i<size(); i++) {
  		cout << S[i] << " ";
  	}
  	cout << endl;
}


