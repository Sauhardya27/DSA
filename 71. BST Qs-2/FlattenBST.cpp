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

void storeInorder(Node* root, vector<Node*> &inorder){
    if(root == NULL)
        return;

    storeInorder(root->left, inorder);
    inorder.push_back(root);
    storeInorder(root->right, inorder);
}

Node* flatten(Node* root)
{
    vector<Node*> inorder;
    storeInorder(root, inorder);

    for (size_t i = 0; i < inorder.size(); i++) {
        inorder[i]->left = NULL;  // Set left child to NULL
        // Set the right child to the next node in the vector
        if (i + 1 < inorder.size()) {
            inorder[i]->right = inorder[i + 1];
        } else {
            inorder[i]->right = NULL;  // Last node's right should be NULL
        }
    }

    return inorder.empty() ? NULL : inorder[0];
}
