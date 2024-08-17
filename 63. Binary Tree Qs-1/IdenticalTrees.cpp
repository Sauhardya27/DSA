#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTree(TreeNode *root)
{
	cout << "Enter data to insert (-1 for no child): ";
	int data;
	cin >> data;
	root = new TreeNode(data);

	if (data == -1)
		return NULL;

	cout << "Enter data for left child of " << data << endl;
	root->left = createTree(root->left);
	cout << "Enter data for right child of " << data << endl;
	root->right = createTree(root->right);

	return root;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL && q != NULL)
		return false;
	if (p != NULL && q == NULL)
		return false;

	bool leftAns = isSameTree(p->left, q->left);
	bool rightAns = isSameTree(p->right, q->right);

	bool data = p->val == q->val;

	return leftAns && rightAns && data;
}

int main()
{
	TreeNode *p, *q;
	p = createTree(p);
	q = createTree(q);

	cout << isSameTree(p, q) << endl;
	return 0;
}