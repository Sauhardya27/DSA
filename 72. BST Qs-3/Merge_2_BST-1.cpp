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

void inorder(Node* root, vector<int> &in){
    if(root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;

    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i++];
        }
        else{
            ans[k++] = b[j++];
        }
    }

    while(i < a.size())
        ans[k++] = a[i++];

    while(j < b.size())
        ans[k++] = b[j++];

    return ans;
}

vector<int> mergeBST(Node *root1, Node *root2)
{
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergedArray = mergeArrays(bst1, bst2);
    return mergedArray;
}