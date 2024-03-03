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

Node * removeDuplicates(Node *head){
    Node* curr = head;
    while(curr != NULL){
        if(curr->next != NULL && curr->data == curr->next->data){
            Node* nextNode = curr->next;
            curr->next = nextNode->next;
            delete(nextNode);
        } else {
            curr = curr->next;
        }
    }
    return head;
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

void print(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
	Node *head, *tail;
	head = tail = NULL;
	InsertAtTail(head, tail, 1);
	InsertAtTail(head, tail, 2);
	InsertAtTail(head, tail, 2);
	InsertAtTail(head, tail, 3);
	InsertAtTail(head, tail, 3);
	InsertAtTail(head, tail, 4);
	InsertAtTail(head, tail, 5);
	InsertAtTail(head, tail, 5);
	cout << "Linked List before removing duplicates:";
	print(head);

	cout << "Linked List after removing duplicates:";
	print(removeDuplicates(head));
	return 0;
}