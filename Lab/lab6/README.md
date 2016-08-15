Lab 6: Binary Heap (Min-heap, Max-heap implementation), Templates, and Heapsort
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

In this lab you will complete the following tasks.

* Implement the **percolateDown** function for the BinaryHeap class.
* Implement the **isEmpty** function, **findMin** function, and **insert** function for the BinaryHeap class.
* Convert the BinaryHeap class from a min-heap into a max-heap.
* **Templatize** the BinaryHeap class.
* Verify that the BinaryHeap class can handle two types, e.g., strings and ints.
* Implement the in-place **heapsort** algorithm presented in class, using your max-heap as the underlying heap data structure. Test heapsort on input of two types. 

Heapsort
--------
To sort comparable elements in decreasing order using heapsort, first build a min-heap. Conversely, to sort elements in increasing order using heapsort, build a max-heap first. You should implement a heapsort function in the main.cc that takes as a parameter a reference to an unsorted vector of elements and constructs a heap from the vector (use the linear-time build_heap algorithm shown in lecture), then sorts the elements in increasing order using heapsort. You may add additional helper functions for your heapsort function in the main.cc as necessary.

Testing
-------
You should test your BinaryHeap class functionality on two types of input. In addition you should test your insert function on heaps with different parent-child relationships for the last element, i.e. parent and no sibling, parent and one sibling. If you finish everything, templatize your heapsort function.
