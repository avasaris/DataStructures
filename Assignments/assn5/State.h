/**
* Course: CS 14 Summer 2016
*
* First Name: Courtney 
* Last Name: Kelly
* Username: ckell015
* email address: ckell015@ucr.edu
*
*
* Assignment: assn5
* Filename : State.h
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there 
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

#ifndef STATE_H_
#define STATE_H_

#include <iostream>
using namespace std;

class State {
	public:
		State( int a, int b) {
			jugA = a;
			jugB = b;
		}
		int jugA;
		int jugB;
		bool operator < (const State& that) const {
	        if (jugA != that.jugA) return jugA < that.jugA;
	        return jugB < that.jugB;
	    }
};

#endif