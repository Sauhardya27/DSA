#include <iostream>
using namespace std;

class Node {
	public:
	int data;
	Node* next;
	Node* prev;

	Node(int data){
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

int getLength(Node* &h, Node* &t){
	Node* temp = h;
	int count=0;
	while(temp != t){
		count++;
		temp = temp->next;
	}
	return count+1;
}
void InsertAtHead(Node* &h, Node* &t, int data){
	if(!h){
		h = new Node(data);
		t = h;
		return;
	}
	Node* temp = new Node(data);
	temp->next = h;
	h->prev = temp;
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
	temp->prev = t;
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
	}else if(pos == getLength(h, t)+1){
		InsertAtTail(h, t, data);
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
	temp->next->prev = newNode;
	temp->next = newNode;
	newNode->prev = temp;
}

void DeleteAtHead(Node* &h){
	if(h == NULL){
		cout << "List is empty. Nothing to delete" << endl;
		return;
	}
	Node* temp = h;
	h = h->next;
	h->prev = NULL;
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
}

void DeleteAtPos(Node* &h, Node* &t, int pos){
	if(pos<1){
		cout << "Invalid position, unable to delete" << endl;
		return;
	}
	if(pos == 1){
		DeleteAtHead(h);
		return;
	}else if (pos == getLength(h, t)){
		DeleteAtTail(h, t);
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
	deleteNode->next->prev = temp;
	delete deleteNode;
}

void print(Node* h){
	if(h == NULL){
		cout << "List is empty. Nothing to delete" << endl;
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

int main(){
	Node* h = NULL;
	Node* t = NULL;
	InsertAtHead(h, t, 30);
	InsertAtHead(h, t, 20);
	InsertAtHead(h, t, 10);
	InsertAtTail(h, t, 40);
	print(h);
	// InsertAtPos(h, t, 50, 6);
	// print(h);
	// DeleteAtHead(h);
	// DeleteAtTail(h, t);
	// print(h);
	DeleteAtPos(h, t, 5);
	print(h);
	return 0;
}