#include <iostream>
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

pair<int, int> predecessorSuccessor(Node* root, int key) {
    Node* temp = root;
    
    int pred = -1, succ = -1;

    while(temp != NULL){
        if(key == temp->data) {
            break;
        }
        else if(key < temp->data){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    if (temp == NULL) {
        return {pred, succ}; // Return current predecessor and successor
    }

    Node* leftTree = temp->left;
    Node* rightTree = temp->right;

    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}