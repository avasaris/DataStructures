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
* Filename : Mergesort.H
*
* Sources: http://www.bogotobogo.com/Algorithms/mergesort.php
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there 
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function Headers
template <typename T>
vector<T> mergesort( vector<T> );

template <typename T>
vector<T> mergesort( vector<T>, int&, int&, int& );

template <typename T>
vector<T> merge(vector<T>, vector<T>, int&, int& );

template <typename T>
void printStats(vector<T>, int&, int&, int& );

template <typename T>
void print( vector<T> );


// Function Implementations
template <typename T>
vector<T> merge(vector<T> left, vector<T> right, int& comparisions, int& dataMovements) {

	vector<T> result;
	while ( left.size() > 0 || right.size() > 0) {
		comparisions += 2;
	  	if ( left.size() > 0 &&  right.size() > 0) {
	  		comparisions+=3;
	     	if ( left.front() <= right.front() ) {
	     		dataMovements += 2;
	        	result.push_back( left.front() );
	        	left.erase( left.begin() );
	     	} 
	 		else {
	 			dataMovements += 2;
	        	result.push_back( right.front() );
	        	right.erase( right.begin() );
	     	}
	  	}  
	  	else if ( left.size() > 0 ) {
	  		comparisions += 3;
	        for (int i = 0; i < left.size(); i++) {
	        	comparisions++;
	        	dataMovements++;
	        	result.push_back(left[i]);
	        }
	        comparisions++;
	        break;
	  	}  
	  	else if ( right.size() > 0) {
	  		comparisions += 4;
	        for (int i = 0; i < right.size(); i++) {
	        	comparisions++;
	        	dataMovements++;
	           	result.push_back(right[i]);
	        }
	        comparisions++;
	        break;
	  }
	}
	comparisions++;
	return result;

}

template <typename T>
vector<T> mergesort( vector<T> v, int& comparisions, int& recursiveCalls, int& dataMovements ) {

	recursiveCalls++;

	if (v.size() <= 1) {
		return v;
	}

	vector<T> left, right, result;
	int middle = (v.size()+ 1) / 2;

	for (int i = 0; i < middle; i++) {
		dataMovements++;
		left.push_back(v[i]);
	}

	for (int i = middle; i < v.size(); i++) {
		dataMovements++;
		right.push_back(v[i]);
	}

	left = mergesort(left, comparisions, recursiveCalls, dataMovements);
	right = mergesort(right, comparisions, recursiveCalls, dataMovements);
	result = merge(left, right, comparisions, dataMovements);

	return result;

}

template <typename T>
vector<T> mergesort( vector<T> v ) {

	int comparisions = 0;
	int recursiveCalls = 0;
	int dataMovements = 0;
	vector<T> result = mergesort(v, comparisions, recursiveCalls, dataMovements);
	printStats(v, comparisions, recursiveCalls, dataMovements);

	return result;

}

template <typename T>
void printStats(vector<T> v, int& comparisions, int& recursiveCalls, int& dataMovements ) {

	cout << "Input Size: " << v.size() << endl;
	cout << "Comparisions: " << comparisions << endl;
	cout << "Data Movements: " << dataMovements << endl;
	cout << "Recursive Calls: " << recursiveCalls << endl;

}

template <typename T>
void print( vector<T> v ) {

	int length = v.size();
	for (int i=0; i<length; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

}