 /**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: lab2
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include "MyList.h"

using namespace std;

int main() {

	// Default Constructor
	cout << "\n\nOperations using Default Constructor Instantiation:" << endl;
	MyList list1;
	list1.push_back(' ');
	list1.push_back('S');
	list1.push_back('n');
	list1.push_back('o');
	list1.push_back('w');
	list1.push_back('!');
	list1.print();
	list1.pop_back();
	list1.print();
	list1.push_front('n');
	list1.push_front('h');
	list1.push_front('o');
	list1.push_front('J');
	list1.push_front('!');
	list1.print();
	list1.pop_front();
	list1.print();
	list1.insert_at_pos(1, '!');
	list1.print();
	list1.swap(1, 6);
	list1.print();
	MyList query1("Snow");
	MyList query2("Stark");
	MyList query3("s");
	MyList query4("o");
	cout << "Looking for '!'...Found at location: " << list1.find('!') << endl;
	cout << "Looking for 'Snow'...Found at location: " << list1.find(query1) << endl;
	cout << "Looking for 'Stark'...Found at location: " << list1.find(query2) << endl;
	cout << "Looking for 's'...Found at location: " << list1.find(query3) << endl;
	cout << "Looking for 'o'...Found at location: " << list1.find(query4) << endl;
	list1.print();
	list1.reverse();
	list1.print();
	
	// String Object Passed
	cout << "\n\nOperations using String Object Passed to Constructor Instantiation:" << endl;
	string name = "Sansa Stark";
	MyList list2(name);
	list2.print();
	list2.push_back('!');
	list2.print();
	list2.pop_back();
	list2.print();
	list2.push_front('!');
	list2.print();
	list2.pop_front();
	list2.print();
	list2.insert_at_pos(1, '!');
	list2.print();
	list2.swap(1, 7);
	list2.print();
	cout << "Looking for '!'...Found at location: " << list2.find('!') << endl;
	cout << "Looking for 'Snow'...Found at location: " << list2.find(query1) << endl;
	cout << "Looking for 'Stark'...Found at location: " << list2.find(query2) << endl;
	cout << "Looking for 's'...Found at location: " << list2.find(query3) << endl;
	cout << "Looking for 'o'...Found at location: " << list2.find(query4) << endl;	list2.print();
	list2.reverse();
	list2.print();

	// Char * Object Passed
	cout << "\n\nOperations using Char* Object Passed to Constructor Instantiation:" << endl;
	MyList list3("Daenerys Targaryen");
	list3.print();
	list3.push_back('!');
	list3.print();
	list3.pop_back();
	list3.print();
	list3.push_front('!');
	list3.print();
	list3.pop_front();
	list3.print();
	list3.insert_at_pos(1, '!');
	list3.print();
	list3.swap(1, 9);
	list3.print();
	cout << "Looking for '!'...Found at location: " << list3.find('!') << endl;
	cout << "Looking for 'Snow'...Found at location: " << list3.find(query1) << endl;
	cout << "Looking for 'Stark'...Found at location: " << list3.find(query2) << endl;
	cout << "Looking for 's'...Found at location: " << list3.find(query3) << endl;
	cout << "Looking for 'o'...Found at location: " << list3.find(query4) << endl;
	list3.print();
	list3.reverse();
	list3.print();

	// MyList Object Passed
	cout << "\n\nOperations using MyList Object Passed to Constructor Instantiation:" << endl;
	MyList list4("Arya Stark");
	MyList list5(list4);
	list5.print();
	list5.push_back('!');
	list5.print();
	list5.pop_back();
	list5.print();
	list5.push_front('!');
	list5.print();
	list5.pop_front();
	list5.print();
	list5.insert_at_pos(1, '!');
	list5.print();
	list5.swap(1, 3);
	list5.print();
	cout << "Looking for '!'...Found at location: " << list5.find('!') << endl;
	cout << "Looking for 'Snow'...Found at location: " << list4.find(query1) << endl;
	cout << "Looking for 'Stark'...Found at location: " << list4.find(query2) << endl;
	cout << "Looking for 's'...Found at location: " << list4.find(query3) << endl;
	cout << "Looking for 'o'...Found at location: " << list4.find(query4) << endl;
	list5.print();
	list5.reverse();
	list5.print();
	
	
	// Assignment Operator Overload
	cout << "\n\nAssignment Operator Overload:" << endl;
	MyList list6("Brandon Stark");
	MyList list7("Eddard Stark");
	cout << "List 6: ";
	list6.print();
	cout << "List 7: ";
	list7.print();
	cout << "List 6 = List 7" << endl;
	list6 = list7;
	cout << "List 6: ";
	list6.print();
	cout << "List 7: ";
	list7.print();
	


	// Bracket Operator Overload
	cout << "\n\nBracket [] Operator Overload:" << endl;
	cout << "List 7: ";
	list7.print();
	cout << "list7[4]: " << list7[4] << endl;
	cout << "list7[100]: ";
	cout << list7[100];
	
	
	// Addition Operator Overload
	cout << "\n\nAddition Operator Overload:" << endl;
	MyList list8("Robb Stark");
	MyList list9("Catherine Stark");
	cout << "List 8: ";
	list8.print();
	cout << "List 9: ";
	list9.print();
	cout << "List 8 + List 9 = " << endl << "Adds the elements of List 9 to List 8 and deletes List 9" << endl;
	list8 + list9;
	cout << "List 8: ";
	list8.print();
	cout << "List 9: ";
	list9.print();
	
	

	return 0;

}
