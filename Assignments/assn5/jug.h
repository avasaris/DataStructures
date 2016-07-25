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
* Filename : jug.h
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there 
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

#ifndef JUG_H_
#define JUG_H_

#include <iostream>
#include <stack>
#include <utility>
#include "State.h"

using namespace std;

class Jug {
	public:
		Jug(int Ca, int Cb, int N, int fA, int fB, int eA, int eB, int pAB, int pBA);
		int solve();
	private:
		void bfs(State initial, stack <pair <State, int> >& path);
		int capacityA;
		int capacityB;
		int N;
		int fillA;
		int fillB;
		int emptyA;
		int emptyB;
		int pourAB;
		int pourBA;
};

#endif