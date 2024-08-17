
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;

	Node(int data)
	{
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

void revLevelOrderTraversal(Node* root) {
    if (root == NULL) return;

    stack<Node*> s;
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Level separator

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            s.push(NULL); // Level separator for reverse traversal
            // If q still has some child nodes
            if (!q.empty()) {
                q.push(NULL); // Push another level separator
            }
        } else {
            s.push(temp);

            // Enqueue right child first so that left child is processed first
            if (temp->right) 
				q.push(temp->right);
            if (temp->left) 
				q.push(temp->left);
        }
    }

    // Now print the nodes in reverse level order using the stack
    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();

        if (temp == NULL) {
            cout << endl; // Newline for level separation
        } else {
            cout << temp->data << " ";
        }
    }
}

void inorder(Node* root){
	if(root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(Node* root){
	if(root == NULL)
		return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root){
	if(root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

void buildFromLevelorder(Node* &root){
	queue<Node*> q;
	int data;
	cout << "Enter data for root: ";
	cin >> data;
	if(data == -1)
		return;

	root = new Node(data);
	q.push(root);

	while(!q.empty()){
		Node* temp = q.front();
		q.pop();

		int leftData, rightData;
		cout << "Enter the left child of " << temp->data <<": ";
		cin >> leftData;

		if(leftData != -1){
			temp->left = new Node(leftData);
			q.push(temp->left);
		}

		cout << "Enter the right child of " << temp->data <<": ";
		cin >> rightData;

		if(rightData != -1){
			temp->right = new Node(rightData);
			q.push(temp->right);
		}
	}
}

int main(){
	Node* root;
	//root = createTree(root);
	buildFromLevelorder(root);

	cout << endl << "Printing level order traversal:" << endl;
	levelOrderTraversal(root);

	// cout << "Printing rev-level order traversal:" << endl;
	// revLevelOrderTraversal(root);

	// cout << "Inorder traversal" << endl;
	// inorder(root);
	// cout << endl;

	return 0;
}