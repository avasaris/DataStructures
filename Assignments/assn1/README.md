Assignment 1
------------
------------

You will implement a singly-linked list of characters called MyList. MyList has a head pointer, but you may NOT add a tail pointer. A node in your list has two data members, a char type variable called value and a pointer of type char called next which points to the next node positioned in the list.

MyList
------

You must implement MyList. Your source file must be called MyList.cc. The descriptions of the
required functionality is below. A reasonable plan of attack is to implement and test the more
straight-forward functions prior to working on the more challenging parts. Your goal should be to
complete a portion of the program each day.

Constructors and Destructor
---------------------------

  * MyList(); <br />
  		Default constructor.
  * MyList(const MyList& str);
       <br />Constructs a list from a passed in MyList object, i.e. MyList l1(l2);
  * MyList(const string& str);
       <br />Constructs a list from a passed in string object, i.e. string name = "Jake"; MyList l1(name);
  * MyList(const char* str);
       <br />Constructs a list from a passed in string literal, i.e. MyList l1("Hello World");
  * ~MyList();
       <br />Destructor.
      
Mutators
--------

  * void push front(char value);
       <br />Inserts value at the front of the list.
  * void push back(char value);
       <br />Inserts value at the back of the list.
  * void pop front();
       <br />Removes the front item from the list.
  * void pop back();
       <br />Removes the last item from the list.
  * void swap(int i, int j);
       <br />Swaps the value of the node at position i in the list with value of the node at position j.
      Be sure you handle out-of-range calls.
  * void insert at pos(int i, char value);
       <br />Inserts a node with value at position i in the list.
  * void reverse();
       <br />Reverses the items in the list.

Accessors
---------

  * int size()const;
       <br />Returns the number of nodes in the list.
  * void print()const;
       <br />Prints the contents of the list.
  * int find(char value)const;
       <br />Finds the position of the first occurrence of a character value in the list and returns that position. If the character is not in the list, the function returns -1.
  * int find(MyList& query str)const;
       <br />Finds the position of the first occurrence of the MyList query str in the list and returns that position. If query str is not in the list, the function returns -1.
      
Operator Overloaders
--------------------

  * MyList& operator=(const MyList& str);
       <br />For assignment of one list to another, i.e. l1 = l2;
  * char& operator[](const int i);
       <br />Returns the character at position i.
  * MyList& operator+(const MyList& str);
       <br />Concatenates two lists together, i.e. l1 + l2;
  
  You can read more about operator overloading here:
  http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
  
Testing and Error Handling
--------------------------

You must provide us with the main.cc you developed to test your program. A portion of your
grade with be based on how thorough your tests are. You are also expected to perform error
checking in your program. How you handle out of bounds cases, your use of assert or other
protective measures will be inspected. We will use our own main function when testing
your program’s functionality. Ensure you do not have any segfaults, as what cannot
be run, cannot be tested. Your code should be self-documenting and/or well commented and
as efficient as possible. Good style and Object Oriented Principles should be obeyed.
