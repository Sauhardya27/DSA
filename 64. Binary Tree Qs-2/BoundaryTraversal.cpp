#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

void traverseLeft(Node *root, vector<int> &ans)
{
	if ((root == NULL) || (root->left == NULL && root->right == NULL))
		return;

	ans.push_back(root->data);
	if (root->left)
		traverseLeft(root->left, ans);
	else
		traverseLeft(root->right, ans);
}

void traverseLeaf(Node *root, vector<int> &ans)
{
	if (root == NULL)
		return;

	if (root->left == NULL && root->right == NULL)
	{
		ans.push_back(root->data);
		return;
	}

	traverseLeaf(root->left, ans);
	traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
	if ((root == NULL) || (root->left == NULL && root->right == NULL))
		return;

	if (root->right)
		traverseRight(root->right, ans);
	else
		traverseRight(root->left, ans);

	// Push the data while returning back so that it gets pushed in rev order.
	ans.push_back(root->data);
}

vector<int> boundary(Node *root){
	// Step 1: Traverse all the left nodes excluding the leaf node on left side
	// Step 2: Traverse all the leaf nodes from left to right
	// Step 3: Traverse all the right nodes in rev direction excluding root
	// and leaf node
	vector<int> ans;
	if (root == NULL)
		return ans;

	ans.push_back(root->data);

	// Traversing left nodes
	traverseLeft(root->left, ans);

	// Traversing the leaf nodes:

	// Traversing the leaf nodes for left subtree
	traverseLeaf(root->left, ans);
	// Traversing the leaf nodes for right subtree
	traverseLeaf(root->right, ans);

	// Traversing right nodes
	traverseRight(root->right, ans);

	return ans;
}