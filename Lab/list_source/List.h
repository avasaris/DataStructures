/**
 * UCR CS&E
 * CS014 Lab 1
 * List.h
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
	
private:
	Node* head;
	Node* tail;
};

#endif /*LIST_H_*/
