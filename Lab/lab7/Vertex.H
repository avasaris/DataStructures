/**
* Course: CS 14 Summer 2016
*
* First Name: Courtney 
* Last Name: Kelly
* Username: ckell015
* email address: ckell015@ucr.edu
*
*
* Assignment: lab7
* Filename : Vertex.H
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there 
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/ 

#ifndef VERTEX_H_
#define VERTEX_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class Vertex {
	public:
		Vertex();
		Vertex(string);
		~Vertex();
		string label;
		int distance;
		vector<int> neighbors;
	private:
};

#endif