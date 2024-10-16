//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
  public:
    int countNodes(struct Node* root){
        if(root == NULL)
            return 0;
        
        int ans = countNodes(root->left) + countNodes(root->right) + 1;
        return ans;
    }
    
    bool isCBT(struct Node* root, int i, int nodeCount){
        if(root == NULL)
            return true;
            
        if(i >= nodeCount)
            return false;
        else{
            bool left = isCBT(root->left, 2*i + 1, nodeCount);
            bool right = isCBT(root->right, 2*i + 2, nodeCount);
            return left && right;
        }
    }
    
    bool isMaxOrder(struct Node* root){
        if(root->left == NULL && root->right == NULL)
            return true;
            
        if(root->right == NULL)
            return root->data > root->left->data;
        else{
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            return left && right && 
            (root->data > root->left->data) && (root->data > root->right->data);
        }
    }
    
    bool isHeap(struct Node* tree) {
        int i = 0;
        int cnt = countNodes(tree);
        return isCBT(tree, i, cnt) && isMaxOrder(tree);
    }
};

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}