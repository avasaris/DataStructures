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
 * Filename : List.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef LIST_H_
#define LIST_H_

#include "Node.h"
#include "Iterator.h"

class List
{
public:
	List();
	~List();
	void push_back(int value);
	void push_front(int value);
	void print()const;
	Node* get_head()const;
	Node* get_tail()const;		
	Iterator begin()const;
	Iterator end()const;
	
	/* These functions are all yours! */
	void sorted_insert(int value);
	void print_reverse()const;
	Iterator betterEnd()const;
	void insertAfter(int i, int value);
	void insertBefore(int i, int value);
	int count(int value) const;
	
private:
	Node* head;
	Node* tail;
};

#endif /*LIST_H_*/
