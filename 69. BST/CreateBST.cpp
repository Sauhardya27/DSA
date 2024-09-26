#include <iostream>
#include <queue>
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

Node *insertIntoBST(Node *root, int d)
{
	if (root == NULL)
	{
		root = new Node(d);
		return root;
	}

	if (root->data > d)
		root->left = insertIntoBST(root->left, d);
	else
		root->right = insertIntoBST(root->right, d);
	return root;
}

void takeInput(Node *&root)
{
	int data;
	cin >> data;

	while (data != -1)
	{
		root = insertIntoBST(root, data);
		cin >> data;
	}
}

pair<Node *, Node *> minAndMaxInBST(Node *root)
{
	pair<Node *, Node *> p = make_pair(nullptr, nullptr);
	if (root == NULL)
		return p;

	Node *temp = root;
	while (temp->left != NULL)
		temp = temp->left;

	p.first = temp;

	temp = root;
	while (temp->right != NULL)
		temp = temp->right;

	p.second = temp;
	return p;
}

Node *inorderPredecessor(Node *root)
{
	if (root == NULL || root->left == NULL)
		return NULL;

	Node *temp = root->left;
	while (temp->right != NULL)
		temp = temp->right;

	return temp;
}

Node *deleteNode(Node *root, int val)
{
	if (root == NULL)
	{
		return root;
	}

	if (root->data == val)
	{
		// 0 child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}

		// 1 child
		if (root->left != NULL && root->right == NULL)
		{
			Node *temp = root->left;
			delete root;
			return temp;
		}
		if (root->left == NULL && root->right != NULL)
		{
			Node *temp = root->right;
			delete root;
			return temp;
		}

		// 2 child
		else
		{
			int ip = inorderPredecessor(root)->data;
			root->data = ip;
			root->left = deleteNode(root->left, ip);
			return root;
		}
	}
	else if(root->data > val){
		root->left = deleteNode(root->left, val);
		return root;
	}
	else{
		root->right = deleteNode(root->right, val);
		return root;
	}
}

void levelOrderTraversal(Node *root)
{
	queue<Node *> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		if (temp == NULL)
		{
			cout << endl;
			// If q still have some child nodes
			if (!q.empty())
				q.push(NULL);
		}
		else
		{
			cout << temp->data << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
}

int main()
{
	Node *root = NULL;
	cout << "Enter data into BST:" << endl;
	takeInput(root);

	cout << "Level-order traversal of BST:" << endl;
	levelOrderTraversal(root);

	// pair<Node*, Node*>p;
	// p = minAndMaxInBST(root);
	// cout << "Min element: " << p.first->data << ", Max element: " << p.second->data << endl;

	root = deleteNode(root, 20);

	cout << "Level-order traversal of BST:" << endl;
	levelOrderTraversal(root);
	return 0;
}