#include "RPN.h"
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

RPN::RPN( string rpn_expression ) {
	tokens = rpn_expression;
}

RPN::~RPN() {

}

void RPN::calculate() {

	int length = tokens.size();
	for (int i=0; i<length; i++) {
		Stack Numbers;			
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

}