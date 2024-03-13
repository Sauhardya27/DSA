#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node* child;

	Node(int d){
		this->data = d;
		this->next = NULL;
		this->child = NULL;
	}
};

Node* merge(Node* a, Node* b){
    // If first linked list is empty then second
    // is the answer
    if (a == NULL)
        return b;
 
    // If second linked list is empty then first
    // is the result
    if (b == NULL)
        return a;
 
    // Compare the data members of the two linked
    // lists and put the larger one in the result
    Node* result;
 
    if (a->data < b->data) {
        result = a;
        result->child = merge(a->child, b);
    }
 
    else {
        result = b;
        result->child = merge(a, b->child);
    }
    result->next = NULL;
    return result;
}

Node* flattenLinkedList(Node* head){
    if (head == NULL || head->next == NULL)
        return head;
 
    // Recur for next list
    head->next = flattenLinkedList(head->next);
 
    // Now merge
    head = merge(head, head->next);
 
    // Return the root
    // it will be in turn merged with its left
    return head;
}

int main(){
	return 0;
}