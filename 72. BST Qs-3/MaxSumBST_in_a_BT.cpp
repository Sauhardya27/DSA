#include <iostream>
#include <vector>
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

class info
{
public:
	int maxi;
	int mini;
	bool isBST;
	int size;
	int sum;
};
class Solution
{
public:
	info solve(Node *root, int &ans, int &sol)
	{
		if (root == NULL)
		{
			return {INT_MIN, INT_MAX, true, 0, 0};
		}

		info left = solve(root->left, ans, sol);
		info right = solve(root->right, ans, sol);

		info currNode;

		currNode.maxi = max(root->data, right.maxi);
		currNode.mini = min(root->data, left.mini);
		currNode.size = left.size + right.size + 1;
		currNode.sum = left.sum + right.sum + root->data;

		if (left.isBST && right.isBST &&
			(root->data > left.maxi && root->data < right.mini))
		{
			currNode.isBST = true;
		}
		else
			currNode.isBST = false;

		if (currNode.isBST)
		{
			ans = max(ans, currNode.size);
			sol = max(sol, currNode.sum);
		}

		return currNode;
	}
	int maxSumBST(Node *root)
	{
		int maxSize = 0, maxSum = 0;
		info temp = solve(root, maxSize, maxSum);
		return maxSum;
	}
};