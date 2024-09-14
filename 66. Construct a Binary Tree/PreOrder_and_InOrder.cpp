#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

class Solution{
    public:
    void createMap(int in[], unordered_map<int, int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, unordered_map<int, int> &nodeToIndex, int n){
        //Base case
        if(index >= n || inOrderStart > inOrderEnd)
            return NULL;
            
        int ele = pre[index++];
        Node* root = new Node(ele);
        int position = nodeToIndex[ele];
        
        root->left = solve(in, pre, index, inOrderStart, position-1, nodeToIndex, n);
        root->right = solve(in, pre, index, position+1, inOrderEnd, nodeToIndex, n);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n){
        int preOrderIndex = 0;
        unordered_map<int, int> nodeToIndex;
        createMap(in, nodeToIndex, n);
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, nodeToIndex, n);
        return ans;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}