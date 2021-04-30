// BST.h

#ifndef BST_H
#define BST_H

#include <vector>

class BST {

public:
	BST();
	~BST();
	bool contains(int);
	void insert(int);
	void remove(int);

	// TODO: update traversals to avoid printing in class!
	void displayPreOrder();
	void displayInOrder();
	void displayPostOrder();

	void dumpInOrder(std::vector<int>& dest);

private:
	struct Node {
		int data;
		Node * left;
		Node * right;
	};
	Node * root;
	
	void displayPreOrder(Node *);
	void insert(Node *&, Node *&);
	void remove(Node *&, int);
	void makeDeletion(Node *&);
	void destroyTree(Node *&);

	void dumpInOrderHelper(Node * root, std::vector<int>& dest);
};

#endif
