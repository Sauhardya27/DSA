#include <iostream>
using namespace std;

class Node {
	public:
	int data;
	Node* next;

	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void InsertAtHead(Node* &h, Node* &t, int data){
	if(!h){
		h = new Node(data);
		t = h;
		return;
	}
	Node* temp = new Node(data);
	temp->next = h;
	h = temp;
}

void InsertAtTail(Node* &h, Node* &t, int data){
	if(!h){
		h = new Node(data);
		t = h;
		return;
	}
	Node* temp = new Node(data);
	t->next = temp;
	t = temp;
}

void InsertAtPos(Node* &h, Node* &t, int data, int pos){
	if(pos<1){
		cout << "Invalid position. Cannot insert" << endl;
		return;
	}
	if(pos == 1){
		InsertAtHead(h, t, data);
		return;
	}
	Node* temp = h;
	int count = 1;
	while(temp && count < pos-1){
		temp = temp->next;
		count++;
	}

	if(!temp){
		cout << "Current position is out of bounds" << endl;
		return;
	}

	Node* newNode = new Node(data);
	newNode->next = temp->next;
	temp->next = newNode;
}

void DeleteAtHead(Node* &h){
	if(h == NULL){
		cout << "List is empty. Nothing to delete" << endl;
		return;
	}
	Node* temp = h;
	h = h->next;
	delete temp;
}

void DeleteAtTail(Node* &h, Node* &t){
	if(h == NULL){
		cout << "List is empty. Nothing to delete" << endl;
		return;
	}
	Node* temp = h;
	while(temp->next != t)
		temp = temp->next;

	temp->next = NULL;
	delete t;
	t = temp;
	t->next = NULL;
}

void DeleteAtPos(Node* &h, int pos){
	if(pos<1){
		cout << "Invalid position, unable to delete" << endl;
		return;
	}
	if(pos == 1){
		DeleteAtHead(h);
		return;
	}
	Node* temp = h;
	int count = 1;
	while(temp && count < pos-1){
		temp = temp->next;
		count++;
	}
	
	if(!temp){
		cout << "Position is out of bounds" << endl;
		return;
	}
	Node* deleteNode = temp->next;
	if(deleteNode == NULL){
		cout << "Position is out of bounds" << endl;
		delete deleteNode;
		return;
	}

	temp->next = deleteNode->next;
	delete deleteNode;
}

void print(Node* h){
	if(h == NULL){
		cout << "List is empty. Nothing to print" << endl;
		return;
	}
	Node* temp = h;
	cout << "Linked List: ";
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void reverse(Node* &h, Node* curr, Node* prev){
	if(curr == NULL){
		h = prev;
		return;
	}
	Node* forward = curr->next;
	reverse(h, forward, curr);
	curr->next = prev;
}

void reverseLinkedList(Node* &h){
	Node* prev = NULL;
	Node* curr = h;
	reverse(h, curr, prev);
}

int main(){
	Node* h = NULL;
	Node* t = NULL;
	InsertAtHead(h, t, 30);
	InsertAtHead(h, t, 20);
	InsertAtHead(h, t, 10);
	InsertAtTail(h, t, 40);
	InsertAtPos(h, t, 50, 3);
	print(h);
	// DeleteAtHead(h);
	// DeleteAtTail(h, t);
	// DeleteAtPos(h, 10);
	// print(h);
	reverseLinkedList(h);
	cout << "Linked List After Reversal: ";
	print(h);
	return 0;
}