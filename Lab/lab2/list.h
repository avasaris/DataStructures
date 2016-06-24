 /**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: lab2
 * Filename : list.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#ifndef __LIST_H_
#define __LIST_H_

#include "node.h"

class List {
private:
  Node* head;

public:
  List ( );
  List( const List & );		// copy constructor
  ~List ( );
  const List &operator=( const List & );	// overload assignment operator
  int size ( ) const;
  void push_front ( int );
  void push_back ( int );
  void print ( );
};

#endif

