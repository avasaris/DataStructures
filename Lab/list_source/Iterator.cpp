/**
 * UCR CS&E
 * CS014 Lab 1
 * Iterator.cpp
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


