#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;

	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class cmp{
public:
	bool operator()(Node *a, Node *b){
		return a->data > b->data;
	}
};

void traverse(Node* root, vector<string> &ans, string temp){
	if(root->left == NULL && root->right == NULL){
		ans.push_back(temp);
		return;
	}
	
	traverse(root->left, ans, temp+'0');
	traverse(root->right, ans, temp+'1');
}

vector<string> huffmanCodes(string S,vector<int> f,int N)
{
	priority_queue<Node*, vector<Node*>, cmp> pq;
	
	for(auto &num: f){
		Node* temp = new Node(num);
		pq.push(temp);
	}
	
	while(pq.size() > 1){
		Node* left = pq.top();
		pq.pop();
		
		Node* right = pq.top();
		pq.pop();
		
		Node* newNode = new Node(left->data + right->data);
		newNode->left = left;
		newNode->right = right;
		pq.push(newNode);
	}
	
	vector<string> ans;
	string temp = "";
	Node* root = pq.top();
	
	traverse(root, ans, temp);
	return ans;
}