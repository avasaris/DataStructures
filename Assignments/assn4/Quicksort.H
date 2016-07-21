/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: assn4
 * Filename : Quicksort.H
 *
 * Sources: 
 * https://en.wikipedia.org/wiki/Quicksort
 * https://en.wikipedia.org/wiki/Quickselect
 * https://en.wikipedia.org/wiki/Median_of_medians
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

 #include <iostream>
 #include <vector>
 #include <string>
 #include <cstdlib>
 #include <ctime>
 #include <cmath>
 #include <stdexcept>
 #include <algorithm>
 using namespace std;

template <typename T>
void printStats(vector<T>, int&, int&, int& );
template <typename T>
vector<T> quicksort( vector<T> v, string );
template <typename T>
int partition(vector<T>& v, int left, int right, T pivot, int&, int&);
template <typename T>
void quicksort( vector<T>& v, int left, int right, string pivotSelection, int&, int&, int& );
template <typename T>
T pickPivot( vector<T>& v, int left, int right, string pivotSelection, int&, int&, int& );
template <typename T>
void print( vector<T> );
template <typename T>
T findMedian(T, T, T, int&);
template <typename T>
int select( vector<T>& v, int left, int right, int k, string, int&, int&, int&);
template <typename T>
int selectPartition( vector<T>& v, int left, int right, int pivotIndex, int&, int& );
template <typename T>
int deterministicPivot(vector<T>& v, int left, int right, int&, int&, int&);
template <typename T>
int partition5(vector<T>& v);

template <typename T>
vector<T> quicksort( vector<T> v, string pivotSelection ) {

	// Test Stats
	int comparisions = 0;
	int recursiveCalls = 0;
	int dataMovements = 0;
 	// Base case: If there are 1 or zero elements to sort, 
 	// partition is already sorted
 	if ( v.size() > 1 ) {
 		int left = 0;
 		int right = v.size()-1;
 		quicksort( v, left, right, pivotSelection, comparisions, recursiveCalls, dataMovements );
 		printStats(v, comparisions, recursiveCalls, dataMovements);
 		return v;
 	}
 	else {
 		printStats(v, comparisions, recursiveCalls, dataMovements);
 		return v;
 	}

 }

template <typename T>
int partition(vector<T>& v, int left, int right, T pivot, int& comparisions, int& dataMovements) {

 	bool done = false;
	int i = left;
 	int j = right;


 	while (!done) {
 		comparisions++;
 		while ( v[i] < pivot ) {
 			comparisions++;
 			i++;
 		}
 		comparisions++;
 		while ( v[j] > pivot ) {
 			comparisions++;
 			j--;
 		}
 		comparisions++;
 		if (i >= j) {
 			done = true;
 		}
 		else {
 			dataMovements++;
 			swap( v[i], v[j] );
 			i++;
 			j--;
 		}
 		comparisions++;
 	}
 	comparisions++;
 	return j;

}

template <typename T>
void quicksort( vector<T>& v, int left, int right, string pivotSelection, int& comparisions, int& recursiveCalls, int& dataMovements ) {

	recursiveCalls++;

	comparisions++;
 	if (left >= right) return;
 	if (is_sorted(v.begin(), v.end())) return;
 	comparisions++;

	T pivot = pickPivot(v, left, right, pivotSelection, comparisions, recursiveCalls, dataMovements);
 	int j = partition(v, left, right, pivot, comparisions, dataMovements);

 	comparisions++;
 	if (left < j) {
 		quicksort(v, left, j, pivotSelection, comparisions, recursiveCalls, dataMovements);
 	}
 	comparisions++;
 	if ((j+1) < right) {
 		quicksort(v, j+1, right, pivotSelection, comparisions, recursiveCalls, dataMovements);
 	}

 	return;

}

