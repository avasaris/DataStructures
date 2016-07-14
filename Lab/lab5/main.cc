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
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

 #include <iostream>
 #include <cstdlib>
 #include <string>
 #include "HashTable.h"

 using namespace std;

 int main( int argc, char* argv[] ) {

 	if ( argc != 3 ) {
 		cerr << "Usage: <executable> <input filename> <hash table mode>\n"
 		"  Hash Table Modes:\n"
 		"   1: adds up the ASCII values of the characters in the key\n"
 		"   2: adds up the ASCII values of the characters in the key:\n" 
 		"      The value for a key k is calculated as:\n" 
 		"      k[0] + 27 * k[1] + 729 * k[2]\n"
 		"   3: uses all characters in the key and calculates\n" 
 		"      SUM i=0,...,keysize-1 k[keysize - i - 1] * 37 i" << endl;
 		exit(1);
 	}

 	string inputFile = argv[1];
 	int mode = atoi(argv[2]);

 	HashTable hash1(inputFile, mode);
 	hash1.print();
 	hash1.printStats();

 	cout << "Processing dict5.txt..." << endl;
 	hash1.processFile("dict5.txt");
 	hash1.printStats();

 	cout << "Processing dict7.txt..." << endl;
 	hash1.processFile("dict7.txt");
 	hash1.printStats();

 	return 0;
 }