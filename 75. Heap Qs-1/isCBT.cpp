#include <bits/stdc++.h>
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
class Solution
{
public:
	bool isCompleteTree(TreeNode *root){
		if (root == NULL)
			return true;

		queue<TreeNode *> q;
		q.push(root);
		bool encounteredNull = false;

		while (!q.empty()){
			TreeNode *current = q.front();
			q.pop();

			if (current == NULL){
				encounteredNull = true;
			}
			else{
				// If we encounter a non-NULL node after having
				// seen a NULL node, it's not complete
				if (encounteredNull)
					return false;

				q.push(current->left);
				q.push(current->right);
			}
		}
		return true;
	}
};