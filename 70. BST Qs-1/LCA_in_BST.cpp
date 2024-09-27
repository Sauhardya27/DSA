#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
	while (root != NULL)
	{
		if (root->data < p->data && root->data < q->data)
			root = root->right;
		else if (root->data > p->data && root->data > q->data)
			root = root->left;
		else
			return root;
	}
	return NULL;
}