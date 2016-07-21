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
* Filename : Graph.cc
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
#include <queue>
#include <map>
#include <sstream>
#include <limits>
#include "Graph.H"
#include "Vertex.H"

#define MaxN 50
#define MaxM 200
#define INFINITY numeric_limits<int>::max()

using namespace std;

Graph::Graph() {

	numNodes=0;
	numEdges=0;

}

Graph::~Graph() {

	while (!vertices.empty()) {
		//cout << "Deleting: " << (vertices.back())->label << endl;
		delete vertices.back();
		vertices.pop_back();
	}

}

void Graph::build_graph(ifstream& ifs) {

	string line;
	string node, neighbor;
	string parameter;
	map <string, vector<string> > graphMap;

	// Read in Number of Nodes and Number of Edges
		ifs >> parameter;
		numNodes = stoi(parameter);
		ifs >> parameter;
		numEdges = stoi(parameter);

	// Read in all of the nodes and their neighbors to a map
	while( getline(ifs, line) ) {
		istringstream iss(line);
		iss >> node;
		graphMap[node].push_back("");
		while ( iss >> neighbor ) {
			graphMap[node].push_back(neighbor);
		}
	}

	// Iterate through all of the keys in the map to get each unique vertex
	for (map< string, vector<string> >::iterator it=graphMap.begin(); it != graphMap.end(); it++) {
 		Vertex* newVertex = new Vertex( it->first );
		vertices.push_back(newVertex);
 	}

 	// Extrapolate the Neighbors from the map and place them in neighbors vector of the 
 	// appropriate vertex
 	for ( vector< Vertex* >::iterator it1=vertices.begin(); it1 != vertices.end(); it1++ ) {
 		for (map< string, vector<string> >::iterator it2=graphMap.begin(); it2 != graphMap.end(); it2++ ) {			
 			if ( (it2->first) == (*it1)->label) {				
				for ( vector<string>::iterator it3=(it2->second).begin(); it3 != (it2->second).end(); it3++ ) {
					int location = getLocation(*it3);
					if (location != -1 && location != 0) {
						((*it1)->neighbors).push_back( location );
					}
				}
			}
 		}
 	}

}

int Graph::getLocation( string node ) {

	int i=0;
	for ( vector< Vertex* >::iterator iter=vertices.begin(); iter != vertices.end(); iter++ ) {
		if ( (*iter)->label == node ) {
			return i;
		}
		i++;
	}
	return -1;

}

void Graph::bfs() {

	Vertex* root = vertices[1];
	
	// Create an Empty Queue
	queue< Vertex* > Q;

	root->distance = 0;
	Q.push(root);

	while (!Q.empty()) {
		Vertex* current = Q.front();
		Q.pop();

		int numNeighbors = (current->neighbors).size();
		for (int i=0; i<numNeighbors; i++) {
			int neighbor = (current->neighbors)[i];
			if (vertices[neighbor]->distance == INFINITY) {
				vertices[neighbor]->distance = current->distance + 1;
				Q.push(vertices[neighbor]);
			}
		}
	}



}

void Graph::print() {

	cout << "Graph: " << endl;
	for ( vector<Vertex*>::iterator it=vertices.begin(); it != vertices.end(); ++it ) {
		cout << "Node: " << (*it)->label << endl;
		cout << "Distance: " << (*it)->distance << endl;
		cout << "Neighbors: " << endl;
		for ( vector<int>::iterator NB=((*it)->neighbors).begin(); NB != ((*it)->neighbors).end(); NB++ ) {
			cout << *NB << endl;
		}
	}	

}