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
 * Filename : MyList.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <cstring>
#include <cstdlib>
 #include <cctype>
#include <string>
#include "MyList.h"
#include "Node.h"

#define debug true

using namespace std;

/**
 * Constructors
 */

/*	Default Constructor
	@param none
*/
MyList::MyList()
{
	debugger("Default Constructor called...");
	head = NULL;
}

/*	Copy Constructor
	@param str: object of type MyList
*/
MyList::MyList(const MyList& myListToCopy) {

	debugger("MyList object passed through Constructor...");
	
	// Get new space
        int length = myListToCopy.size();     // get the size of the list to be copied
        	debugger("left size function...");
        Node* node_pointers[ length ];      // create an array of pointers to Node objects

        for (int i=0; i<length; i++) {      // Initialize array of pointers with correct number of Nodes
            node_pointers[i] = new Node;
        }

    // Copy
        Node* node_to_copy = myListToCopy.head;    // Get the head of the list to be copied in temporary node to loop through

        head = node_pointers[0];            // Redirect head pointer to beginning of new Node pointers array
        head->value = node_to_copy->value;  // assign the head's value from the copy node
        head->next = node_pointers[1];      // assign the head's next pointer to next element in Node pointers array

        for (int i=1; i<(length-1); i++) {  // fill in the rest of Nodes with correct values and next pointers
            node_to_copy = node_to_copy->next;
            node_pointers[i]->value = node_to_copy->value;
            node_pointers[i]->next = node_pointers[i+1];
        }

        node_to_copy = node_to_copy->next;                          // last element needs to be done outside of loop 
        node_pointers[length-1]->value = node_to_copy->value;       // bc it's next pointer needs to point to NULL

}

/*	Nondefault Constructor
	@param str: string object
*/
MyList::MyList(const string& str) {

	debugger("String object passed through Constructor...");
	int length = str.length();

	// Create an array of pointers to objects of type Node
	Node* node_pointers[length];

	// Fill array with pointers of type Node
	for (int i=0; i<length; i++) {
		node_pointers[i] = new Node(str[i]);
	}

	head = node_pointers[0];
	head->set_next(node_pointers[1]);

	for (int i=1; i<length; i++) {
		node_pointers[i]->set_next(node_pointers[i+1]);
	}

}

/*	Default Constructor
	@param str: char* object (array of characters)
*/
MyList::MyList(const char* str){

	debugger("char* object passed through Constructor...");
	int length = strlen(str);
	
	// Create an array of pointers to objects of type Node
	Node* node_pointers[length];

	// Fill array with pointers of type Node
	for (int i=0; i<length; i++) {
		node_pointers[i] = new Node(str[i]);
	}

	head = node_pointers[0];
	head->set_next(node_pointers[1]);

	for (int i=1; i<(length-1); i++) {
		node_pointers[i]->set_next(node_pointers[i+1]);
	}
}

/**
 * Destructor
 */
MyList::~MyList()
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

/* Mutators 
*/

/**
 * push_front() inserts a new node at the 
 * front of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void MyList::push_front(char value)
{
	debugger("push_front function called...");
	/*
	Node* new_node = new Node(value);	
	new_node->set_next(head);
	head = new_node;*/

	Node* insert = new Node;
  	insert->value = value;
  	insert->next = head;
  	head = insert;			
	
}

void MyList::push_back(char value) {
	
	debugger("push_back function called...");
	/*
	Node* new_node = new Node(value);
	if(!head)
	{
		head = new_node;
	}
	else
	{
		Node* temp;
		Node* last;
		for (temp=head; temp != NULL; temp=temp->get_next()) {
			last = temp;
		}
		last->set_next(new_node);
	} */

	if ( size() == 0 ) {
    	push_front ( value );
  	}
  	else {
	    Node* tail;
	    for ( tail = head; tail->next != NULL; tail = tail->next ) {
		    Node* insert = new Node;
		    insert->value = value;
		    insert->next = NULL;
		    tail->next = insert;
		}
  	}
}

