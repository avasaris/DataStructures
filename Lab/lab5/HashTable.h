/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: lab5
 * Filename : HashTable.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include <vector>
#include <map>

using namespace std;

class HashTable {
	public:
		HashTable( const string &inputFile, const int mode );
		~HashTable();
		void insert( string );
		void print();
		void processFile( string filename );
		void printStats();
	private:
		int hash( string );
		int mode;
		int collisions;
		map<int, vector<string> > table;
};

#endif