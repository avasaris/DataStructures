/*
 * cs014_16sum1 
 * lab3
 * main.cc for BST
 */

#include "BST.H"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>

using namespace std;


int main(int argc, char* argv[]) {
  
    if(argc != 2) {
        cerr << "Usage error: expected <executable> <mode>" << endl;
        exit(1);
    }
      
    string cmd = "";
    int key = -1;
    BST t;
    string mode = argv[1];
    int numNodes=0;

    // ofstream you will use to write to file output.dot
    // currently an empty output.dot gets written into pwd
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
            numNodes++;
        }
        else if(cmd == "remove") {
            cin >> key;
            t.remove(key);
            numNodes--;
        }
        else if(cmd == "dotty") {
            ofs << "// Digraph \n// lab 4 \n// output.dot \n// cs014_16sum1\n//" << mode << " traversal" << endl << endl;
            ofs << "digraph G {\n\n//nodes" << endl;
            if (mode=="preorder") {
                queue<int> preorderQ;
                t.preorder( t.getRoot(), preorderQ );
                t.print(ofs, preorderQ );
                t.printEdges(ofs);
            }
            else if (mode == "postorder") {
                queue<int> postorderQ;
                t.postorder( t.getRoot(), postorderQ );
                t.print(ofs, postorderQ);
                t.printEdges(ofs);
            }
            else if (mode == "inorder") {
                queue<int> inorderQ;
                t.inorder( t.getRoot(), inorderQ );
                t.print(ofs, inorderQ);
                t.printEdges(ofs);
            }
            else if (mode == "height") {
                queue<int> heightQ = t.height();
                t.print(ofs, heightQ);
                t.printEdges(ofs);
            }
            else {
                ofs << "Invalid mode selected" << endl;
            }
            ofs << "}" << endl;
        }
        else if(cmd == "display") t.display();
        else if(cmd == "end") break;
        else
          cout << cmd << ", not found, try again." << endl;
    }
      
    cout << "Good bye!" << endl;
    return 0;
}

