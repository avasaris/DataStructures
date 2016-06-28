#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include "Stack.h"

using namespace std;

int main( int argc, char * argv[] ) {

	cout << "\nTesting Stack Class:" << endl;
	Stack MyStack; 

	MyStack.push(5);
	MyStack.push(10);
	MyStack.push(2);
	MyStack.push(7);
	MyStack.push(8);
	MyStack.print();
	cout << "top: " << MyStack.top() << endl << endl;
	MyStack.pop();
	MyStack.print();
	cout << "top: " << MyStack.top() << endl << endl;
	MyStack.pop();
	MyStack.pop();
	MyStack.print();
	cout << "top: " << MyStack.top() << endl << endl;
	
	cout << "Reverse Polish Notation Evaluation:\n";

	if ( argc != 2 ) {
		cout << "usage: ./a.out <rpn.txt>" << endl;
	}
	else {
		ifstream InFile (argv[1]);
		if (InFile.is_open()) {
			Stack Numbers;
			char c;
			while (InFile.get(c)) {
				if (isdigit(c)) {
					Numbers.push(c-48);		// convert from ASCII to actual number !!
					Numbers.print();
				}
				else if (isblank(c)) {}
				else {
					cout << "Operator: " << c << endl;
					// pop two numbers off the stack                 
                        int a = Numbers.top();                 
                        Numbers.pop();                 
                        int b = Numbers.top();                 
                        Numbers.pop();                 
                    // evaluate and push the result back
                        switch (c) {
                        	case '+': 
                        		Numbers.push(a + b); 
                        		break;                     
                            case '-': 
                            	Numbers.push(b - a); 
                            	break;                     
                            case '*': 
                            	Numbers.push(b * a); 
                            	break;                     
                            case '/': 
                            	Numbers.push(b / a); 
                            	break;
                        }
                    Numbers.print();
				}
			}
			cout << "Result: " << Numbers.top() << endl << endl;
		}
		InFile.close();
	}
	

	return 0;
}