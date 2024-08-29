#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

pair<int, int> solve(Node *root)
{
	if (root == NULL)
	{
		pair<int, int> p = make_pair(0, 0);
		return p;
	}

	pair<int, int> leftAns = solve(root->left);
	pair<int, int> rightAns = solve(root->right);

	pair<int, int> res;

	res.first = root->data + leftAns.second + rightAns.second;
	res.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

	return res;
}

int getMaxSum(Node *root)
{
	pair<int, int> ans = solve(root);
	return max(ans.first, ans.second);
}