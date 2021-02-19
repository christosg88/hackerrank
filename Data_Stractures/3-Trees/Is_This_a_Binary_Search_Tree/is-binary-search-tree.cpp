#include <iostream>
#include <vector>

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node()
	{
		this->data = -1;
		this->left = NULL;
		this->right = NULL;
	}
};

class Tree
{

public:
	// list of node data values:
	std::vector<int> values;
	// total number of nodes in the tree:
	int count;

	// constructor
	Tree()
	{
		this->count = 0;
	}

	/**
	 * Check if the binary tree, is also a binary search tree. That is, each
	 * node, has two sub-trees, left and right, with every node on the left
	 * sub-tree having a smaller value and every node on the right sub-tree
	 * having a greater value.
	 */
	bool checkBST(Node *root)
	{
		return isBSTHelper(root, INT32_MIN, INT32_MAX);
	}

	bool isBSTHelper(Node *root, int min, int max)
	{
		if (root == NULL) return true;

		if (root->data <= min || root->data >= max) return false;
		else return isBSTHelper(root->left, min, root->data) && isBSTHelper(root->right, root->data, max);
	}

	void inOrder(Node* root, int levels)
	{
		if (root != NULL)
		{
			// If there are still unfilled levels, fill left subtree:
			if (levels > 0)
			{
				// Create a new left child node:
				root->left = new Node();
				inOrder(root->left, levels - 1);
			}

			// Set node data:
			root->data = values.at(count);
			count++;

			// If there are still unfilled levels, fill right subtree:
			if (levels > 0)
			{
				// Create a new right child node:
				root->right = new Node();
				inOrder(root->right, levels - 1);
			}
		}
	}
};

int main(int argc, char *argv[])
{
	int height;
	std::cin >> height;

	// Read data values for tree's nodes:
	Tree *tree = new Tree();
	int value;
	while (std::cin >> value)
	{
		tree->values.push_back(value);
	}

	// Fill tree:
	Node *root = new Node();
	tree->inOrder(root, height);

	// Print result:
	if (tree->checkBST(root) == true)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}
}