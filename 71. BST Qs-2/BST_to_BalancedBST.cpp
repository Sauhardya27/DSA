#include <iostream>
#include <vector>
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

void storeInorder(Node* root, vector<int>& inorder) {
        if (root == NULL)
            return;

        storeInorder(root->left, inorder);
        inorder.push_back(root->data);
        storeInorder(root->right, inorder);
    }

    Node* inorderToBST(int s, int e, vector<int>& inorder) {
        if (s > e)
            return NULL;

        int mid = (s + e) / 2;

        Node* root = new Node(inorder[mid]);
        root->left = inorderToBST(s, mid - 1, inorder);
        root->right = inorderToBST(mid + 1, e, inorder);

        return root;
    }
    Node* balanceBST(Node* root) {
        vector<int> inorder;
        storeInorder(root, inorder);

        return inorderToBST(0, inorder.size() - 1, inorder);
    }