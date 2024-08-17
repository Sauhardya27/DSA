#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;

	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

Node *createTree(Node *root){
	cout << "Enter data to insert (-1 for no child): ";
	int data;
	cin >> data;
	root = new Node(data);

	if (data == -1)
		return NULL;

	cout << "Enter data for left child of " << data << endl;
	root->left = createTree(root->left);
	cout << "Enter data for right child of " << data << endl;
	root->right = createTree(root->right);

	return root;
}

void inorder(Node* root, int &count){
	if(root == NULL){
		return;
    }

	inorder(root->left, count);
	if(root->left == NULL && root->right == NULL)
        count++;

	inorder(root->right, count);
}

int noOfLeafNodes(Node *root){
    int count = 0;
    inorder(root, count);
    return count;
}

int main(){
	Node* root;
	root = createTree(root);

	cout << "No of leaf nodes: " << noOfLeafNodes(root) << endl;
	return 0;
}