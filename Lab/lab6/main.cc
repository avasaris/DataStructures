/**
 * cs014_10spr lab 7
 * main.cc for BinaryHeap
 */

#include "BinaryHeap.H"
#include "MaxBinaryHeap.H"

// Implement heapsort here
template <typename T>
void heapsort1( vector<T> );
template <typename T>
void print( vector<T>& );


int main() {

	vector<int> v;
	v.push_back(10);
	v.push_back(6);
	v.push_back(8);
	v.push_back(4);
	v.push_back(2);
	v.push_back(12);
	v.push_back(14);

	BinaryHeap pq(v);
	pq.print( );

	// Add additional tests for new BinaryHeap functionality here
	// Add additional tests for heapsort here. You should use the 
	// print function to view the heap at each step of the sort.


	cout << endl << "============== Min Heap Test ==============" << endl << endl;

	BinaryHeap b(100);

	b.insert(7);
	b.insert(7);
	b.insert(7);
	b.insert(1);
	b.insert(9);
	b.insert(2);
	b.insert(4);
	b.insert(3);
	b.insert(6);
	b.insert(10);
	b.insert(12);
	b.insert(14);
	b.insert(5);
	b.insert(8);
	b.insert(11);
	b.insert(13);
	b.insert(15);

	b.print();

	cout << "\t1st Min = " << b.findMin() << endl;


	b.deleteMin();

	cout << "\t2nd Min = " << b.findMin() << endl;


	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();
	b.deleteMin();

	b.print();

	cout << "\tLast Min = " << b.findMin() << endl;

	b.insert(99);
	b.insert(1);

	b.print();


	cout << endl << "============== Max Heap Test ==============" << endl << endl;

	MaxBinaryHeap<int> b2;

	b2.insert(7);
	b2.insert(7);
	b2.insert(7);
	b2.insert(1);
	b2.insert(9);
	b2.insert(2);
	b2.insert(4);
	b2.insert(3);
	b2.insert(6);
	b2.insert(10);
	b2.insert(12);
	b2.insert(14);
	b2.insert(5);
	b2.insert(8);
	b2.insert(11);
	b2.insert(13);
	b2.insert(15);

	b2.print();

	cout << "\t1st Max = " << b2.findMax() << endl;


	b2.deleteMax();

	cout << "\t2nd Max = " << b2.findMax() << endl;


	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();
	b2.deleteMax();

	b2.print();

	cout << "\tLast Max = " << b2.findMax() << endl;

	b2.insert(99);
	b2.insert(1);

	b2.print();


	cout << endl << "============== HeapSort Test ==============" << endl << endl;

	
	vector<int> s;

	s.push_back(7);
	s.push_back(7);
	s.push_back(7);
	s.push_back(1);
	s.push_back(9);
	s.push_back(2);
	s.push_back(4);
	s.push_back(3);
	s.push_back(6);
	s.push_back(10);
	s.push_back(12);
	s.push_back(14);
	s.push_back(5);

	s.push_back(8);
	s.push_back(11);
	s.push_back(13);
	s.push_back(15);

	heapsort1(s);

  return 0;
}

template <typename T>
void heapsort1( vector<T> unsortedVector ) {
    
    // create heap from unsorted vector
    MaxBinaryHeap<T> h(unsortedVector);
    int length = h.getSize();

    // remove from heap one by one and store in original array
    for (int i=length; i>0; i--) {
         unsortedVector[i-1] = h.findMax();
         h.deleteMax();
    }
    print(unsortedVector);
}

template <typename T>
void print( vector<T>& v ) {

    int length = v.size();
    for (int i=0; i<length; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

}
