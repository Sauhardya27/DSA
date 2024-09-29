#include <iostream>
#include <vector>
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

void storeInorder(Node *root, vector<int> &inorder)
{
	if (root == NULL)
		return;

	storeInorder(root->left, inorder);
	inorder.push_back(root->data);
	storeInorder(root->right, inorder);
}
bool findTarget(Node *root, int k)
{
	vector<int> inorder;
	storeInorder(root, inorder);

	int i = 0, j = inorder.size() - 1;
	while (i < j)
	{
		int sum = inorder[i] + inorder[j];
		if (sum == k)
			return true;
		else if (sum < k)
			i++;
		else
			j--;
	}
	return false;
}