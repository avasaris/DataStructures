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
* Filename : main.cc
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there 
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

#include <iostream>
#include <fstream>
#include "jug.h"

using namespace std;

int main() {

	ofstream ofs("output.dot");
    if(!ofs) {
        cout << "output.dot could not be opened." << endl;
        exit(1);
    }

	jug die_hard(3, 5, 4, 1, 1, 1, 1, 1, 1);

	int solution = die_hard.solve( ofs );

	if (solution == -1) {
		cout << "invalid entries" << endl;
	}
	else if (solution == 0) {
		cout << "couldn't find solution" << endl;
	}

	return 0;
}