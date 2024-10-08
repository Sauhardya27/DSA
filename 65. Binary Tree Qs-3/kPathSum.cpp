#include <iostream>
#include <vector>
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

void solve(TreeNode *root, int k, vector<int> path, int &count)
{
	if (root == NULL)
		return;

	path.push_back(root->val);

	solve(root->left, k, path, count);
	solve(root->right, k, path, count);

	long long sum = 0;
	int size = path.size();
	for (int i = size - 1; i >= 0; i--)
	{
		sum += path[i];
		if (sum == k)
			count++;
	}
	path.pop_back();
}

int pathSum(TreeNode *root, int k)
{
	vector<int> path;
	int count = 0;

	solve(root, k, path, count);
	return count;
}