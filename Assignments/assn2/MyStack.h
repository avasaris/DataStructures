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
 * Filename : MyStack.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#ifndef __MyStack_H_
#define __MyStack_H_

#include <iostream>
#include <stdexcept>
#include <string> 
#define CAPACITY 2500

using namespace std;

class MyStack {
	public:
		MyStack();
		~MyStack();
		void push( string ); 	
		string& top(); 				
		void pop();		
		bool is_empty() const; 
		int size() const;
		void print();		
		string& operator[](const int i);
		void debugger( string );
	private:
		int t;
		string S[CAPACITY];

};

#endif
