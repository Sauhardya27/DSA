#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root){
	if (root == NULL)
		return 0;

	int left = maxDepth(root->left);
	int right = maxDepth(root->right);

	return max(left, right) + 1;
}

TreeNode *createTree(TreeNode *root){
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

int main(){
	TreeNode* root;
	root = createTree(root);

	cout << "Height of tree: " << maxDepth(root) << endl;
	return 0;
}