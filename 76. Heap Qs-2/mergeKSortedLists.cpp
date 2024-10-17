#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

class compare {
public:
    bool operator()(Node* a, Node* b) { return a->data > b->data; }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != NULL) {
                minHeap.push(arr[i]);
            }
        }

        Node* head = new Node(0);
        Node* tail = head;

        while (!minHeap.empty()) {
            Node* temp = minHeap.top();
            minHeap.pop();

            tail->next = temp;
            tail = tail->next;

            if (temp->next != NULL) {
                minHeap.push(temp->next);
            }
        }

        return head->next;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<Node*> arr;
        vector<int> nums;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            nums.push_back(number);
        }
        int ind = 0;
        int N = nums.size();

        while (ind < N) {
            int n = nums[ind++];
            int x = nums[ind++];
            Node* head = new Node(x);
            Node* curr = head;
            n--;

            for (int i = 0; i < n; i++) {
                x = nums[ind++];
                Node* temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
            arr.push_back(head);
        }

        Solution obj;
        Node* res = obj.mergeKLists(arr);
        printList(res);
    }
    return 0;
}