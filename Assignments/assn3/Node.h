/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: assn3
 * Filename : Node.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#ifndef __NODE_H_
#define __NODE_H_

#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
		Node( string );
		Node* left;
	  	Node* right;
	  	string value;
	  	int count;
};

#endif /* NODE_H_ */