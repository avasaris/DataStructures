Assignment 2
------------
------------

For this assignment, you will write a program to find the smallest word ladder given a start word and an end word. To keep things simple, you will only be working with 5 letter words.

The program will take as command line arguments the name of the dictionary file, the start word, and the end word and output to standard output the word ladder, e.g. ($a.out words5.dict brave heart). The output must start with the start word and end with the end word, and output no other characters other than whitespace. We will have a program that will take your output in this format as its input and verify you have a valid word ladder.

Algorithm - Find Word Ladder
----------------------------

   Create a stack of strings.
   Push the start word on this stack.
   Create a queue of stacks.
   Enqueue this stack.

   <pre><code>While the queue is not empty
      For each word in the dictionary
         If a word is one letter different (in any position) than the top string of the front stack
            If this word is the end word
              You are done! The front stack plus this word is your word ladder. Don't forget to output this word ladder.
            Make a copy of the front stack.
            Push the found word onto the copy.
            Enqueue the copy.
      Dequeue front stack.</code></pre>

Implementation
--------------

You will implement your own queue and stack. These classes must follow the ADT specifications given in lecture meaning the public interface must be the same and all public member function must run in O(1) time in the worst case. The only exceptions to the O(1) rule are the "Big 3" functions, copy constructor, overloaded assignment operator, and destructor. Since you will be copying stacks, you may need to define these functions yourself to avoid shallow copies. Here is a link to some notes on copy constructors if you don't have your CS12 textbook anymore: Copy Constructor info.

You must also implement a WordLadder class with the following public interface:

WordLadder( const string &listFile ) - Constructor that passes in the name of the dictionary file.
void outputLadder( const string &start, const string &end ) - passes in the start and end words and outputs to standard output the word ladder.

Storing the dictionary
----------------------

The dictionary is in a file. You will want to read in the dictionary once and store it. Which of the "list" data structures we've learned so far should we choose to store this dictionary in: vector, list, queue, or stack? Once you begin to understand the algorithm, you will find that you can make this algorithm run much faster if you take out of the dictionary, or at least ignore, any word you've added to a potential word ladder.

You are required to use STL's list or slist (whichever is the most efficient possible given your algorithm) to store the dictionary. Do not make your own linked list as I want you to have practice using the STL list along with their iterator. Why is a linked list a good choice here?

Object Oriented Programming
---------------------------

There is a lot of freedom in the design of this assignment and since writing the actual queue and stack implementation is simple (I give a lot of it in class), a large portion of the points will be dedicated to your OOP skills.
Modular design

What modules should you create and what should each module be responsible for? You should have several private member functions in the WordLadder class. When you are done with this assignment, you should be able to directly take out your queue and stack classes and use them to implement a queue or stack for some other data structure by simply changing the type of data stored in the node class or changing the type of the array. A queue or stack class should know nothing about WHAT it is actually queuing or stacking, nor should a queue or stack class contain data specific statistics.
