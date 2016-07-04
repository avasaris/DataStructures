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
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <iostream>
#include <string>
#include "MyStack.h"
#include "MyQueue.h"
#include "WordLadder.h"

using namespace std;

int main( int argc, char * argv[] ) {

	
	if ( argc != 4 ) {
		cout << "usage: ./a.out <dictionary.dict> <start word> <end word>" << endl;
	}
	else {

		WordLadder WordLadder1(argv[1]);

		if ( ( strlen(argv[2])==5) && ( strlen(argv[3])==5) ) {
			WordLadder1.outputLadder( argv[2], argv[3] );
		}
		else {
			cout << "Both the start and end word need to be of length 5!" << endl;
		}
	} 

	return 0;
}