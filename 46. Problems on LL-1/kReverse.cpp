#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node() : data(0), next(nullptr) {}
	Node(int x) : data(x), next(nullptr) {}
	Node(int x, Node *next) : data(x), next(next) {}
};

int getlength(Node*head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;

    }
    return c;
}

Node* kReverse(Node* head, int k) {
    //base case
    if(head==NULL){
        return NULL;

    }

    Node*prev=NULL;
    Node*curent=head;
    Node*forward=NULL;

    int c=0;
    while(curent!=NULL && c<k){
        forward=curent->next;
        curent->next=prev;
        prev=curent;
        curent=forward;
        c++;
    }

    if(forward!=NULL ){
        if(getlength(forward)>=k){
            head->next = kReverse(forward, k);
        }
        else{
            head->next=forward;
        }
    }
    return prev;
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
	InsertAtTail(head, tail, 5);
	InsertAtTail(head, tail, 4);
	InsertAtTail(head, tail, 3);
	InsertAtTail(head, tail, 7);
	InsertAtTail(head, tail, 9);
	InsertAtTail(head, tail, 2);
	print(head);

	head = kReverse(head, 4);
	print(head);
	return 0;
}