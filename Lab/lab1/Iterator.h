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
 * Filename : Iterator.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "Node.h"

class Iterator
{
public:
	Iterator();
	~Iterator();
	int get_value()const;
	Node* get_curr_pos()const;
	Node* get_last_pos()const;
	void set_curr_pos(Node*);
	void set_last_pos(Node*);
	bool is_equal(Iterator rhs)const;
	void next_pos();
	
	/* You must implement this ! */
	void prev_pos();
	
private:
	Node* curr_pos;
	Node* last_pos;
};

#endif /*ITERATOR_H_*/
