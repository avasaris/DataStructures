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
#include "WordLadder.h"

using namespace std;

int main( int argc, char * argv[] ) {

	
	if ( argc != 4 ) {
		cout << "usage: ./a.out <dictionary.dict> <start word> <end word>" << endl;
	}
	else {

		WordLadder WordLadder1(argv[1]);
		WordLadder1.outputLadder( argv[2], argv[3] );
	} 

	return 0;
}