#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(Node* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data);

    preOrder(node->left);

    preOrder(node->right);
}

class Solution {
  public:
    void createMap(int in[], unordered_map<int, int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    Node* solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, unordered_map<int, int> &nodeToIndex, int n){
        //Base case
        if(index < 0 || inOrderStart > inOrderEnd)
            return NULL;
            
        int ele = post[index--];
        Node* root = new Node(ele);
        int position = nodeToIndex[ele];
        
        root->right = solve(in, post, index, position+1, inOrderEnd, nodeToIndex, n);
        root->left = solve(in, post, index, inOrderStart, position-1, nodeToIndex, n);
        
        return root;
        
    }
    Node *buildTree(int n, int in[], int post[]) {
        int postOrderIndex = n-1;
        unordered_map<int, int> nodeToIndex;
        createMap(in, nodeToIndex, n);
        Node* ans = solve(in, post, postOrderIndex, 0, n-1, nodeToIndex, n);
        return ans;
    }
};

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}