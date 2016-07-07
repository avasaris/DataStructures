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
 * Filename : BST.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

class BST {

private:
    struct BinaryNode {

        int value;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode(int& v) : value(v), left(NULL), right(NULL) {}
        static BinaryNode* insert(int v, BinaryNode* t) {
            if(t == NULL){
                t = new BinaryNode(v);
            }
            else if (v < t->value)
                t->left = insert(v, t->left);
            else if (v > t->value)
                t->right = insert(v, t->right);
            else
                t->value = v;
            return t;
        }
    
        static BinaryNode* remove(int v, BinaryNode* t) {
            if(t) {
                if(v < t->value)
                    t->left = remove(v, t->left);
                else if(t->value < v)
                    t->right = remove(v, t->right);
                else if(t->left != NULL && t->right != NULL) {
                    t->value = find_min(t->right)->value;
                    t->right = remove(t->value, t->right);
                }
                else {
                    BinaryNode* oldNode = t;
                    t = (t->left != NULL) ? t->left
                    : t->right;
                    delete oldNode;
                }
            }
            return t;
        }
    
        static BinaryNode* find_min(BinaryNode* t) {
            if(t == NULL)
	           return NULL;
            if(t->left == NULL)
	           return t;
            return find_min(t->left);
        }
    };

public:
    BST(): root(NULL) {}
    ~BST();
    void freeNode(BinaryNode*);
    void insert(int v) { root = BinaryNode::insert(v, root); }
    void remove(int v) { root = BinaryNode::remove(v, root); }
    void display() { display(root); }
    void display( BinaryNode* t ) {
        // in-order traversal with indented display.
        static int depth = 0;
        ++ depth;
        if ( t == NULL ) return;
        if ( t->right != NULL ) display(t->right);
        for( int i = 0; i != depth; ++i )
            cout << " ";
        cout << t->value << " " << endl;
        if ( t->left != NULL )
            display(t->left);
            --depth;
    }
    BinaryNode* getRoot() {return root;}
    int getLocation( queue<int>, int);
    int getTreeHeight(BinaryNode*);
    int getNodeDepth( BinaryNode*, int, int );
    void print(ofstream& ofs, queue<int>&, string, string );
    void printEdges(ofstream& ofs);
    void height(ofstream& ofs);
    void preorder( BinaryNode* t, queue<int>& );
    void inorder( BinaryNode* t, queue<int>& );
    void postorder( BinaryNode* t, queue<int>& );
    queue<int> levelOrder();
private:
    BinaryNode* root;
};

// Destructor
BST::~BST() {
    
    cout << "Destructor called..." << endl;
    freeNode( getRoot() );

}

void BST::freeNode( BinaryNode* node ) {

    if (node != NULL) {
        freeNode(node->left);
        freeNode(node->right);
        cout << "Deleting " << node->value << "..." << endl;
        delete node;
    }

}

void BST::preorder( BinaryNode* root, queue<int>& preorderQ ) {

    if (root) {
        preorderQ.push(root->value);
        preorder(root->left, preorderQ);
        preorder(root->right, preorderQ);
    }    
}

void BST::inorder( BinaryNode* root, queue<int>& inorderQ ) {

    if (root) {
        inorder(root->left, inorderQ);
        inorderQ.push(root->value);
        inorder(root->right, inorderQ);
    }
}

void BST::postorder( BinaryNode* root, queue<int>& postorderQ ) {

    if (root) {
        postorder(root->left, postorderQ);
        postorder(root->right, postorderQ);
        postorderQ.push(root->value);
    }
}

void BST::height( ofstream& ofs ) {

    ofs << "// Digraph \n// lab 4 \n// output.dot \n// cs014_16sum1\n//" << "height traversal" << endl << endl;
    ofs << "digraph G {\n\n//nodes" << endl;

    queue<BinaryNode*> q;
    q.push(getRoot());   // push root
    BinaryNode* root = getRoot();
    int treeHeight = getTreeHeight(getRoot());
    char c = 'a';

    while ( ! q.empty() ) {

        // Pop a node from front
        BinaryNode* v = q.front();
        ofs << c++ << " [color = orange, peripheries=2, style = filled, label=\"key=";
        ofs << q.front()->value << ", h=" << treeHeight - getNodeDepth( root, q.front()->value, 0 ) << "\"];" << endl;

        // Push the left children
        if ( v->left != NULL ) {
            q.push(v->left);
        }

        // Push the right children
        if ( v->right != NULL ) {
            q.push(v->right);
        }

        // Pop the visited node
        q.pop();
    }

}

void BST::print( ofstream& ofs, queue<int>& queueToPrint, string symbol, string mode ) {

    ofs << "// Digraph \n// lab 4 \n// output.dot \n// cs014_16sum1\n//" << mode << " traversal" << endl << endl;
    ofs << "digraph G {\n\n//nodes" << endl;

    queue<int> levelOrderQueue = levelOrder();
    char c='a';
    while (!levelOrderQueue.empty()) {
        ofs << c++ << " [color = orange, peripheries=2, style = filled, label=\"key=";
        ofs << levelOrderQueue.front() << symbol << getLocation(queueToPrint, levelOrderQueue.front()) << "\"];" << endl;
        levelOrderQueue.pop();
    }

}

void BST::printEdges(ofstream& ofs) {

    queue<int> levelOrderQueue = levelOrder();
    queue<BinaryNode*> q;

    ofs << "\n//edges" << endl;

    q.push(getRoot());   // push root
    while ( ! q.empty() ) {

        // Pop a node from front
        BinaryNode* v = q.front();
        char parent = (char) ('a'+getLocation(levelOrderQueue, v->value) -1);

        // Push the left children
        if ( v->left != NULL ) {
            char leftChild = (char) ('a' + getLocation(levelOrderQueue, v->left->value) -1);
            ofs << parent << " -> " << leftChild << " [color=blue];" << endl;
            q.push(v->left);
        }

        // Push the right children
        if ( v->right != NULL ) {
            char rightChild = (char) ('a' + getLocation(levelOrderQueue, v->right->value) -1);
            ofs << parent << " -> " << rightChild << " [color=blue];" << endl;
            q.push(v->right);
        }

        // Pop the visited node
        q.pop();
    }

    ofs << "}" << endl;


}

int BST::getLocation( queue<int> queue, int value) {

    int location = 0;
    while (!queue.empty()) {
        location++;
        if (queue.front()==value) {
            return location;
        }
        queue.pop();
    }
    return 0;

}

int BST::getTreeHeight( BinaryNode* root ) {

    if (root == NULL) {
        return -1;
    }

    int left = getTreeHeight(root->left);
    int right = getTreeHeight(root->right);

    return 1 + max(left,right);
}

int BST::getNodeDepth( BinaryNode* root, int value, int height ) {

    if (root == NULL) {
        return 0;
    }

    if (root->value == value) {
        return height;
    }

    int depth = getNodeDepth(root->left, value, height+1);
    if (depth != 0 ) {
        return depth;
    }

    depth = getNodeDepth(root->right, value, height+1);
    return depth;

}

queue<int> BST::levelOrder() {

    queue<int> levelOrderQueue;
    queue<BinaryNode*> q;
    q.push(getRoot());   // push root

    while ( ! q.empty() ) {
       // Pop a node from front
       BinaryNode* v = q.front();
       levelOrderQueue.push( v->value );

       // Push the left children
       if ( v->left != NULL )
            q.push(v->left);

       // Push the right children
       if ( v->right != NULL )
            q.push(v->right);

       // Pop the visited node
       q.pop();
   }

   return levelOrderQueue;

}

#endif /* BST_H_ */