template <typename T>
T pickPivot( vector<T>& v, int left, int right, string pivotSelection, int& comparisions, int& recursiveCalls, int& dataMovements ) {

	string random = "random", median = "median_three", qselect = "random_qselect", dqsort = "deterministic_qsort", first = "first";
	int size = right - left;	// this is very important! narrows selection

	if (pivotSelection == first) {
		T f = v[left];
		return f;
	}
	else if ( pivotSelection == random ) {
		T randPivot = v[left+(rand() % size)];
		return randPivot;
	}
	else if (pivotSelection == median) {
		T m = findMedian( v[left+(rand() % size)], v[left+(rand() % size)], v[left+(rand() % size)], dataMovements );
		return m;
	}
	else if (pivotSelection == qselect) {
		T q = v[select(v, left, right,(left+(size/2)), pivotSelection, comparisions, recursiveCalls, dataMovements )];
		return q;
	}
	else if (pivotSelection == dqsort) {
		T dq = v[select(v, left, right,(left+(size/2)), pivotSelection, comparisions, recursiveCalls, dataMovements )];
		return dq;
	}
	else {
		// middle
		return v[(left+right)/2];
	} 

}

template <typename T>
T findMedian( T a, T b, T c, int& dataMovements ) {

	vector<T> vec;
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);

	dataMovements++;
	sort(vec.begin(), vec.end());

	return vec[1];
}

template <typename T>
int select( vector<T>& v, int left, int right, int k, string pivotSelection, int& comparisions, int& recursiveCalls, int& dataMovements ) {

	string qselect = "random_qselect";
	recursiveCalls++;

	// Base Case: the list only contains 1 element
	if (left == right) {
		//return v[left];	// return that element
		return left;
	}

	int pivotIndex;
	comparisions++;
	if (pivotSelection == qselect) {
		pivotIndex = (left + floor(rand() % (right - left)));	// Quickselect
	}
	else {
		pivotIndex = deterministicPivot(v, left, right, comparisions, recursiveCalls, dataMovements);	// Deterministic Quickselect
	}
	pivotIndex = selectPartition(v, left, right, pivotIndex, comparisions, dataMovements);	 // pivot index is in it's final sorted position
	
	comparisions++;
	if (k == pivotIndex) {
		//return v[k];
		return k;
	}
	else if (k < pivotIndex) {
		comparisions++;
		return select(v, left, pivotIndex - 1, k, pivotSelection, comparisions, recursiveCalls, dataMovements);
	}
	else {
		comparisions++;
		return select(v, pivotIndex + 1, right, k, pivotSelection, comparisions, recursiveCalls, dataMovements);
	}

}

template <typename T>
int selectPartition( vector<T>& v, int left, int right, int pivotIndex, int& comparisions, int& dataMovements ) {

	T pivotValue = v[pivotIndex];
	dataMovements++;
	swap(v[pivotIndex], v[right]); 	// move pivot to the end
	int storeIndex = left;
	for (int i=left; i<right; i++) {
		comparisions+=2;
		if (v[i] < pivotValue) {
			dataMovements++;
			swap(v[storeIndex], v[i]);
			storeIndex++;
		}
	}
	comparisions++;
	dataMovements++;
	swap(v[right], v[storeIndex]);	// move pivot to its final place
	return storeIndex;

}

template <typename T>
int deterministicPivot(vector<T>& v, int left, int right, int& comparisions, int& recursiveCalls, int& dataMovements) {

	// for 5 or less elements just get median
	comparisions++;
    if ( (right-left) < 5) { 
         return partition5(v);
    }
    // otherwise move the medians of five-element subgroups to the first n/5 positions
    for (int i=left; i<=right; i+=5) {
    	comparisions+=2;
        // get the median of the i'th five-element subgroup
        int subRight = i + 4;
        if (subRight > right) {
            subRight = right;
        }
        int median5 = partition5(v);
        dataMovements++;
        swap( v[median5], v[left + floor((i - left)/5)]);
    }
    // compute the median of the n/5 medians-of-five
    return select(v, left, left + ceil((right - left) / 5) - 1, left + (right - left)/10, "deterministic_qsort", comparisions, recursiveCalls, dataMovements);

}

template <typename T>
int partition5(vector<T>& v) {

	if (v.empty()) return 0;
	else {
		sort(v.begin(), v.end());
		if (v.size() % 2 == 0)
			//return (v[(v.size()+1)/2]);
			return (v.size()+1)/2;
		else 
			//return v[v.size()/2];
			return v.size()/2;
	}

}


