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
#include <string>
#include "MyQueue.h"
#include "MyStack.h"
#define MAX_QUEUE_SIZE 5
#define debug true

using namespace std;

// Constructor
MyQueue::MyQueue() {
	debugger("Queue Constructor called...");

	front = NULL;
	rear = NULL;
	numItems = 0;
}

// Destructor
MyQueue::~MyQueue() {
	debugger("Queue Destructor called...");
	
	while(front)
	{
		Node* temp = front;
		front = front->next;
		delete temp;
	}
}

/*	Adds a new element x at the top of the queue
*/
void MyQueue::push( MyStack& newStack ) {
	debugger("push function called...");

	if (size() == MAX_QUEUE_SIZE) {
 		throw overflow_error("Queue overflow");
 	}
	else if ( size() == 0 ) {
		debugger("creating new Node...");
    	Node* insert = new Node;
    	debugger("assigning the value of the new node to the passed stack...");
	    insert->value = newStack;
	    debugger("setting the next pointer to NULL...");
	    insert->next = NULL;
	    debugger("changing the rear and front pointers");
	    rear = insert;
	    front = insert;
	    numItems++;
  	}
  	else {
  		debugger("creating a new node...");
	    Node* insert = new Node;
	    debugger("assigning the value of the new node to the passed stack...");
	    insert->value = newStack;
	    debugger("setting the next pointer to NULL...");
	    insert->next = NULL;
	    rear = insert;
	    numItems++;
  	}

}

/* 	Returns a reference to the next(top) element in the queue,
	if the queue is not already empty
*/
MyStack& MyQueue::top() {
	debugger("top function called...");

	if (is_empty()) {
		//throw underflow_error("Queue is Empty");
		cout << "No top element, queue is empty..." << endl;
	}
	else {
		return front->value;
	}

}

/*	Removes the element on top of the queue, reducing the 
	queue's size by 1 if the queue is not already empty.
*/
void MyQueue::pop() {
	debugger("pop function called...");

	if (is_empty()) {
		//throw underflow_error("Queue is Empty");
		cout << "Can't pop, queue is empty..." << endl;
	}
	else {
		// find the last Node, and it's position in the Queue
	  	Node* temp;
		Node* last;
		int position = 0;
		debugger("for loop to find last node...");
		for (temp=front; temp != NULL; temp=temp->next) {
			position++;
			last = temp;
		}
		numItems--;

		// If there's only 1 element in the list the front and rear pointers need to be adjusted
		debugger("adjust front and rear pointers if only 0 element in list...");
		if ( numItems == 0) {
			debugger("changing pointers bc only 1 element in list...");
			front = NULL;
			rear = NULL;
		}
		else {	
			// Find the new rear, set it, and adjust it's next pointer to NULL
			debugger("find new rear...");
			int i=0;
			for (temp=front; temp != NULL; temp=temp->next) {
				i++;
				if (i == (position-1)) {
					debugger("rear = temp");
					rear = temp;
					debugger("temp->next = NULL");
					temp->next = NULL;
				}
			}
		}

	}

}

/*	tests whether the queue size is zero Primarily used to ensure 
	that a pop() or top() operation is not performed on an empty 
	instance of a queue. Returns true if queue is empty, false 
	otherwise
*/
bool MyQueue::is_empty() const {
	debugger("is_empty function called...");

	return (size() == 0);

}

/*	Returns how many elements are in the queue 
*/
int MyQueue::size() const {
	//debugger("size function called...");

	return numItems;

}

/* 	Prints all elements in the queue
*/
void MyQueue::print() {
	debugger("print function called...");

	if ( size() == 0 ) {
    	//throw underflow_error("Queue is Empty");
    	cout << "Queue is empty" << endl;
  	}
  	else {
  		cout << "Queue: \n";
	  	for ( Node* temp = front; temp != NULL; temp = temp->next ) {
	    	temp->value.print();
	  	}
	}
}

void MyQueue::debugger( string message ) const {

	if (debug) {
		cout << message << endl;
	}
}