/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: assn3
 * Filename : Tree.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#ifndef __TREE_H_
#define __TREE_H_

#include <iostream>
#include <string>
#include "Node.h" 
using namespace std;

class Tree {
	public:
		Tree();
		~Tree();
		void insert( string );
		/*
		bool search( string );
		string largest();
		string smallest();
		int height();
		void remove( string );
		void preOrder();
		void inOrder();
		void postOrder(); */
		Node* getRoot();
	private:
		void addNode( string, Node* );
		void freeNode( Node* );
		Node* root;
};

#endif /* TREE_H_ */