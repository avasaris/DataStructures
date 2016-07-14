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
 * Filename : OpenAddressCollisionTests.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

 #include <iostream>
 #include <cstdlib>
 #include <cmath>
 #include <vector>
 #include <string>

 using namespace std;

 const int SIZE = 9001;
 const int MAX = 6500;

 int main() {

 	vector<int> linear(SIZE, -1);
 	vector<int> quadratic(SIZE, -1);
 	vector<int> cubic(SIZE, -1);

 	int linearCollisions = 0;
 	int quadraticCollisions = 0;
 	int cubicCollisions = 0;

 	srand(0);
 	for (int i=0; i<MAX; i++) {
 		int hashCode = rand() % SIZE;
 		int offset = 0;
 		while (linear[hashCode] == 1) {
 			++linearCollisions;
 			++offset;
 			hashCode += offset;
 			hashCode %= SIZE;
 		}
 		linear[hashCode] = 1;
 	}
 	cout << "Linear Collisions: " << linearCollisions << endl;

 	for (int i=0; i<MAX; i++) {
 		int hashCode = rand() % SIZE;
 		int offset = 0;
 		while (quadratic[hashCode] == 1) {
 			++quadraticCollisions;
 			++offset;
 			hashCode += pow(offset,2);
 			hashCode %= SIZE;
 		}
 		quadratic[hashCode] = 1;
 	}
 	cout << "Quadratic Collisions: " << quadraticCollisions << endl;

	for (int i=0; i<MAX; i++) {
 		int hashCode = rand() % SIZE;
 		int offset = 0;
 		while (cubic[hashCode] == 1) {
 			++cubicCollisions;
 			++offset;
 			hashCode += pow(offset,3);
 			hashCode %= SIZE;
 		}
 		cubic[hashCode] = 1;
 	}
 	cout << "Cubic Collisions: " << cubicCollisions << endl; 	

 	return 0;
 } 