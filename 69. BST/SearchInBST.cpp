#include <iostream>
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

Node* insertIntoBST(Node* root, int d){
	if(root == NULL){
		root = new Node(d);
		return root;
	}

	if(root->data > d)
		root->left = insertIntoBST(root->left, d);
	else
		root->right = insertIntoBST(root->right, d);
	return root;
}

void takeInput(Node* &root){
	int data;
	cin >> data;

	while(data != -1){
		root = insertIntoBST(root, data);
		cin >> data;
	}
}

Node *searchBST(Node *root, int x)
{
	//Recursive solution takes O(h) time and space complexity, h = height of BST
	//Iterative solution takes O(h) time complexity.
	Node *temp = root;

	while (temp != NULL)
	{
		if (temp->data == x)
			return temp;
		if (temp->data > x)
			return searchBST(root->left, x);
		else
			return searchBST(root->right, x);
	}
	return NULL;
}

int main(){
	Node* root = NULL;
	cout << "Enter data into BST:" << endl;
	takeInput(root);

	int val;
	cout << "Enter value to search for: ";
	cin >> val;

	if(searchBST(root, val))
		cout << "Element found" << endl;
	else
		cout << "Element not found" << endl;
	return 0;
}