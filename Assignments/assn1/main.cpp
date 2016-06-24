#include <iostream>
#include <string>
#include "MyList.h"
#include "Node.h"

using namespace std;

int main() {

	//string str = "string one";
	//MyList courtney(str);

	MyList katie("courtney");
	katie.push_back('8');
	katie.push_front('5');
	katie.pop_front();
	katie.pop_back();

	MyList list3(katie);

	//katie.swap(1, 12);
	katie.insert_at_pos(11, 'B');
	katie.print();
	katie.reverse();
	katie.print();

	cout << "Found: " << katie.find('t') <<endl;
	return 0;

}