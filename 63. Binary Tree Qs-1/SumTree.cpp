#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

Node *createTree(Node *root)
{
	cout << "Enter data to insert (-1 for no child): ";
	int data;
	cin >> data;
	root = new Node(data);

	if (data == -1)
		return NULL;

	cout << "Enter data for left child of " << data << endl;
	root->left = createTree(root->left);
	cout << "Enter data for right child of " << data << endl;
	root->right = createTree(root->right);

	return root;
}

pair<bool, int> optimizedSumTree(Node *root)
{
	if (root == NULL)
	{
		pair<bool, int> p = make_pair(true, 0);
		return p;
	}
	if (root->left == NULL && root->right == NULL)
	{
		pair<bool, int> p = make_pair(true, root->data);
		return p;
	}

	pair<bool, int> left = optimizedSumTree(root->left);
	pair<bool, int> right = optimizedSumTree(root->right);

	bool leftAns = left.first;
	bool rightAns = right.first;

	bool condition = root->data == left.second + right.second;

	pair<bool, int> ans;
	ans.first = leftAns && rightAns && condition;
	ans.second = 2 * root->data;

	return ans;
}

bool isSumTree(Node *root)
{
	return optimizedSumTree(root).first;
}

int main()
{
	Node *root;
	root = createTree(root);

	cout << isSumTree(root) << endl;
	return 0;
}