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
#define MAX_QUEUE_SIZE 2500
#define debug false

using namespace std;

// Constructor
MyQueue::MyQueue() {

	head = NULL;
	rear = NULL;
	numItems = 0;
}

// Destructor
MyQueue::~MyQueue() {
	
	while(head)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

/*	Adds a new element x at the front of the queue
*/
void MyQueue::push( MyStack& newStack ) {

	Node* insert = new Node;
	insert->value = newStack;
	insert->next = NULL;

	if (size() == MAX_QUEUE_SIZE) {
 		throw overflow_error("Queue overflow");
 	}
	else if ( size() == 0 ) {
	    rear = insert;
	    head = insert;
	    numItems++;
  	}
  	else {
  		Node* temp;
		Node* last;
		for (temp=head; temp != NULL; temp=temp->next) {
			last = temp;
		}
		last->next = insert;
	    rear = insert;
	    numItems++;
  	}

}

/* 	Returns a reference to the next(head) element in the queue,
	if the queue is not already empty
*/
MyStack& MyQueue::front() {

	if (is_empty()) {
		throw underflow_error("front(): Queue is Empty");
	}
	else {
		return head->value;
	}

}

/*	Removes the element on front of the queue, reducing the 
	queue's size by 1 if the queue is not already empty.
*/
void MyQueue::pop() {

	if (is_empty()) {
		throw underflow_error("pop(): Queue is Empty");
	}
	else {
		
		Node* temp;
		temp = head;
		head = head->next;
		delete temp;
		numItems--;

	}

}

/*	tests whether the queue size is zero Primarily used to ensure 
	that a pop() or front() operation is not performed on an empty 
	instance of a queue. Returns true if queue is empty, false 
	otherwise
*/
bool MyQueue::is_empty() const {

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

	if ( size() == 0 ) {
    	throw underflow_error("print(): Queue is Empty");
  	}
  	else {
  		cout << "Queue: \n";
	  	for ( Node* temp = head; temp != NULL; temp = temp->next ) {
	    	temp->value.print();
	  	}
	}
}

void MyQueue::debugger( string message ) const {

	if (debug) {
		cout << message << endl;
	}
}