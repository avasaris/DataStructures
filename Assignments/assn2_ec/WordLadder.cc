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
 #include <cstring>
 #include <string>
 #include <list>
 #include <stack>
 #include <queue>
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

		stack<string> string_stack;
		string_stack.push(start);
		queue< stack<string> > stack_queue, solutions;
		stack_queue.push(string_stack);
		dumpList.push_back(start);

		while ( !stack_queue.empty() ) {
			for (list<string>::iterator it=dictionary.begin(); it != dictionary.end(); it++) {
				if ( neighbors(*it, stack_queue.front().top()) && !in_dumpList(*it) ) {
					if (*it == end) {
						stack_queue.front().push(*it);
						solutions.push(stack_queue.front());
					}
					else {
						stack<string> new_string_stack;
						for (int i=0; i<(stack_queue.front().size()); i++) {
							new_string_stack.push( stack_queue.front().top() );
							stack_queue.front().pop();
						}
						/*
						new_string_stack = stack_queue.front();
						cout << "Stack to copy: " << endl;
						print(stack_queue.front());
						cout << "Stack after assignment: " << endl;
						print(new_string_stack); */
						cout << "Stack before push: " << endl;
						print(new_string_stack);
						new_string_stack.push(*it);
						cout << "Stack after push: " << *it << endl;
						print(new_string_stack);
						stack_queue.push(new_string_stack);
						dumpList.push_back(*it);
					} 
				}
			}
			stack_queue.pop();
		}

/*
		cout << "Solutions: " << endl;
		for (int i=0; i<solutions.size(); i++) {
			stack<string> solution_stack = solutions.front();
			solutions.pop();
			cout << "\nStack: " << endl;
			for (int j=0; j<solution_stack.size(); j++) {
				cout << solution_stack.top() << endl;
				solution_stack.pop();
			}
        }
*/
	}

bool WordLadder::neighbors( string& dictionary_word, string& top_word ) {

	int numDifferences=0;
	int length = dictionary_word.size();
	for ( int i=0; i<length; i++ ) {
		if ( dictionary_word[i] != top_word[i] ) {
			numDifferences++;
		}
	}

	return (numDifferences==1);

}

bool WordLadder::in_dumpList( string& dictionary_word ) {

	list<string>::iterator iter = find(dumpList.begin(), dumpList.end(), dictionary_word);
	return ( iter != dumpList.end() );

}

void WordLadder::print( stack<string> S ) {

	for (int j=0; j<S.size(); j++) {
		cout << S.top() << endl;
		S.pop();
	}

}

void WordLadder::debugger( string message ) {

	if (debug) {
		cout << message << endl;
	}
} 