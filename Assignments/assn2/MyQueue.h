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
 * Filename : MyQueue.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#ifndef __MyQueue_H_
#define __MyQueue_H_

#include <iostream>
#include <stdexcept>
#include "Node.h"
#define MAX_QUEUE_SIZE 5

using namespace std;

class MyQueue {
	public:
		MyQueue();
		~MyQueue();
		void push( string ); 	
		string& front(); 				
		void pop();		
		bool is_empty() const; 
		int size();
		void print();

	private:
		Node* front;
		Node* rear;
		int numItems;

};

#endif