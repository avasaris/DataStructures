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

#define debug false

using namespace std;

/**
 * Constructors
 */

/*	Default Constructor
	@param none
*/
MyList::MyList() {
	debugger("Default Constructor called...");
	head = NULL;
}

/*	Copy Constructor
	@param str: object of type MyList
*/
MyList::MyList(const MyList& myListToCopy) {

	debugger("MyList object passed through Constructor...");
	
	// Get new space
        int length = myListToCopy.size();   // get the size of the list to be copied
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
	Node* node_pointers[length];			// Create an array of pointers to objects of type Node

		for (int i=0; i<length; i++) {			// Fill array with pointers of type Node
			node_pointers[i] = new Node;
			node_pointers[i]->value = str[i];
		}

	// Copy to new space 
		head = node_pointers[0];				// Redirect head pointer to beginning of new Node pointers
		head->next = node_pointers[1];

		for (int i=1; i<(length-1); i++) {
			node_pointers[i]->next = node_pointers[i+1];
		}

		node_pointers[length-1]->next = NULL;	// Make sure tail points to NULL
}

/*	Default Constructor
	@param str: char* object (array of characters)
*/
MyList::MyList(const char* str) {
	debugger("char* object passed through Constructor...");
	
	// Get new space
		int length = strlen(str);				// get length of string passed
		Node* node_pointers[length];			// Create an array of pointers to objects of type Node

		for (int i=0; i<length; i++) {			// Fill array with pointers of type Node
			node_pointers[i] = new Node;
			node_pointers[i]->value = str[i];
		}

	// Copy to new space 
		head = node_pointers[0];				// Redirect head pointer to beginning of new Node pointers
		head->next = node_pointers[1];

		for (int i=1; i<(length-1); i++) {
			node_pointers[i]->next = node_pointers[i+1];
		}

		node_pointers[length-1]->next = NULL;	// Make sure tail points to NULL
}

/**
 * Destructor
 */
