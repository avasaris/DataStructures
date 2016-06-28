#ifndef __RPN_H_
#define __RPN_H_

#include <string>
using namespace std;

class RPN {
public:
	RPN( string );
	~RPN();
	void calculate();
private:
	string tokens;
};

#endif