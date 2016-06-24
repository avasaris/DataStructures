// CS14
// This file contains all of the functions for the list class

#include "list.h"
#include <cstdlib>
#include <iostream>

using namespace std;

List::List ( ) {

  head = NULL;

}

//------------------------------------------------------------------------

List::~List ( ) {

  // ADD: to avoid memory leaks, make sure you delete all allocated memory

    cout << "\nList Destructor called...\n";
    while(head) {
        Node* temp = head;
        head = head->next;
        cout << "Deleting.... " << temp->value << endl;
        delete temp;
    }
}

//------------------------------------------------------------------------

const List &List::operator=( const List &right ) {

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
    }   

    return *this;   // return yourself (basically)

}

//------------------------------------------------------------------------

int 
List::size ( ) const {
  int size = 0;
  for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    size ++;
  }
  return size;
}

//------------------------------------------------------------------------

void 
List::push_front ( int value ) {

  Node* insert = new Node;
  insert->value = value;
  insert->next = head;
  head = insert;

}

//------------------------------------------------------------------------

void
List::push_back ( int value ) {

  if ( size ( ) == 0 ) {
    push_front ( value );
  }
  else {
    Node* tail;
    for ( tail = head; tail->next != NULL; tail = tail->next );
    Node* insert = new Node;
    insert->value = value;
    insert->next = NULL;
    tail->next = insert;
  }

}

//------------------------------------------------------------------------

void 
List::print ( ) {

  if ( size ( ) == 0 ) {
    cout << "No elements in the array" << endl;
    return;
  }

  for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    cout << temp->value << " ";
  }
  cout << endl;
}