MyList::~MyList() {
	debugger("List Destructor called...");
	
	while(head)
	{
		Node* temp = head;
		head = head->next;
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
void MyList::push_front(char value) {
	debugger("push_front function called...");

	Node* insert = new Node;
  	insert->value = value;
  	insert->next = head;
  	head = insert;			
	
}

/**
 * push_back() inserts a new node at the 
 * back of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void MyList::push_back(char value) {
	debugger("push_back function called...");
	
	Node* new_node = new Node;
	new_node->value = value;
	if(!head)
	{
		head = new_node;
	}
	else
	{
		Node* temp;
		Node* last;
		for (temp=head; temp != NULL; temp=temp->next) {
			last = temp;
		}
		last->next = new_node;
	} 
}

/**
 * pop_front() removes the Node at the front of 
 * the list, updates the head 
 * @param value an integer Node value
 * @return none
 */
void MyList::pop_front() {
	debugger("pop_front function called...");

	Node* temp = head;
	head = head->next;
	delete temp;
}

/**
 * pop_back() removes the Node at the back of 
 * the list, updates the previous next pointer
 * @param value an integer Node value
 * @return none
 */
void MyList::pop_back() {
	debugger("pop_back function called...");

	Node* temp;
	Node* last;
	int position = 0;
	for (temp=head; temp != NULL; temp=temp->next) {
		position++;
		last = temp;
	}
	delete last;
	
	int i=0;
	for (temp=head; temp != NULL; temp=temp->next) {
		i++;
		if (i == (position-1)) {
			temp->next = NULL;
		}
	}
	delete temp;	
}

/**
 * swap() swaps the values of the nodes at
 * locations passed through the function
 * @param i: location 1, j: location 2
 * @return none
 */
void MyList::swap( int i, int j ) {
	debugger("swap function called...");

	char value_i, value_j;

	int position = 0;
	Node* temp;
	if ( (i > 0 && i <= size()) && (j > 0 && j <= size()) ) {
		// Get both values to swap
		for (temp=head; temp != NULL; temp=temp->next) {
			position++;
			if (position == i) {
				value_i = temp->value;
			}
			else if (position == j) {
				value_j = temp->value;
			}
		}
		position=0;
		// swap the values
		for (temp=head; temp != NULL; temp=temp->next) {
			position++;
			if (position == i) {
				temp->value = value_j;
			}
			else if (position == j) {
				temp->value = value_i;
			}
		}
	}
	else {
		cout << "The position you entered to swap is invalid!\n" << endl;
	}
}

/**
 * insert_at_pos() inserts a node after location i
 * with a specfic char value 
 * @param i: location to insert after, value: char value of node 
 * @return none
 */
void MyList::insert_at_pos(int i, char value) {
	debugger("insert_at_pos function called...");

	Node* new_node = new Node;	// Create new Node with desired value
	new_node->value = value;
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
		cout << "You cannot insert at that position, it doesn't exist!" << endl;
	}
	else {
		for (temp=head; temp != NULL; temp=temp->next) {
			position++;
			if (position == i) {
				new_node->next = temp;
				previous_node->next = new_node;
			}
			previous_node = temp; 		//update previous position
		}
	}
}

/**
 * reverse() reverses the order of the list
 * @param none
 * @return none
 */
void MyList::reverse() {
	debugger("reverse function called...");

	int length = size();
	int values[length];
	int decrementer = 1;

	Node* temp;
	for (temp=head; temp != NULL; temp=temp->next) {
		values[length-decrementer] = temp->value;
		decrementer++;
	}

	int i=0;
	for (temp=head; temp != NULL; temp=temp->next) {
		temp->value = values[i];
		i++;
	}

}

/* Accessors
*/

/**
 * size() returns the number if nodes in the list
 * @param none
 * @return integer size
 */
int MyList::size() const {
	debugger("size function called...");

	int size = 0;
	for ( Node* temp = head; temp != NULL; temp = temp->next ) {
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
void MyList::print()const {
	debugger("print function called...");

	if ( size () == 0 ) {
    	cout << "No elements in this list" << endl;
    	return;
  	}

  	for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    	cout << temp->value;
  	}
  	cout << endl;
}

/**
 * find() finds the location of the character passed in the list
 * @param value: char to be located
 * @return integer location where found
 */
int MyList::find(char value) const {
	debugger("find char function called...");

	int position=0;
	Node* temp;
	for (temp=head; temp != NULL; temp=temp->next) {
		position++;
		if (temp->value == value) {
			return position;
		}
	}

	return -1;
}

/**
 * find() finds the location of the query string passed in the list
 * @param value: string to be located
 * @return integer location where found
 */
int  MyList::find(MyList& query_str) const {
	debugger("find query string function called...");

	// Convert MyList to char array
	char value[size()];
	int p = 0;;
	Node* temp;
	for (temp=head; temp != NULL; temp=temp->next) {
		value[p]=temp->value;
		p++;
	}

	// Convert Query String to char array
	char query[query_str.size()];
	p = 0;
	for (temp=query_str.head; temp != NULL; temp=temp->next) {
		query[p]=temp->value;
		p++;
	}

	// Find substring 
	int i=0,j=0,first_occurence=0;
    for(i=0; i<size(); i++) {
        j=0;
        if( value[i]==query[j] ) {
            first_occurence = i+1;
            while( value[i] == query[j]) {
                i++;
                j++;
            }
            if( j == query_str.size() ) {
                return first_occurence;
            }
            else {
                i = first_occurence;
                first_occurence=0;
            }
        }
    }
 
 	// If substring doesn't exist first_occurence 
 	// will be 0
    if( first_occurence == 0 ) {
    	return -1;
    }

}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return MyList's head Node pointer
 */
Node* MyList::get_head()const {
	debugger("get_head function called...");

	return head;
}

/* Operator overloads 
*/

const MyList &MyList::operator=( const MyList &right ) {
	debugger("Assignment operator overload function called...");

    if ( &right != this ) {   // Avoid self assignment

        // Delete Associated Memory
            Node* next;
            for ( Node* temp = head; temp != NULL; temp = next ) {
                next = temp->next;
                delete temp;
            }

        // Get new space
            int length = right.size();          // get the size of the list to be copied
            Node* node_pointers[ length ];      // create an array of pointers to Node objects
	    
            for (int i=0; i<length; i++) {      // Initialize array of pointers with correct number of Nodes
                node_pointers[i] = new Node;
            }

        // Copy
            Node* node_to_copy = right.head;    // Get the head of the list to be copied in temporary node to loop through

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
    	    node_pointers[length-1]->next = NULL;
	}   

    return *this;   // return yourself (basically)
}

char& MyList::operator[](const int i) {
	debugger("Bracket operator overload function called...");

	char blank = ' ';
	int position=0;
	if (i<0 || (i>size())) {
		cout << "You cannot access that position, it doesn't exist" << endl;
		return blank;
	}
	else {
		Node* temp;
		for (temp=head; temp != NULL; temp=temp->next) {
			position++;
			if (position == i) {
				return temp->value;
			}
		}
	}
}

MyList MyList::operator+( MyList &right) {
	debugger("Addition operator overload function called...");

	Node* last;
	Node* temp;
	for (temp=head; temp != NULL; temp=temp->next) {
		last = temp;
	}

	last->next = right.head;
	right.head = NULL;

	return *this;
}

// Debugger Function
void MyList::debugger( string message ) const {

	if (debug) {
		cout << message << endl;
	}

}
