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
 * Filename : HashTable.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

 #include <iostream>
 #include <fstream>
 #include <cstdlib>
 #include <cmath>
 #include <stdexcept>
 #include <string>
 #include <vector>
 #include <map>
 #include "HashTable.h"

 using namespace std;

 // Constructor 
 HashTable::HashTable( const string &inputFile, const int m ) {

 	mode = m;
 	collisions = 0;

 	ifstream InputFile (inputFile.c_str());
 	if ( InputFile.is_open() ){
 		string line;
 		while ( getline(InputFile, line) ) {
 			insert(line);
 		}
 	}
 	InputFile.close();

 }

 HashTable::~HashTable() {}

 int HashTable::hash( string item ) {

 	int sum = 0;
 	int length = item.length();
 	if (mode==1) {
 		for (int i=0; i<length; i++) {
 			sum += (int) (item[i]);
 		}
 	}
 	else if (mode==2) {
 		int a = (int) item[0];
 		int b = (int) item[1];
 		int c = (int) item[2];
 		sum = a + 27 * b + 729 * c;

 	}
 	else if (mode==3) {
 		for (int i=0; i<length; i++) {
 			sum += item[length-i-1]*pow(37,i);
 		}

 	}
 	else if (mode==4) {
 		sum = (int) item[0];
 	}
 	else {
 		throw invalid_argument("The mode you entered is invalid!");
 	}

 	return sum;

 }

 void HashTable::insert( string item ) {

 	int index = hash(item);
 	table[index].push_back(item);
 	if (table[index].size() > 1) collisions++;
 
 }

 void HashTable::print() {

 	cout << "Hash Table:" << endl;
 	for (map< int, vector<string> >::iterator it=table.begin(); it != table.end(); it++) {
 		cout << it->first << ": ";
 		for ( vector<string>::iterator iter=(it->second.begin()); iter != (it->second.end()); iter++ ) {
 			cout << *iter << ", ";
 		}
 		cout << endl;
 	}
 	cout << endl;

 }

 void HashTable::processFile( string file ) {

 	ifstream InputFile (file.c_str());
 	if ( InputFile.is_open() ){
 		string line;
 		while ( getline(InputFile, line) ) {
 			insert(line);
 		}
 	}
 	InputFile.close();

 }

 void HashTable::printStats() {

 	cout << "Hash Table Stats:" << endl;
 	cout << "  Number of Collisions: " << collisions << endl;

 	double max=0, location=0, sum=0;

 	for (map< int, vector<string> >::iterator it=table.begin(); it != table.end(); it++) {
 		sum += it->second.size();
 		double size = it->second.size();
 		if (size > max ) {
 			max = it->second.size();
 			location = it->first;
 		}
 	}

 	cout << "  Longest list occurs at: " << location << ", with a length of: " << max << " items" << endl;
 	cout << "  Average length of all the lists: " << sum/table.size() << endl << endl;;

 }

 