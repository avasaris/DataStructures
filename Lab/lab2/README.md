Lab 2: Lists & GDB
------------------
------------------

<ol>
  <li> Read the following web pages
    * Shallow v. Deep Copies:
    www.fredosaurus.com/notes-cpp/oop-condestructors/shallowdeepcopy.html
    * Destructor:
    www.fredosaurus.com/notes-cpp/oop-condestructors/destructors.html
    * Copy Constructors:
    www.fredosaurus.com/notes-cpp/oop-condestructors/copyconstructors.html
    * Overloaded Assignment Operator:
    www.fredosaurus.com/notes-cpp/oop-overloading/overloadassign.html
  </li>

  <li> Review GDB_Quick_Reference.pdf:
  		http://users.ece.utexas.edu/~adnan/gdb-refcard.pdf
		Reading the following sections.
			* Essential Commands
			* Breakpoints and Watchpoints
			* Program Stack
			* Execution Control
	</li>
	
If you need additional help understanding GDB read through the following:
	http://www.yolinux.com/TUTORIALS/GDB-Commands.html
	http://davis.lbl.gov/Manuals/GDB/gdb_9.html
	
Exercise: Practice Using the Debugger
-------------------------------------

In this lab you will gain experience with the GDB debugging tool. Debugging code is both
a skill and an art. It is easily one of the most essential tasks in programming that any
professional or serious enthusiast must master. Debuggers are also useful for visualizing
data in your program. An automatic instinct to immediately open a debugging session to
test programs or upon the discovery of a bug must be acquired.


Record the line numbers where the lists are at interesting states in which we would want to know more information about
them for your drawing. Specifically, write down the four line numbers for:
	* when both lists are done being initially populated with push_front(),
	* when second_list is set equal to first_list,
	* after the pair of push_front()’s have been called,
	* after the pair of push_back()’s have been called.

We will be adding breakpoints directly after these events have occurred. Add a
breakpoint for all these line numbers now. 

Did the outputted behavior of the program match your initial drawing? You should find
that the lists do not behave in the way you originally expected from a simple visual
inspection of the main function. To remedy this, you will implement the missing parts for
the list program. When done, verify using the debugger that your list class functions
correctly.
