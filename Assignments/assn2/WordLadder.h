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
 * Filename : WordLadder.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

 #ifndef _WORDLADDER_H
 #define _WORDLADDER_H

 #include <iostream>
 #include <string>
 #include <list>
 //#include "MyQueue"
 //#include "MyStack"

 using namespace std;

 class WordLadder {
	public:
	 	WordLadder( const string &listFile );	// Constructor
	 	~WordLadder();
		void outputLadder( const string &start, const string &end );	// output function
		void debugger(string);
	private:
		list<string> dictionary;
 };

 #endif