 /**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015
 *
 *
 * Assignment: lab1
 * Filename : Iterator.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <cstdlib>
#include <cassert>
#include "Iterator.h"
#include "Node.h"

/**
 * Constructor
 */
Iterator::Iterator()
{
	curr_pos = NULL;
	last_pos = NULL;
}

/**
 * Destructor
 */
Iterator::~Iterator()
{}

/**
 * Looks up the value at the current postion
 * @param none
 * @return the value of the node to which iterator points
 */
int Iterator::get_value()const
{
	assert(get_curr_pos() != NULL);
	return get_curr_pos()->get_value();
}

/**
 * Accessors
 */
Node* Iterator::get_curr_pos()const
{
	return curr_pos;
}

Node* Iterator::get_last_pos()const
{
	return last_pos;
}

/**
 * Mutators
 */
void Iterator::set_curr_pos(Node* temp)
{
	curr_pos = temp;
}

void Iterator::set_last_pos(Node* temp)
{
	last_pos = temp;
}

/**
 * Compares two iterators
 * @param rhs the iterator to compare to 'this' 
 * @return true if iterators are equal
 */ 
bool Iterator::is_equal(Iterator rhs)const
{
	/* Both iterators point to same memory location */
	if(get_curr_pos() == rhs.get_curr_pos())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * Advances iterator to the next node
 * @param none
 * @return none
 */
void Iterator::next_pos()
{
	assert(get_curr_pos() != NULL);
	set_curr_pos(get_curr_pos()->get_next());
}

/**
 * Advances iterator to the previous node
 * @param none
 * @return none
 */
void Iterator::prev_pos() {

	//assert(get_curr_pos() != NULL);
	set_curr_pos(get_curr_pos()->get_prev());

}
