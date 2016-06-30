#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
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
	
	// Double Stack
	cout << "\nStack of Type <double>" << endl;
	Stack<double> doubleStack;
	doubleStack.push(5.2);
	doubleStack.push(100.33);
	doubleStack.push(.02);
	doubleStack.print();
	cout << "Top: " << doubleStack.top() << endl;
	doubleStack.pop();
	doubleStack.print();
	cout << "Top: " << doubleStack.top() << endl;

	// Char Stack
	cout << "\nStack of Type <char>" << endl;
	Stack<char> charStack;
	charStack.push('a');
	charStack.push('b');
	charStack.push('z');
	charStack.print();
	cout << "Top: " << charStack.top() << endl;
	charStack.pop();
	charStack.print();
	cout << "Top: " << charStack.top() << endl;

	// Short Stack 
	cout << "\nStack of Type <short>" << endl;
	Stack<short> shortStack;
	shortStack.push(5);
	shortStack.push(100);
	shortStack.push(2);
	shortStack.print();
	cout << "Top: " << shortStack.top() << endl;
	shortStack.pop();
	shortStack.print();
	cout << "Top: " << shortStack.top() << endl;

	/* String Stack 
	cout << "\nStack of Type <string>" << endl;
	Stack<string> stringStack;
	stringStack.push("hey");
	stringStack.push("hi");
	stringStack.push("hello");
	stringStack.print();
	cout << "Top: " << stringStack.top() << endl;
	stringStack.pop();
	stringStack.print();
	cout << "Top: " << stringStack.top() << endl;
	*/
	return 0;
}