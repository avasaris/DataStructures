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
  ~List ( );
  int size ( );
  void push_front ( int );
  void push_back ( int );
  void print ( );
  // Add new member function declarations here
};

#endif

