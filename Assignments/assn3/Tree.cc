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

 	freeNode( getRoot() );

 }

void Tree::freeNode( Node* node ) {

	if (node != NULL) {
        freeNode(node->left);
        freeNode(node->right);
        delete node;
    }

 }

void Tree::insert( string v ) {

	if (root == NULL) {
		Node* n = new Node(v);
		root = n;
	}
	else {
		addNode( v, root );
	}

}

void Tree::addNode( string v, Node* leaf ) {

	if ( v == leaf->value ) {
		leaf->count++;
	}
	else if ( v < leaf->value ) {
		if ( leaf->left != NULL ) {
			addNode(v, leaf->left);
		}
		else {
			Node* n = new Node(v);
			leaf->left = n;
		}
	}
	else if (v > leaf->value) {
		if ( leaf->right != NULL ) {
			addNode(v, leaf->right);
		}
		else {
			Node* n = new Node(v);
			leaf->right = n;
		}
	}

}

bool Tree::search( string v ) {

	Node* temp = root;

	while (temp != NULL) {
		if (temp->value == v) {
			return true;
		}
		else if (v < temp->value) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return false;

}

string Tree::largest() {

	if (root) {
		Node* temp = root;
		while (temp->right != NULL) {
			temp = temp->right;
		}
	  	return temp->value;
	}
	else {
		return "";
	}

}

string Tree::smallest() {

	if (root) {
		return find_min(root)->value;
	}
	else {
		return "";
	}

}

int Tree::height( string v ) {

	int h = height(v, root, 0);
	return h;

}

int Tree::height( string v, Node* node, int h ) {

    if (node == NULL) {
        return 0;
    }

    if (node->value == v) {
        return h;
    }

    int depth = height(v, node->left, h+1);
    if (depth != 0 ) {
        return depth;
    }

    depth = height(v, node->right, h+1);
    return depth;

}

void Tree::remove( string v ) {

	root = remove(v, root);

}

Node* Tree::remove( string v, Node* node ) {

	if (node == NULL) {
		return node;
	}
  	else if (v < node->value) {
  		node->left = remove(v, node->left);
  	}
  	else if (v > node->value) {
  		node->right = remove(v, node->right);
  	}
	else {
		// Case 1: No Children
		if (node->left == NULL && node->right == NULL) {
		  	delete node;
		  	node = NULL;
		}
		// Case 2: One Child
		else if (node->left == NULL) {
			Node* temp = node;
			node = node->right;
			delete temp;
		} 
		else if (node->right == NULL) {
			Node* temp = node;
			node = node->left;
			delete temp;
		} 
		else {
			Node* temp = find_min(node->right);
			node->value = temp->value;
			node->right = remove(temp->value, node->right);
		}
	}
	return node;

}

void Tree::preOrder() {

	preOrder(root);

}

void Tree::inOrder() {

	inOrder(root);

}

void Tree::postOrder() {

	postOrder(root);

}

void Tree::preOrder( Node* node ) {

	if (node) {
		cout << node->value << "(" << node->count << "), ";
        preOrder(node->left);
        preOrder(node->right);
    }  

}

void Tree::inOrder( Node* node ) {

	if (node) {
        inOrder(node->left);
        cout << node->value << "(" << node->count << "), ";
        inOrder(node->right);
    }

}

void Tree::postOrder( Node* node ) {

	if (node) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << "(" << node->count << "), ";
    }

}

Node* Tree::find_min( Node* node ) {

	while (node->left != NULL) {
		node = node->left;
	}
  	return node;

}

Node* Tree::getRoot() {

	return root;

}

void Tree::printTreeSideways() {

	printTreeSideways(root, 0);

}

void Tree::printTreeSideways( Node* node, int depth ) {

	depth =  depth + 5;

    if ( node == NULL ) {
    	return;
    }
    if ( node->right != NULL ) {
    	printTreeSideways(node->right, depth);
    }

    for( int i = 0; i!=depth; ++i ) {
        cout << " ";
    }
    cout << node->value << "(" << node->count << ")" << endl << endl;
    if ( node->left != NULL ) {
        printTreeSideways(node->left, depth);
        depth = depth - 5;
    }

}

