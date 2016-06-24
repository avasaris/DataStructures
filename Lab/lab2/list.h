// CS14
// This file contains the list class declaration.

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

