/**
* Course: CS 14 Summer 2016
*
* First Name: Courtney 
* Last Name: Kelly
* Username: ckell015
* email address: ckell015@ucr.edu
*
*
* Assignment: assn4
* Filename : main.cc
*
* I hereby certify that the contents of this file represent
* my own original indiunsortedVidual work. Nowhere herein is there 
* code from any outside resources such as another indiunsortedVidual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

// Headers 
#include <iostream>
#include <string>
#include <vector>
#include <ctime>	
#include "Quicksort.H"

using namespace std;

int main() {

	srand (time(NULL));

	vector<int> unsortedV;
	unsortedV.push_back(10);
    unsortedV.push_back(6);
    unsortedV.push_back(8);
    unsortedV.push_back(4);
    unsortedV.push_back(2);
    unsortedV.push_back(12);
    unsortedV.push_back(14);

    print (unsortedV);
    string pivot = "random_qselect";
    vector<int> result = quicksort(unsortedV, pivot);
    print (result);
	return 0;
}
