#include <bits/stdc++.h> 
using namespace std;

class node{
    public:
        int data;
        int row;
        int col;

        node(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    priority_queue<node*, vector<node*>, compare> minHeap;

    for(int i=0; i<k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    while(minHeap.size() > 0){
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int row = temp->row;
        int col = temp->col;

        if(col+1 < kArrays[row].size()){
            node* next = new node(kArrays[row][col+1], row, col+1);
            minHeap.push(next);
        }
    }
    return ans;
}
