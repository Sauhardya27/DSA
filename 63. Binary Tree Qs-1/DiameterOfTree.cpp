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

int height(TreeNode *root){
	if (root == NULL)
		return 0;

	int left = height(root->left);
	int right = height(root->right);

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

// Approach 1 O(n^2):
/*int diameterOfBinaryTree(TreeNode* root) {
	//op1: diameter exists in left subtree
	//op2: diameter exists in right subtree
	//op3: diameter exists between the left and right subtree => height of left subtree + height of right subtree (Diameter = no. of edges)
	if(root == NULL)
			return 0;

	int op1 = diameterOfBinaryTree(root->left);
	int op2 = diameterOfBinaryTree(root->right);
	int op3 = height(root->left) + height(root->right);

	return max(op1, max(op2, op3));
}*/

// Approach 2 O(n):
pair<int, int> optimizedDiameter(TreeNode *root){
	if (root == NULL){
		pair<int, int> p = make_pair(0, 0);
		return p;
	}

	pair<int, int> left = optimizedDiameter(root->left);
	pair<int, int> right = optimizedDiameter(root->right);

	int op1 = left.first;
	int op2 = right.first;
	int op3 = left.second + right.second;

	pair<int, int> ans;
	ans.first = max(op1, max(op2, op3));
	ans.second = max(left.second, right.second) + 1;

	return ans;
}

int diameterOfBinaryTree(TreeNode *root){
	// op1: diameter exists in left subtree
	// op2: diameter exists in right subtree
	// op3: diameter exists between the left and right subtree => height of left subtree + height of right subtree (Diameter = no. of edges)
	return optimizedDiameter(root).first;
}

int main(){
	TreeNode* root;
	root = createTree(root);

	cout << "Diameter of tree: " << diameterOfBinaryTree(root) << endl;
	return 0;
}