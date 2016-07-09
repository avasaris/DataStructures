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
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <iostream>
#include "Tree.h"
#include "Node.h"

using namespace std;

void printOrders( Tree *tree ) {
	cout << "Preorder = ";
	tree->preOrder( );
	cout << endl;
	cout << "Inorder = ";
	tree->inOrder( );
	cout << endl;
	cout << "Postorder = ";
	tree->postOrder( );
	cout << endl;
}

int main( ) {
	Tree tree;

	tree.insert( "hoppy" );
	tree.insert( "gadget" );
	tree.insert( "hoppy" );
	tree.insert( "gadget" );
	tree.insert( "reel" );
	tree.insert( "trap" );
	tree.insert( "madness" );
	tree.insert( "aeon" );
	tree.insert( "hoppy" );
	tree.insert( "gadget" );
	tree.insert( "hoppy" );
	tree.insert( "gadget" );
	tree.insert( "reel" );
	tree.insert( "trap" );
	tree.insert( "madness" );
	tree.insert( "aeon" );
	tree.insert( "alphabet" );
	tree.insert( "alphabet" );
	tree.insert( "basket" );
	tree.insert( "basket" );
	tree.insert( "hut" );
	tree.insert( "hit" );
	tree.insert( "House" );
	tree.insert( "A+" );
	tree.insert( "jungle" );
	tree.insert( "ink" );
	tree.insert( "jab" );
	tree.printTreeSideways();
	cout << endl << endl;

	return 1;
}