/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Courtney 
 * Last Name: Kelly
 * Username: ckell015
 * email address: ckell015@ucr.edu
 *
 *
 * Assignment: lab4
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "BST.H"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
  
    if(argc != 1) {
        cerr << "Usage error: expected <executable>" << endl;
        exit(1);
    }
    
    string executable = argv[0];
    string cmd = "";
    int key = -1;
    BST t;

    ofstream ofs("output.dot");
    if(!ofs) {
        cout << "output.dot could not be opened." << endl;
        exit(1);
    }
      
    for(;;) {
        cin >> cmd;
        if(cmd == "insert") {
            cin >> key;
            t.insert(key);
        }
        else if(cmd == "remove") {
            cin >> key;
            t.remove(key);
        }
        else if(cmd == "dotty") {
            string mode;
            cout << "What kind of dotty file would you like to generate? preorder, inorder, postorder, or height?" << endl;
            cin >> mode;
            if (mode=="preorder") {
                string symbol = ", pre=";
                queue<int> preorderQ;
                t.preorder( t.getRoot(), preorderQ );
                t.print(ofs, preorderQ, symbol, mode );
                t.printEdges(ofs);
            }
            else if (mode == "postorder") {
                string symbol = ", post=";
                queue<int> postorderQ;
                t.postorder( t.getRoot(), postorderQ );
                t.print(ofs, postorderQ, symbol, mode);
                t.printEdges(ofs);
            }
            else if (mode == "inorder") {
                string symbol = ", in=";
                queue<int> inorderQ;
                t.inorder( t.getRoot(), inorderQ );
                t.print(ofs, inorderQ, symbol, mode);
                t.printEdges(ofs);
            }
            else if (mode == "height") {
                t.height(ofs);
                t.printEdges(ofs);
            }
            else {
                cout << mode << ", not found, try again." << endl;
            }
        }
        else if(cmd == "display") t.display();
        else if(cmd == "end") break;
        else
          cout << cmd << ", not found, try again." << endl;
    }
      
    cout << "Good bye!" << endl;
    return 0;
}

