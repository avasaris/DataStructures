#ifndef __STACK_H_
#define __STACK_H_

#define CAPACITY 25

class Stack {
	public:
		Stack();
		~Stack();
		void push(const int& x); 	// adds a new element x at the top of the stack.

		int& top(); 				// Returns a reference to the next(top) element in the stack,
									// if the stack is not already empty.

		void pop();					// Removes the element on top of the stack, reducing the 
									// stack's size by 1 if the stack is not already empty.

		bool is_empty() const; 		// tests whether the stack size is zero Primarily used to ensure 
									// that a pop() or top() operation is not performed on an empty 
									// instance of a Stack. Returns true if stack is empty, false 
									// otherwise

		int size();
		void print();

	private:
		int t;
		int S[CAPACITY];

};

#endif