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
* Filename : Vertex.cc
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there 
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/ 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include "Vertex.H"

#define MaxN 50
#define MaxM 200

using namespace std;

Vertex::Vertex() {

	label = "";
	distance = numeric_limits<int>::max();

}

Vertex::Vertex( string l ) {

	label = l;
	distance = numeric_limits<int>::max();

}

Vertex::~Vertex() {}