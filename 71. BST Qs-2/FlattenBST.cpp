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

void storeInorder(Node* root, vector<int> &inorder){
    if(root == NULL)
        return;

    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

Node* flatten(Node* root)
{
    vector<int> inorder;
    storeInorder(root, inorder);
    int n = inorder.size();

    Node* newRoot = new Node(inorder[0]);
    Node* curr = newRoot;

    for(int i=1; i<n; i++){
        Node* temp = new Node(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}