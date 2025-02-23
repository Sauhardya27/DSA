#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
	TreeNode(int x){
	    val = x;
	    left = NULL;
	    right = NULL;
	}
};

TreeNode* solve(int preStart, int postStart, int preEnd, vector<int>& preorder, vector<int>& postorder, unordered_map<int, int> &nodeToIndex){
	if(preStart > preEnd)
		return NULL;

	TreeNode* root = new TreeNode(preorder[preStart]);

	if(preStart == preEnd)
		return root;

	int nextNode = preorder[preStart+1]; //root of left subtree

	int j = nodeToIndex[nextNode];

	int num = j-postStart+1;

	root->left = solve(preStart+1, postStart, preStart+num, preorder, postorder, nodeToIndex);
	root->right = solve(preStart+num+1, j+1, preEnd, preorder, postorder, nodeToIndex);

	return root;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
	int n = preorder.size();

	unordered_map<int, int> nodeToIndex;
	for(int i=0; i<n; i++){
		nodeToIndex[postorder[i]] = i;
	}

	return solve(0, 0, n-1, preorder, postorder, nodeToIndex);
}