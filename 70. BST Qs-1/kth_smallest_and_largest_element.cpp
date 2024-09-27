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

int smallest(Node *root, int &i, int k)
{
	if (root == NULL)
		return -1;

	int left = smallest(root->left, i, k);
	if (left != -1)
		return left;

	i++;
	if (i == k)
		return root->data;

	return smallest(root->right, i, k);
}

int largest(Node *root, int &i, int k)
{
	//Perform reverse-level order traversal for kth largest element in BST
	if (root == NULL)
		return -1;

	int right = largest(root->right, i, k);
	if (right != -1)
		return right;

	i++;
	if (i == k)
		return root->data;

	return largest(root->left, i, k);
}

int kthSmallest(Node *root, int k)
{
	int i = 0;
	int ans = smallest(root, i, k);
	return ans;
}

int kthLargest(Node *root, int k)
{
	int i = 0;
	int ans = largest(root, i, k);
	return ans;
}