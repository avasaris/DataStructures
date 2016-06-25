/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: lab1
 * Filename : Node.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "Node.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/* Default Constructor */
Node::Node()
{
	next = NULL;
	value = 0;
}

/* Overloaded Constructor
 * @param value integer node value
 */
Node::Node(char value)
{
	next = NULL;
	this->value = value;
}

/* Destructor */
Node::~Node()
{}

/*
 * Mutators
 */
void Node::set_next(Node* temp)
{
	next = temp;
}

/* 
 * Accessors
 */
Node* Node::get_next()const
{
	return next;
}

char Node::get_value()const
{
	return value;
}

void Node::set_value(char v) {

	value = v;

}