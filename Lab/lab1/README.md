Lab 1
-----
-----

Description
-----------
The domain of the project will be a most fundamental data structure, a doubly­linked, linked list.
The source code provided to you (see below) supports push back, push front, and printing the
list. In addition, this implementation makes use of a user defined Iterator object for traversing
the list and accessing its contents. One caveat of the implementation is that it does not make
any classes friends of other classes, but rather adheres strictly to OOD/OOP (Object Oriented
Design/Object Oriented Programming) principles, i.e. data encapsulation.

Functions
---------
1. **void List::sorted_insert(int value)** 
Takes an integer value inserts it into the list as a new node in the list. This insert_sort should preserve the increasing ordering of the list, i.e. if you were to insert a 5, then the new node would have a value of 5 and be inserted after the highest integer less than 5 and before any integer equal to or greater than 5. You can  assume that the list is already sorted, though might be empty or have one element.

2. List::print_reverse() const 
Prints the contents of a list backwards

3. List::insertAfter(int i, int value) 
Inserts a node with specified value at position i+1 in the list

4. void List::insertBefore(int i, int value) 
Inserts a node with specified value at position i­1 in the list.

5. int List::count(int value) const 
Returns the number of times value appears in the list.
