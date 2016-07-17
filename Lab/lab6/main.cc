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
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <string>
#include "BinaryHeap.h"
#include "MaxBinaryHeap.h"

using namespace std;

template <typename T>
void heapsort1( vector<T>& );
template <typename T>
void print( vector<T>& );
void heapsort2( vector<int>& );

int main() {
    
    vector<int> v;
    v.push_back(10);
    v.push_back(6);
    v.push_back(8);
    v.push_back(4);
    v.push_back(2);
    v.push_back(12);
    v.push_back(14);
    
    // Testing MinHeap
    cout << "\nTesting Min Heap:" << endl;
        BinaryHeap pq(v);
        pq.print( );
        pq.insert(5);
        pq.print();
        pq.insert(6);
        pq.print();
        pq.insert(20);
        pq.print();
        pq.insert(16);
        pq.print();
        pq.insert(9);
        pq.print();

        // Testing findMin function 
            cout << "Minimum: " << pq.findMin() << endl;

            BinaryHeap emptyHeap;
            try {
                cout << "Minimum: " << emptyHeap.findMin() << endl;
            }
            catch (underflow_error(e)) {
                cout << "Caught Error: " << e.what() << endl;
            }

    // Testing MaxBinaryHeap<int>
    cout << "\nTesting Max Heap <int> :" << endl;

        MaxBinaryHeap<int> maxHeap(v);
        maxHeap.print();
        maxHeap.print( );
        maxHeap.insert(5);
        maxHeap.print();
        maxHeap.insert(6);
        maxHeap.print();
        maxHeap.insert(20);
        maxHeap.print();
        maxHeap.insert(16);
        maxHeap.print();
        maxHeap.insert(9);
        maxHeap.print();

        // Testing findMax function 
            cout << "Maximum: " << maxHeap.findMax() << endl;

            MaxBinaryHeap<int> emptyMaxHeap;
            try {
                cout << "Maximum: " << emptyMaxHeap.findMax() << endl;
            }
            catch (underflow_error(e)) {
                cout << "Caught Error: " << e.what() << endl;
            }

    // Testing MaxBinaryHeap<string>
    cout << "\nTesting Max Heap <string>:" << endl;

        MaxBinaryHeap<string> stringHeap;
        stringHeap.insert("spicy");
        stringHeap.print();
        stringHeap.insert("alpha");
        stringHeap.print();
        stringHeap.insert("pasta");
        stringHeap.print();
        stringHeap.insert("goldfish");
        stringHeap.print();
        stringHeap.insert("water");
        stringHeap.print();
        stringHeap.insert("phone");
        stringHeap.print();
        stringHeap.insert("charger");
        stringHeap.print();
        stringHeap.insert("fork");
        stringHeap.print();
    
    // Testing Heapsort
        vector<int> unsortedVector;
        unsortedVector.push_back(10);
        unsortedVector.push_back(6);
        unsortedVector.push_back(8);
        unsortedVector.push_back(4);
        unsortedVector.push_back(2);
        unsortedVector.push_back(12);
        unsortedVector.push_back(14);

        cout << "\nBefore: ";
        print(unsortedVector);
        cout << "\nMax Heap Sort:" << endl;
        heapsort1(unsortedVector);

        vector<int> vector2;
        vector2.push_back(10);
        vector2.push_back(6);
        vector2.push_back(8);
        vector2.push_back(4);
        vector2.push_back(2);
        vector2.push_back(12);
        vector2.push_back(14);

        cout << "\nMin Heap Sort:" << endl;
        heapsort2(vector2);
        cout << "Final: ";
        print(vector2);
    
    return 0;
}

template <typename T>
void heapsort1( vector<T>& unsortedVector ) {
    
    // create heap from unsorted vector
    MaxBinaryHeap<T> h(unsortedVector);
    int length = h.getSize();

    // remove from heap one by one and store in original array
    for (int i=0; i<length; i++) {
         unsortedVector[i] = h.findMax();
         h.deleteMax();
         cout << "Iteration " << i << ": ";
         print(unsortedVector);
    }
}

void heapsort2( vector<int>& vector2 ) {

    // create heap from unsorted vector
    BinaryHeap h(vector2);
    int length = h.getSize();

    // remove from heap one by one and store in original array
    for (int i=0; i<length; i++) {
         vector2[i] = h.findMin();
         h.deleteMin();
         cout << "Iteration " << i << ": ";
         print(vector2);
    }

}

template <typename T>
void print( vector<T>& v ) {

    int length = v.size();
    for (int i=0; i<length; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

}





