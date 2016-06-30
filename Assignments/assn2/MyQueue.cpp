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
 * Filename : MyQueue.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <iostream>
#include <stdexcept>
#include "MyQueue.h"
#define MAX_QUEUE_SIZE 5

using namespace std;

// Constructor
MyQueue::MyQueue() {
	front = NULL;
	rear = NULL;
	numItems = 0;
}

// Destructor
MyQueue::~MyQueue() {
	// No dynamic Memory allocation
	// unnecessary
}

/*	Adds a new element x at the top of the queue
*/
void MyQueue::push( string x ) {

	if (size == N) {
 		throw overflow_error("Queue overflow");
 	}
	else if ( size == 0 ) {
    	Node* insert = new Node;
	    insert->value = value;
	    insert->next = NULL;
	    rear->next = insert;
	    rear = insert;
	    front = insert;
	    numItems++;
  	}
  	else {
	    Node* insert = new Node;
	    insert->value = value;
	    insert->next = NULL;
	    rear->next = insert;
	    rear = insert;
	    numItems++;
  	}

}

/* 	Returns a reference to the next(top) element in the queue,
	if the queue is not already empty
*/
string& MyQueue::front() {

	if (is_empty()) {
		throw underflow_error("Queue is Empty");
	}
	else {
		return front->value;
	}

}

/*	Removes the element on top of the queue, reducing the 
	queue's size by 1 if the queue is not already empty.
*/
void MyQueue::pop() {

	if (is_empty()) {
		throw underflow_error("Queue is Empty");
	}
	else {
	  	delete rear;
	  	Node* temp;
	  	for (temp=front; temp != NULL; temp=temp->next) {
	  		rear = temp;
	  	}
	}

}

/*	tests whether the queue size is zero Primarily used to ensure 
	that a pop() or top() operation is not performed on an empty 
	instance of a queue. Returns true if queue is empty, false 
	otherwise
*/
bool MyQueue::is_empty() const {

	return (size == 0);

}

/*	Returns how many elements are in the queue 
*/
int MyQueue::size() {

	return size;

}

/* 	Prints all elements in the queue
*/
void MyQueue::print() {

	if ( size == 0 ) {
    	throw underflow_error("Queue is Empty");
  	}
  	else {
	  	cout << "Queue: ";
	  	for (int i=0; i<size; i++) {
	  		cout << Q[i] << " ";
	  	}
	  	cout << endl;
	}
}