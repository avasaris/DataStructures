/*
 * node.h
 * cs014 Summer 2016
 * assn 1
 */

#ifndef __NODE_H_
#define __NODE_H_

class Node {
  	friend class MyList;
	private:
	  	Node* next;
	  	char value;
	public:
		Node();
		Node(char value);
		~Node();
		Node* get_next() const;
		char get_value() const;
		void set_next(Node*);
		void set_value(char value);
};

#endif /* NODE_H_ */

