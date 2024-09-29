#include <iostream>
#include <vector>
#include <climits>
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

class info{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node* root, int &ans){
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);
    currNode.size = left.size + right.size + 1;

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else
        currNode.isBST = false;

    if(currNode.isBST)
        ans = max(ans, currNode.size);

    return currNode;
}

int largestBST(Node * root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}