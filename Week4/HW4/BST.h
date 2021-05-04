//
// Created by Antonio Santana on 5/3/21.
//
/** Interface for the binary search tree.
 * @file BST.h
 */

#ifndef BST_H_
#define BST_H_

#include <vector>
#include <string>

using namespace std;

template<class ItemType>
class BST
{

public:
	BST(); // Default constructor, constructs an empty binary search tree.
	BST(const BST& copyTree); // Create a copy of the BST passed in as a parameter.
    // Overloaded assignment operator. Assigns the BST passed in as a parameter to an existing BST.
    BST<ItemType>& operator = (const BST<ItemType>& tree);
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

    int size();

    bool empty();

    int getLevel(ItemType);
    std::string getAncestors(ItemType);
    string PreOrderTraversal();
    string InOrderTraversal();
    string PostOrderTraversal();

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
    int getLeafCountHelper(Node *&);
    int sizeHelper(Node *&);
    // Returns the level of a node in the BST. If the node with the given value is not present in the BST, returns -1.
    int getHeightHelper(Node *&);
    int getLevelHelper(Node *&, ItemType, int);
    std::string getAncestorsHelper(Node *&, ItemType);
    void PreOrderTraversal(Node *&,stringstream& ss);
    void InOrderTraversal(Node *&, stringstream& ss);
    void PostOrderTraversal(Node *&, stringstream& ss);
}; // end BST.h

#include "BST.cpp"

#endif

