void MyList::pop_front() {

	debugger("pop_front function called...");
	Node* temp = head;
	head = head->get_next();
	delete temp;

}

void MyList::pop_back() {

	debugger("pop_back function called...");
	Node* temp;
	Node* last;
	for (temp=head; temp != NULL; temp=temp->get_next()) {
		last = temp;
	}
	delete temp;
	delete last;

}

void MyList::swap( int i, int j ) {

	debugger("swap function called...");
	char value_i, value_j;

	int position = 0;
	Node* temp;
	if ( (i > 0 && i <= size()) && (j > 0 && j <= size()) ) {
		// Get both values to swap
		for (temp=head; temp != NULL; temp=temp->get_next()) {
			position++;
			if (position == i) {
				value_i = temp->get_value();
				cout << value_i << endl;
			}
			else if (position == j) {
				value_j = temp->get_value();
				cout << value_j << endl;
			}
		}
		position=0;
		// swap the values
		for (temp=head; temp != NULL; temp=temp->get_next()) {
			position++;
			if (position == i) {
				temp->set_value(value_j);
			}
			else if (position == j) {
				temp->set_value(value_i);
			}
		}
	}
	else {
		cout << "The position you entered to swap is invalid!\n" << endl;
	}

}

void MyList::insert_at_pos(int i, char value) {

	debugger("insert_at_pos function called...");
	Node* new_node = new Node(value);	// Create new Node with desired value
	Node* previous_node = NULL;			// Create pointer for previous node, initially set to NULL

	int position=0;
	Node* temp;
	if (i==1) {
		push_front(value);
	}
	else if (i == size()+1) {
		push_back(value);
	}
	else if (i<=0 && (i > (size()+1))) {
		cout << i << endl;
		cout << size() << endl;
		cout << "You cannot insert at that position, it doesn't exist!" << endl;
	}
	else {
		for (temp=head; temp != NULL; temp=temp->get_next()) {
			position++;
			if (position == i) {
				new_node->set_next(temp);
				previous_node->set_next(new_node);
			}
			previous_node = temp; 		//update previous position
		}
	}

}

void MyList::reverse() {

	debugger("reverse function called...");
	int length = size();
	int values[length];
	int decrementer = 1;

	Node* temp;
	for (temp=head; temp != NULL; temp=temp->get_next()) {
		values[length-decrementer] = temp->get_value();
		decrementer++;
	}

	int i=0;
	for (temp=head; temp != NULL; temp=temp->get_next()) {
		temp->set_value(values[i]);
		i++;
	}

}
/* Accessors
*/

int MyList::size() const {

	debugger("size function called...");
	/*
	int count = 0;
	Node* temp;
	for (temp=head; temp != NULL; temp=temp->get_next()) {
		count++;
	}

	return count;*/

	int size = 0;
	for ( Node* temp = head; temp != NULL; temp = temp->next ) {
		debugger("In size function for loop...");
		size ++;
	}
	return size;

}

/**
 * print()const prints the contents of 
 * the list to the console, starting
 * at the head of the list
 * @param none
 * @return none
 */
void MyList::print()const
{
	debugger("print function called...");
	cout << "\nList contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	Node* temp;
	for (temp=head; temp != NULL; temp=temp->get_next()) {
		cout << temp->get_value() << ", ";
	}
	cout << "\n";
}

int MyList::find(char value) const {

	debugger("find function called...");
	int position=0;
	Node* temp;
	for (temp=head; temp != NULL; temp=temp->get_next()) {
		position++;
		if (temp->get_value() == value) {
			return position;
		}
	}

	return -1;

}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return MyList's head Node pointer
 */
Node* MyList::get_head()const
{
	debugger("get_head function called...");
	cout << "\nget_head function called. returning: " << head->get_value() << endl;
	return head;
}

/* Operator overloads 
*/

void MyList::debugger( string message ) const {

	if (debug) {
		cout << message << endl;
	}

}
