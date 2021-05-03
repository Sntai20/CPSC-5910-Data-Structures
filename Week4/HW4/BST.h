//
// Created by Antonio Santana on 5/3/21.
//
/** Interface for the binary search tree.
 * @file BST.h
 */

#ifndef BST_H_
#define BST_H_

#include <vector>

using namespace std;

template<class ItemType>
class BST
{

public:
	BST(); // Default constructor, constructs an empty binary search tree.
	/* TODO: Create a copy of the BST passed in as a parameter.
	 * BST();*/

	/* TODO: Overloaded assignment operator
	 * Assigns the BST passed in as a parameter to an existing BST.
	 * BST(); */
	~BST();
	/* Searches the BST to determine if a given value is present.
	 * Returns true if so, else false. Must use recursion. */
	bool contains(ItemType);

	/* Inserts the element passed in as a parameter into
	 * the BST. Assume no duplicate values. Must use recursion. */
	void insert(ItemType);

	/* Removes the specified value from the BST. */
	void remove(ItemType);

	// TODO: update traversals to avoid printing in class!
	void displayPreOrder();
	void displayInOrder();
	void displayPostOrder();

	void dumpInOrder(std::vector<ItemType>& dest);

    int getHeight();

    int getLeafCount();

    int treeSize();

    bool empty();

private:
	struct Node {
		ItemType data;
		Node * left;
		Node * right;
	};
	Node * root;

	void displayPreOrder(Node *);
	void displayInOrder(Node *);
	void displayPostOrder(Node *);
	void insert(Node *&, Node *&);
	void remove(Node *&, ItemType);
	void makeDeletion(Node *&);
	void destroyTree(Node *&);

	void dumpInOrderHelper(Node * root, std::vector<ItemType>& dest);
}; // end BST.h

#include "BST.cpp"

#endif

























