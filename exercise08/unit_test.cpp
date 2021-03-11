#define CATCH_CONFIG_MAIN  // This line tells Catch to provide a main() function
                           // - do this in one cpp file only
#include "catch.hpp"       // This line provides access to all Catch macros
                           // - do not modify catch.hpp
#include "treap.h"
#include <cassert>    
#include <cstdlib>

TEST_CASE("treap unit test1", "[treap]") {

	struct TreapNode *root = NULL; 
	root = insert(root, 50);
	
	TreapNode *res = search(root, 50);
	REQUIRE(res->key == 50);

}

TEST_CASE("treap unit test2 (testing insert)", "[treap") {

	struct TreapNode *root = NULL;
	
	for (int i = 0; i <= 100; i += 10) {
		root = insert(root, i);
		TreapNode *res = search(root, i);

		REQUIRE(res->key == i);
	}
}

TEST_CASE("treap unit test3 (testing search)", "[treap]") {
	struct TreapNode *root = NULL;

	for (int i = 0; i <= 100; i += 10) {
		root = insert(root, i);
		TreapNode *res = search(root, i);

		REQUIRE(res->key == i);
	}

	TreapNode *miss = search(root, 22);
	REQUIRE(miss == NULL);
}

TEST_CASE("treap unit test4 (testing delete)", "[treap]") {
	struct TreapNode *root = NULL;

	for (int i = 0; i <= 100; i += 10) {
		root = insert(root, i);
		TreapNode *res = search(root, i);

		REQUIRE(res->key == i);
	}

	for (int i = 0; i < 50; i += 10) {
		root = deleteNode(root, i);

		TreapNode *miss = search(root, i);

		REQUIRE(miss == NULL);
	}
}

TEST_CASE("treap unit test5 (testing right and left)", "[treap]") {
	struct TreapNode *root = NULL;
	
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);

	TreapNode *res = search(root, 30);
	TreapNode *right = search(root, 20);
	TreapNode *left = search(root, 10);


	REQUIRE(res->right == NULL);
	REQUIRE(res->left == left);
	REQUIRE(left->right == right);

	rightRotate(root);

	REQUIRE(right->left == NULL);
	REQUIRE(right->right == NULL);
	REQUIRE(res->left == right);
	REQUIRE(res->right == NULL);

}

TEST_CASE("treap unit testing (testing everything)", "[treap]") {
	struct TreapNode *root = NULL;

	for (int i = 0; i < 50; i += 10) {
		root = insert(root, i);
		TreapNode *res = search(root, i);

		REQUIRE(res->key == i);
	}

	TreapNode *zero = search(root, 0);
	TreapNode *one = search(root, 10);
	TreapNode *two = search(root, 20);
	TreapNode *three = search(root, 30);
	TreapNode *four = search(root, 40);

	REQUIRE(zero->right == two);
	REQUIRE(two->left == one);
	REQUIRE(two->right == three);
	REQUIRE(four->left == zero);



	//inorder(root);

	root = deleteNode(root, 20);
	root = deleteNode(root, 30);

	TreapNode *zero1 = search(root, 0);
	TreapNode *one1 = search(root, 10);
	TreapNode *two1 = search(root, 20);
	TreapNode *three1 = search(root, 30);
	TreapNode *four1 = search(root, 40);

	REQUIRE(two1 == NULL);
	REQUIRE(three1 == NULL);

	REQUIRE(zero1->right == one1);
	REQUIRE(four1->left == zero1);
	REQUIRE(zero1->left == NULL);
	REQUIRE(one1->right == NULL);
	REQUIRE(one1->left == NULL);
	REQUIRE(four1->right == NULL);


	
}