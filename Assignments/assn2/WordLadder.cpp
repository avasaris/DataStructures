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
 * Filename : WordLadder.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

 #include <iostream>
 #include <fstream>
 #include <string>
 #include <list>
 #include "MyQueue.h"
 #include "MyStack.h"
 #include "WordLadder.h"

 #define debug false

 using namespace std;

// Constructor
	WordLadder::WordLadder( const string &listFile ) {

		ifstream DictionaryFile (listFile.c_str());
		if (DictionaryFile.is_open()) {
			string line; 
			while ( getline(DictionaryFile, line) ) {
				dictionary.push_back(line);
			}
		}
		DictionaryFile.close();

	}

// Destructor
	WordLadder::~WordLadder() {	
	}

// outputLadder function 
	void WordLadder::outputLadder( const string &start, const string &end ) {

		MyStack string_stack;
		string_stack.push(start);
		MyQueue stack_queue;
		stack_queue.push(string_stack);

		int numDifferences=0;
		dictionary.remove(start);

		while (stack_queue.size() != 0) {
			for (list<string>::iterator it=dictionary.begin(); it != dictionary.end(); ++it) {
				cout << "Word: " << *it << endl;
				for (int i=0; i<5; i++) {
					string dictionary_word = *it;
					if ( dictionary_word[i] != stack_queue.top().top()[i]) {
						debugger("found a different character...");
						numDifferences++;
					}
				}
				debugger("if numDifferences == 1...");
				if (numDifferences == 1) {
					debugger("if it's the last word...");
					if (*it == end) {
						debugger("it's the last word...");
						stack_queue.top().push(*it);
						stack_queue.top().print();
						stack_queue.pop();
					}
					else {
						stack_queue.top().push(*it);
						cout << stack_queue.top().print();
						/*
						debugger("copying stack...");
						stack_queue.top().print();
						debugger("declaring new string stack...");
						MyStack new_string_stack;
						debugger("setting the new string stack equal to the old...");
						new_string_stack = stack_queue.top();
						new_string_stack.print();
						debugger("pushing the matched word...");
						new_string_stack.push(*it);
						new_string_stack.print();
						debugger("removing the world from the dictionary...");
						dictionary.remove(*it);
						debugger("pushing the new stack...");
						stack_queue.push(new_string_stack);
						cout << "Size of Queue: " << stack_queue.size() << endl;
						stack_queue.pop();
						cout << "Size of Queue: " << stack_queue.size() << endl;
						*/
					} 
				}
				numDifferences=0;
			}
		}

	}

void WordLadder::debugger( string message ) {

	if (debug) {
		cout << message << endl;
	}
} 