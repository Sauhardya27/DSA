#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;

	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void InsertAtTail(Node* &h, Node* &t, int data) {
  	if (!h) {
    	h = new Node(data);
    	t = h;
    	return;
  	}
  	Node* temp = new Node(data);
  	t->next = temp;
  	t = temp;
}

void print(Node* head) {
  	if (head == NULL) {
    	cout << "List is empty." << endl;
    	return;
  	}

  	while (head != NULL) {
    	cout << head->data << " ";
    	head = head->next;
  	}
  	cout << endl;
}