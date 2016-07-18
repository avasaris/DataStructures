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
 * Filename : BinaryHeap.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

class BinaryHeap
{
public:
    BinaryHeap( int capacity = 100 ) {
        currentSize=0;
        array[capacity];
    }
    BinaryHeap( const vector<int> & items )
    :  currentSize( items.size( ) ), array( items.size( ) + 10 ) {
        for( unsigned int i = 0; i < items.size( ); i++ ) {
            array[ i + 1 ] = items[ i ];
        }
        buildHeap( );
    }
    
    bool isEmpty( ) const {

        return (currentSize==0);

    }

    const int& findMin( ) const {

        if (currentSize==0) {
            throw underflow_error("Heap is Empty");
        }
        return array[1];

    }

    void insert( const int & x ) {
        int value = x;
        insert(value);
    }
    
    /**
     * Prints the elements of the underlying array in the BinaryHeap
     */
    void print( ) const {
        for( int i = 1; i < currentSize + 1; i++ )
            cout << array[i] << " ";
        cout << endl;
    }
    
    /**
     * Remove the minimum item and place it in minItem.
     * Exits the program if empty.
     */
    void deleteMin( ) {
        
        if( isEmpty( ) ) {
            // throw UnderflowException( );
            cerr << "Heap is empty" << endl;
            exit(1);
        }
        array[ 1 ] = array[ currentSize-- ];
        percolateDown( 1 );
    }

    int getSize() {
        return currentSize;
    }
    
private:
    int currentSize;   // Number of elements in heap
    vector<int> array; // The heap array

    void percolateUp( int hole ) {

        // can only percolate up if the hole isn't the root
        if ( hole > 1 ) {

            // check if current node has smaller value than its parent
            if ( array[hole/2] > array[hole] ) {
                // move up one level
                swap( array[hole], array[hole/2] );

                // call recusively to see if it needs to be done again
                percolateUp( hole/2 );
            }
        }

    }
    
    void insert( int& newItem ) {

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
    void buildHeap( ) {

        // Only try to percolate down internal nodes
        for( int i = currentSize / 2; i > 0; i-- )
            percolateDown( i );
    }
    
    /**
     * Internal method to percolate down in the heap.
     * hole is the index at which the percolate begins.
     */
    void percolateDown( int hole ) {
        
        // Only try to percolate down internal nodes
        if ((2*hole+1) <= currentSize ) {
            
            // Find the minimum value of the two children of this node.
            int min = minimum(hole);

            // If this value is less than the current value, then we need to move
            // our current value down the heap.
            if (array[hole] > array[min]) {
                swap(array[hole], array[min]);

                // This part is recursive and allows us to continue percolating
                // down the element in question.
                percolateDown(min);
            }
        }

        // hole only has a left child
        else if ( currentSize == 2*hole ) {
            if (array[hole] > array[2*hole]) {
                swap(array[hole], array[2*hole]);
            }
        }
    
    }

    int minimum( int hole ) {

        if ( array[2*hole] > array[2*hole+1] ) {
            return 2*hole+1;
        }
        else {
            return 2*hole;
        }

    }
};