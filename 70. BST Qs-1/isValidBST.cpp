#include <iostream>
#include <climits>
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

bool isBST(Node *root, long min, long max)
{
	if (root == NULL)
		return true;
	if ((root->data > min && root->data < max))
	{
		bool left = isBST(root->left, min, root->data);
		bool right = isBST(root->right, root->data, max);
		return left && right;
	}
	else
		return false;
}
bool isValidBST(Node *root)
{
	return isBST(root, LONG_MIN, LONG_MAX);
}