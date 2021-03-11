// credit: this example was adapted from https://www.geeksforgeeks.org/treap-set-2-implementation-of-search-insert-and-delete/
//
// C++ program to demonstrate search, insert and delete in Treap 
#include <bits/stdc++.h> 
using namespace std; 

// A Treap Node 
struct TreapNode 
{ 
	int key, priority; 
	TreapNode *left, *right; 
}; 

/* T1, T2 and T3 are subtrees of the tree rooted with y 
(on left side) or x (on right side) 
				y							 x 
			/ \	 Right Rotation		 / \ 
			x T3 – – – – – – – >	 T1 y 
			/ \	 < - - - - - - -		 / \ 
			T1 T2	 Left Rotation		 T2 T3 */

// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
TreapNode *rightRotate(TreapNode *y);


// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
TreapNode *leftRotate(TreapNode *x);

/* Utility function to add a new key */
TreapNode* newNode(int key);

// C function to search a given key in a given BST 
TreapNode* search(TreapNode* root, int key);

/* Recursive implementation of insertion in Treap */
TreapNode* insert(TreapNode* root, int key);

/* Recursive implementation of Delete() */
TreapNode* deleteNode(TreapNode* root, int key);

// A utility function to print tree 
void inorder(TreapNode* root);

