/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: lab6
 * Filename : MaxBinaryHeap.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#ifndef MAXBINARYHEAP_H_
#define MAXBINARYHEAP_H_
#define debug false

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <class T>
class MaxBinaryHeap {
	public:
		MaxBinaryHeap( int capacity = 100 ) 
		: currentSize(0), array(capacity) {}
		MaxBinaryHeap( const vector<T>& items ) 
		:  currentSize( items.size( ) ), array( items.size( ) + 10 ) {

    		//cout << "currentSize: " << currentSize << endl;
    		//cout << "capacity: " << capacity << endl;

	        for( unsigned int i = 0; i < items.size( ); i++ ) {
	            array[ i + 1 ] = items[ i ];
	        }
	        buildHeap( );
	    }
		bool isEmpty() const;
		const T & findMax() const;
		void insert( const T & x );
		void print() const;
		void deleteMax();
		int getSize();
		void debugger(string);
	private:
		int currentSize;
		vector<T> array;
		void percolateUp( int hole );
	    void insert( T& newItem );
	    void buildHeap();
	    void percolateDown( int hole );
	    int maximum( int hole );
};

template <class T>
int MaxBinaryHeap<T>::getSize() {

	return currentSize;

}

template <class T>
bool MaxBinaryHeap<T>::isEmpty( ) const {
    return (currentSize==0);
}

template <class T>
const T & MaxBinaryHeap<T>::findMax( ) const {
    if (currentSize==0) {
        throw underflow_error("Heap is Empty");
    }
    return array[1];
}

template <class T>
void MaxBinaryHeap<T>::insert( const T & x ) {
    T value = x;
    insert(value);
}
    
/**
 * Prints the elements of the underlying array in the BinaryHeap
 */
template <class T>
void MaxBinaryHeap<T>::print( ) const {
    for( int i = 1; i < currentSize + 1; i++ )
        cout << array[i] << " ";
    cout << endl;
}

/**
 * Remove the minimum item and place it in minItem.
 * Exits the program if empty.
 */
template <class T>
void MaxBinaryHeap<T>::deleteMax( ) {
    if( isEmpty( ) ) {
        // throw UnderflowException( );
        cerr << "Heap is empty" << endl;
        exit(1);
    }
    array[ 1 ] = array[ currentSize-- ];
    percolateDown( 1 );
}

// Private Functions
template <class T>
void MaxBinaryHeap<T>::percolateUp( int hole ) {

    // can only percolate up if the hole isn't the root
    if ( hole > 1 ) {

        // check if current node has smaller value than its parent
        if ( array[hole/2] < array[hole] ) {
            // move up one level
            swap( array[hole], array[hole/2] );

            // call recusively to see if it needs to be done again
            percolateUp( hole/2 );
        }
    }
}

template <class T> 
void MaxBinaryHeap<T>::insert( T& newItem ) {

	int size = array.size();
    if ( currentSize >= size ) {
        throw overflow_error("Heap Full Exception");
    }

    currentSize++;
    array[currentSize] = newItem;
    percolateUp( currentSize ); 
}
    
/**
 * Establish heap order property from an arbitrary
 * arrangement of items. Runs in linear time.
 */
template <class T>
void MaxBinaryHeap<T>::buildHeap( ) {
	debugger("buildHeap...");
    // Only try to percolate down internal nodes
    for( int i = currentSize / 2; i > 0; i-- )
        percolateDown( i );
}
    
/**
 * Internal method to percolate down in the heap.
 * hole is the index at which the percolate begins.
 */
template <class T>
void MaxBinaryHeap<T>::percolateDown( int hole ) {
    debugger("percolate down...");

	// Only try to percolate down internal nodes
	if ((2*hole+1) <= currentSize ) {
	    
	    // Find the maximum value of the two children of this node.
	    int max = maximum(hole);

	    // If this value is greater than the current value, then we need to move
	    // our current value down the heap.
	    if (array[max] > array[hole]) {
	        swap(array[hole], array[max]);

	        // This part is recursive and allows us to continue percolating
	        // down the element in question.
	        percolateDown(max);
	    }
	}
	// hole only has a left child
    else if ( currentSize == 2*hole ) {
        if (array[2*hole] > array[hole]) {
            swap(array[hole], array[2*hole]);
        }
    }

}

template <class T>
int MaxBinaryHeap<T>::maximum( int hole ) {

    if ( array[2*hole] > array[2*hole+1] ) {
        return 2*hole;
    }
    else {
        return 2*hole+1;
    }

}

template <class T>
void MaxBinaryHeap<T>::debugger( string message ) {

	if (debug) {
		cout << message << endl;
	}
}

 #endif