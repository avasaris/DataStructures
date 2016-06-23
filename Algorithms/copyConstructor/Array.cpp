// Fig 11.7: Array.cpp
// Array class member- and friend-function definitions.

#include <iostream>
#include <iomanip>
#include <cstdlib> // exit function prototype
#include "Array.h" // Array class definition
using namespace std;

// default constructor for class Array (default size 10)
Array::Array( int arraySize ) {
	size = ( arraySize > 0 ? arraySize : 10 ); // validate arraySize
	ptr = new int[ size ]; // create space for pointer-based array

	for ( int i = 0; i < size; i++ )
	ptr[ i ] = 0; // set pointer-based array element
	} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to prevent infinite recursion
Array::Array( const Array &arrayToCopy ) : size( arrayToCopy.size ) {
	ptr = new int[ size ]; // create space for pointer-based array

	for ( int i = 0; i < size; i++ )
		ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
} // end Array copy constructor

// destructor for class Array
Array::~Array()	{
	delete [] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
int Array::getSize() const {
	return size; // number of elements in Array
} // end function getSize

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3

const Array &Array::operator=( const Array &right ) {
	if ( &right != this ) 	// avoid self assignment
	{
	// for Arrays of different sizes, deallocate original
	// left-side array, then allocate new left-side array
	if ( size != right.size ) {
		delete [] ptr; // release space
		size = right.size; // resize this object
		ptr = new int[ size ]; // create space for array copy
	} // end inner if

	for ( int i = 0; i < size; i++ )
		ptr[ i ] = right.ptr[ i ]; // copy array into object
	} // end outer if

	return *this; // enables x = y = z, for example
} // end function operator=




