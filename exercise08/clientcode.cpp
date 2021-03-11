// credit: this example was adapted from https://www.geeksforgeeks.org/treap-set-2-implementation-of-search-insert-and-delete/
//
// C++ program to demonstrate search, insert and delete in a treap 

#include "treap.h"

// Driver Program to test above functions 
int main() 
{ 
	srand(time(NULL)); 

	struct TreapNode *root = NULL; 
	root = insert(root, 50); 
	root = insert(root, 30); 
	root = insert(root, 20); 
	root = insert(root, 40); 
	root = insert(root, 70); 
	root = insert(root, 60); 
	root = insert(root, 80); 

	cout << "Inorder traversal of the given tree \n"; 
	inorder(root); 

	cout << "\nDelete 20\n"; 
	root = deleteNode(root, 20); 
	cout << "Inorder traversal of the modified tree \n"; 
	inorder(root); 

	cout << "\nDelete 30\n"; 
	root = deleteNode(root, 30); 
	cout << "Inorder traversal of the modified tree \n"; 
	inorder(root); 

	cout << "\nDelete 50\n"; 
	root = deleteNode(root, 50); 
	cout << "Inorder traversal of the modified tree \n"; 
	inorder(root); 

	TreapNode *res = search(root, 50); 
	(res == NULL)? cout << "\n50 Not Found\n": 
				cout << "\n50 found\n"; 

	return 0; 
} 
