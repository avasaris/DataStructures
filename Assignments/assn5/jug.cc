/**
* Course: CS 14 Summer 2016
*
* First Name: Courtney 
* Last Name: Kelly
* Username: ckell015
* email address: ckell015@ucr.edu
*
*
* Assignment: assn5
* Filename : jug.cc
*
* source: https://kartikkukreja.wordpress.com/2013/10/11/water-jug-problem/
* 
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there 
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

#include <iostream>
#include <cassert>
#include <cstdio>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include "Jug.h"
#include "State.h"

using namespace std;

Jug::Jug(int Ca, int Cb, int N, int fA, int fB, int eA, int eB, int pAB, int pBA) {

	capacityA = Ca;
	capacityB = Cb;
	N = N;
	fillA = fA;
	fillB = fB;
	emptyA = eA;
	emptyB = eB;
	pourAB = pAB;
	pourBA = pBA;

}

int Jug::solve() {

	// Check if input valid 
	try {
		assert (capacityA > 0);
		assert (capacityA <= capacityB);
		assert (capacityB >= N);
		assert (capacityB <= 1000);
	}
	catch (int e) {
		return -1;
	}

	// path to solution
	stack <pair <State, int> > path;

	// BFS all the options starting with initial case being, both empty
	State initial(0,0);	
	bfs(initial, path);

	if (path.empty()) {
		return 0;
	}
	else {
		while (!path.empty()) {
			State current = path.top().first;
			int rule = path.top().second;
			path.pop();

			switch (rule)   {
                case 0: printf("State : (%d, %d)\n\n", current.jugA, current.jugB);
                        break;
                case 1: printf("State : (%d, %d) Action : Fill A\n", current.jugA, current.jugB);
                        break;
                case 2: printf("State : (%d, %d) Action : Fill B\n", current.jugA, current.jugB);
                        break;
                case 3: printf("State : (%d, %d) Action : Empty A\n", current.jugA, current.jugB);
                        break;
                case 4: printf("State : (%d, %d) Action : Empty B\n", current.jugA, current.jugB);
                        break;
                case 5: printf("State : (%d, %d) Action : Pour B A\n", current.jugA, current.jugB);
                        break;
                case 6: printf("State : (%d, %d) Action : Pour A B\n", current.jugA, current.jugB);
                        break;
            }
		}
		cout << "Success " << path.size()-1 << endl;
		return 1;
	}

}

void Jug::bfs( State initial, stack <pair <State, int> >& path ) {

	// Create an empty Queue
	queue< State > Q;
	State goal(-1, -1);


	// stores the previous states so they aren't revisited
	map < State, pair <State, int> > previous;

	// Push initial to the front of the queue
	Q.push(initial);
	previous[initial] = make_pair(initial,0);

	while (!Q.empty()) {
		// Pop front of the Queue
		State current = Q.front();
		Q.pop();

		// If target state (jugA = N) reached, break
		if (current.jugA == N || current.jugB == N) {
			goal = current;
			break;
		}

		// Rule 1: (a, b) -> (capacityA, b) if a < capacityA -- Fill the jug A
        if (current.jugA < capacityA)  {
		    State child(capacityA, current.jugB);
		    // if child state hasn't been visisted, push on the queue
		    if (previous.find(child) == previous.end()) {
		        Q.push(child);
		        previous[child] = make_pair(current, 1);
		    }
		}

		// Rule 2: (a, b) -> (a, capacityB) if b < capacityB -- Fill the jug B
        if (current.jugB < capacityB)  {
            State child(current.jugA, capacityB);
            if (previous.find(child) == previous.end()) {
                Q.push(child);
                previous[child] = make_pair(current, 2);
            }
        }

        // Rule 3: (a, b) -> (0, b) if a > 0 -- Empty the jug A
        if (current.jugA > 0)  {
            State child(0, current.jugB);
            if (previous.find(child) == previous.end()) {
                Q.push(child);
                previous[child] = make_pair(current, 3);
            }
        }

        // Rule 4: (x, y) -> (x, 0) if y > 0 -- Empty the jug B
        if (current.jugB > 0)  {
            State child(current.jugA, 0);
            if (previous.find(child) == previous.end()) {
                Q.push(child);
                previous[child] = make_pair(current, 4);
            }
        }

        // Rule 5: (x, y) -> (min(x + y, capacity_x), max(0, x + y - capacity_x)) if y > 0 -- Pour B A
        if (current.jugB > 0)  {
            State child( min(current.jugA + current.jugB, capacityA), max(0, current.jugA + current.jugB - capacityA) );
            if (previous.find(child) == previous.end()) {
                Q.push(child);
                previous[child] = make_pair(current, 5);
            }
        }

        // Rule 6: (x, y) -> (max(0, x + y - capacity_y), min(x + y, capacity_y)) if x > 0 -- Pour A B
        if (current.jugA > 0)  {
            State child( max(0, current.jugA + current.jugB - capacityB), min(current.jugA + current.jugB, capacityB) );
            if (previous.find(child) == previous.end()) {
                Q.push(child);
                previous[child] = make_pair(current, 6);
            }
        }
	}

	// Check if target state (jugA == N) was not reached
	if (goal.jugA == -1 || goal.jugB == -1) {
		return;
	}

	// push back on the stack to get sequence of rules
	path.push(make_pair(goal, 0));
	// initial state (start) is paired with 0
	while (previous[(path.top()).first].second != 0) {
        path.push(previous[(path.top()).first]);
    }

}

