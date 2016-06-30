/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: lab3
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "Stack.h"

using namespace std;

int main( int argc, char * argv[] ) {
	
	cout << "Reverse Polish Notation Evaluation:\n";

	if ( argc != 2 ) {
		cout << "usage: ./a.out <rpn.txt>" << endl;
	}
	else {
		ifstream InFile (argv[1]);
		if (InFile.is_open()) {
			Stack<int> Numbers;
			char c;
			while (InFile.get(c)) {
				if (isdigit(c)) {
					try {
						Numbers.push(c-48);		// convert from ASCII to actual number !!
						Numbers.print();
					}
					catch (overflow_error& e) {
						cerr << "Overflow Exception: " << e.what() << endl;
					}
					catch (underflow_error& e) {
						cerr << "Underflow Exception: " << e.what() << endl;
					}
				}
				else if (isblank(c)) {}
				else {
					cout << "Operator: " << c << endl;
					try {
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
	                catch (overflow_error& e) {
						cerr << "Overflow Exception: " << e.what() << endl;
					}
					catch (underflow_error& e) {
						cerr << "Underflow Exception: " << e.what() << endl;
					}
				}
			}
			try {
			cout << "Result: " << Numbers.top() << endl << endl;
			}
			catch (underflow_error& e) {
						cerr << "Underflow Exception: " << e.what() << endl;
			}
		}
		InFile.close();
	}
	
	// Double Stack
	cout << "\nStack of Type <double>" << endl;
	Stack<double> doubleStack;
	cout << "Pushing onto stack..." << endl;
	try {
		doubleStack.push(5.2);
		doubleStack.print();
		doubleStack.push(100.33);
		doubleStack.print();
		doubleStack.push(.02);
		doubleStack.print();
		doubleStack.push(4.7);
		doubleStack.print();
		doubleStack.push(2.3);
		doubleStack.print();
		doubleStack.push(.05);
		doubleStack.print();
	}
	catch (overflow_error& e) {
		cerr << "Overflow Exception: " << e.what() << endl;
	}
	catch (underflow_error& e) {
		cerr << "Underflow Exception: " << e.what() << endl;
	}

	// String Stack 
	cout << "\nStack of Type <string>" << endl;
	Stack<string> stringStack;
	stringStack.push("hey");
	stringStack.push("hi");
	stringStack.push("hello");
	stringStack.print();
	cout << "Top: " << stringStack.top() << endl;
	cout << "Popping off stack..." << endl;
	try {
		stringStack.pop();
		stringStack.print();
		stringStack.pop();
		stringStack.print();
		stringStack.pop();
		stringStack.print();
		stringStack.pop();
	}
	catch (underflow_error& e) {
		cerr << "Underflow Exception: " << e.what() << endl;
	}
	catch (overflow_error& e) {
		cerr << "Overflow Exception: " << e.what() << endl;
	}
	
	return 0;
}