#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{

public:
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

	BinaryTreeNode(int data)
	{
		this->left = NULL;
		this->right = NULL;
		this->data = data;
	}
};
void createInorder(BinaryTreeNode *root, vector<int> &inorder)
{
	if (root == NULL)
		return;

	createInorder(root->left, inorder);
	inorder.push_back(root->data);
	createInorder(root->right, inorder);
}

void fillPreOrder(BinaryTreeNode *&root, vector<int> &inorder, int &index)
{
	if (root == NULL)
		return;

	root->data = inorder[index++];
	fillPreOrder(root->left, inorder, index);
	fillPreOrder(root->right, inorder, index);
}

BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
	vector<int> inorder;
	int i = 0;
	createInorder(root, inorder);
	fillPreOrder(root, inorder, i);
	return root;
}