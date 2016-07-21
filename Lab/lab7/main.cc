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
 * Filename : main.cc
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
 #include "Graph.H"
 #include "Vertex.H"

 using namespace std;

 int main() {

 	Graph g1;

 	ifstream InFile("input.txt");
 	g1.build_graph(InFile);
 	g1.bfs();
 	//g1.print();

 	ofstream ofs("output.dot");
    if(!ofs) {
        cout << "output.dot could not be opened." << endl;
        exit(1);
    }

    ofs << "// Digraph \n// lab 7 \n// output.dot \n// cs014_16sum1\n//" << endl << endl;
    ofs << "digraph G {\n\n//nodes" << endl;

    //vector<Vertex*>::iterator it=g1.vertices.begin();
    //it++;

   // while (it != g1.vertices.end()) {
   	int length = g1.vertices.size();

    for (int i=1; i<length; i++) {
    	ofs << i <<  " [color = orange, peripheries=2, style = filled, label=\"key=" << (g1.vertices[i])->label;
    	ofs << ", distance=" << (g1.vertices[i])->distance << "\"];" << endl;

    	int numNeighbors = ((g1.vertices[i])->neighbors).size();
    	for (int j=0; j<numNeighbors; j++) {
    		ofs << i << " -> " << ((g1.vertices[i])->neighbors)[j] << endl;
    	}

    }

    ofs << endl << "}" << endl;

 	return 0;
 } 