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
* Filename : Graph.H
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there 
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/ 

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Vertex.H"

using namespace std;

class Graph {
	public:
		Graph();
		~Graph();
		vector< Vertex* > vertices;
		void build_graph(ifstream& ifs);
		void output_graph();
		void bfs();
		void print();
		int getLocation( string );
	private:
		int numNodes;
		int numEdges;
};

#endif