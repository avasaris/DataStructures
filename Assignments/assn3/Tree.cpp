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
 * Filename : Tree.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <iostream>
#include <string>
#include "Tree.h"
#include "Node.h"

using namespace std;

 // Constructor
 Tree::Tree() {

 	root = NULL;

 }

 // Destructor
 Tree::~Tree() {

 	cout << "Destructor called..." << endl;
 	freeNode( getRoot() );

 }

void Tree::freeNode( Node* node ) {

	if (node != NULL) {
        freeNode(node->left);
        freeNode(node->right);
        cout << "Deleting " << node->value << "..." << endl;
        delete node;
    }

 }

void Tree::insert( string value ) {

	if (root == NULL) {
		Node* n = new Node(value);
		root = n;
	}
	else {
		addNode( value, root );
	}

}

void Tree::addNode( string value, Node* leaf ) {

	if ( value == leaf->value ) {
		leaf->count++;
	}
	else if ( value < leaf->value ) {
		if ( leaf->left != NULL ) {
			addNode(value, leaf->left);
		}
		else {
			Node* n = new Node(value);
			leaf->left = n;
		}
	}
	else {
		if ( leaf->right != NULL ) {
			addNode(value, leaf->right);
		}
		else {
			Node* n = new Node(value);
			leaf->right = n;
		}
	}

}

/*
bool Tree::search( string ) {



}

string Tree::largest() {



}

string Tree::smallest() {}
int Tree::height() {}
void Tree::remove( string ) {}
void Tree::preOrder() {}
void Tree::inOrder() {}
void Tree::postOrder() {}
*/
Node* Tree::getRoot() {

	return root;

}

