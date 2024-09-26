#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d){
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

void levelOrderTraversal(Node* root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp == NULL){
			cout << endl;
			//If q still have some child nodes
			if(!q.empty())
				q.push(NULL);
		}
		else{
			cout << temp->data << " ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}

int main(){
	Node* root = NULL;
	cout << "Enter data into BST:" << endl;
	takeInput(root);

	cout << "Level-order traversal of BST:" << endl;
	levelOrderTraversal(root);
	return 0;
}