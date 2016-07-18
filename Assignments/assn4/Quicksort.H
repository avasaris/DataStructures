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
 #include <stdexcept>
 #include <algorithm>
 using namespace std;

vector<int> quicksort( vector<int> v, string );
void quicksort( vector<int>& v, int left, int right, string pivotSelection );
int pickPivot( vector<int> v, int left, int right, string pivotSelection );
void print( vector<int> );
int findMedian(int, int, int);
int select( vector<int> v, int k );

vector<int> quicksort( vector<int> v, string pivotSelection ) {

 	// Base case: If there are 1 or zero elements to sort, 
 	// partition is already sorted
 	if ( v.size() > 1 ) {
 		int left = 0;
 		int right = v.size()-1;
 		quicksort( v, left, right, pivotSelection );
 		return v;
 	}
 	else {
 		return v;
 	}

 }

 void quicksort( vector<int>& v, int left, int right, string pivotSelection ) {

 	int i = left;
 	int j = right;
 	int size = right - left;

 	if (size > 1) {

 		int pivot = pickPivot(v, left, right, pivotSelection);

	 	// Partition 
	 	while (i <= j) {
	 		while ( v[i] < pivot )
	 			i++;
	 		while ( v[j] > pivot )
	 			j--;
	 		if (i <= j) {
	 			swap( v[i], v[j] );
	 			i++;
	 			j--;
	 		}
	 	}

	 	// Recursion
	 	if (left < j)
	 		quicksort(v, left, j, pivotSelection);
	 	if (i < right)
	 		quicksort(v, i, right, pivotSelection);

	}

}

int pickPivot( vector<int> v, int left, int right, string pivotSelection ) {

	string random = "random", median = "median_three", qselect = "random_qselect", dqsort = "deterministic_qsort";

	if ( pivotSelection == random ) {
		int randPivot = v[rand() % v.size()];
		return randPivot;
	}
	else if (pivotSelection == median) {
		int m = findMedian( v[rand() % v.size()], v[rand() % v.size()], v[rand() % v.size()] );
		return m;
	}
	else if (pivotSelection == qselect) {
		//int q = select(v, (1+v.size())/2 );
		int q = select(v, v.size()-1 );
		//cout << "q: " << q << endl;
		return q;
	}
	else if (pivotSelection == dqsort) {
		return -1;
	}
	else {
		// middle
		return v[(left+right)/2];
	} 

}

int findMedian( int a, int b, int c ) {

	vector<int> vec;
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);

	sort(vec.begin(), vec.end());

	return vec[1];
}

int select( vector<int> v, int k ) {

	if ( !v.empty() && (k>=1 && k<=v.size()) ) {

		int pivot = v[rand() % v.size()];
		vector<int> L, E, G;
		for (int i=0; i<v.size(); i++) {
			if (v[i] < pivot) {
				L.push_back(v[i]);
			}
			else if (v[i] > pivot) {
				G.push_back(v[i]);
			}
			else {
				E.push_back(v[i]);
			}
		}
		print(v);
		cout << "k: " << k << endl;
		cout << "L.size(): " << L.size() << endl;
		cout << "E.size(): " << E.size() << endl;
		cout << "G.size(): " << G.size() << endl;
		int lengthL = L.size();
		int lengthE = E.size();
		int lengthG = G.size();
		if (k <= lengthL) {
			return select(L,k);
		}
		else if (k <= (lengthL+lengthE)) {
			return pivot;
		}
		else {
			return select(G,k-(L.size()+E.size()));
		}
	}
	else {
		throw underflow_error("Vector is empty");
	} 

}

void print( vector<int> v ) {

	int length = v.size();
	for (int i=0; i<length; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

}


