/**
 * UCR CS&E
 * CS014 Lab 1
 * List.cpp
 */

#include <iostream>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

/**
 * Constructor
 */
List::List()
{
	head = NULL;
	tail = NULL;
}

/**
 * Destructor
 */
List::~List()
{
	cout << "\nList Destructor called...\n";
	
	while(head)
	{
		Node* temp = head;
		head = head->get_next();
		cout << "Deleting.... " << temp->get_value() << endl;
		delete temp;
	}	
}

/**
 * push_back() inserts a new node at the tail
 * end of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_back(int value)
{
	Node* new_node = new Node(value);
	
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_prev(tail);
		tail->set_next(new_node);
		tail = new_node;
	}
}
/**
 * push_front() inserts a new node at the 
 * front of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_front(int value)
{
	Node* new_node = new Node(value);
		
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_next(head);
		head->set_prev(new_node);
		head = new_node;			
	}
}

/**
 * print()const prints the contents of 
 * the list to the console, starting
 * at the head of the list
 * @param none
 * @return none
 */
void List::print()const
{
	cout << "\nList contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return List's head Node pointer
 */
Node* List::get_head()const
{
	return head;
}

/**
 * get_tail()const  returns the tail
 * Node pointer which points to the
 * last element in the list
 * @param none
 * @return List's tail Node pointer
 */
Node* List::get_tail()const
{
	return tail;
}

/**
 * begin()const gets beginning postion of the list
 * @param none
 * @return an Iterator pointing to the beginning of the list
 */
Iterator List::begin()const
{
	Iterator iter;
	iter.set_curr_pos(get_head());
	iter.set_last_pos(get_tail());
	return iter;
}

/**
 * end()const gets past-the-end postion of the list
 * @param none
 * @return an Iterator pointing just past the end of the list
 */
Iterator List::end()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_tail());
	return iter;
}

Iterator List::betterEnd()const
{
	Iterator iter;
	iter.set_curr_pos(get_tail());
	iter.set_last_pos(get_tail());
	return iter;
}

void List::sorted_insert(int value) {
	
	Node* new_node = new Node(value);	// Create new Node with desired value
	Node* previous_node = NULL;			// Create pointer for previous node, initially set to NULL

	/* list is empty */
	if(!head) {
		push_front(value);
	}
	else {
		for( Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()) {
			if (iter.get_value() >= value) {
				// Check if new node will be new head of list
				if (iter.get_curr_pos() == head) {
					push_front(value);
				}
				else {
					// update next pointers
						new_node->set_next(iter.get_curr_pos());
						previous_node->set_next(new_node);
					// update previous pointers
						new_node->set_prev(previous_node);
						iter.get_curr_pos()->set_prev(new_node);
				}
				break;
			}
			else if ((iter.get_curr_pos() == tail)) {			// Check if new node should be placed at the end of the list
				push_back(value);
				break;
			}
			previous_node = iter.get_curr_pos(); //update previous position
		}
	}
}

void List::print_reverse() const {

	cout << "\nReverse List contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = betterEnd(); iter.get_curr_pos()!=NULL; iter.prev_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";

}

 void List::insertAfter(int i, int value) {

 	Node* new_node = new Node(value);
 	Node* next_node;
 	int position = 0;
 	bool placed = false;	

	for( Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()) {
		next_node = iter.get_curr_pos()->get_next();
		position++;
		if (i == position) {
			// Update next pointers
			new_node->set_next(next_node);
			iter.get_curr_pos()->set_next(new_node);

			// Update previous pointers
			next_node->set_prev(new_node);
			new_node->set_prev(iter.get_curr_pos());
			placed = true;
			break;
		}
	}

	if (!placed) {
		if (i < 50) {
			push_front(value);
		}
		else {
			push_back(value);
		}
	}	

 }

 void List::insertBefore(int i, int value) {

 	Node* new_node = new Node(value);
 	Node* previous_node;
 	int position = 0;
 	bool placed = false;	

	for( Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()) {
		previous_node = iter.get_curr_pos()->get_prev();
		position++;
		if (i == position) {
			// Update next pointers
			new_node->set_next(iter.get_curr_pos());
			previous_node->set_next(new_node);

			// Update previous pointers
			new_node->set_prev(previous_node);
			iter.get_curr_pos()->set_prev(new_node);
			placed = true;
			break;
		}
	}

	if (!placed) {
		if (i < 50) {
			push_front(value);
		}
		else {
			push_back(value);
		}
	}

 }

  int List::count(int value) const {

  	int count = 0;

  	for( Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()) {
  		if (iter.get_value() == value) {
  			count++;
  		}
  	}

  	return count;

  }

