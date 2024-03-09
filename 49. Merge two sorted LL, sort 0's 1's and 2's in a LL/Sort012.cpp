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

//Sort by replacing data
Node* sortList1(Node* head){
	int zeroCount=0, oneCount=0, twoCount=0;
	Node* temp = head;

	while(temp != NULL){
		if (temp -> data == 0)
			zeroCount++;
		else if (temp -> data == 1)
			oneCount++;
		else
			twoCount++;

		temp = temp -> next;
	}

	temp = head;
	while(temp != NULL){
		if (zeroCount != 0){
			temp -> data = 0;
			zeroCount--;
		}
		else if (oneCount != 0){
			temp -> data = 1;
			oneCount--;
		}
		else{
			temp -> data = 2;
			twoCount--;
		}
		temp = temp -> next;
	}
	return head;
}

void addEnd(Node* &tail, Node* curr){
	tail->next = curr;
	tail = curr;
}

//Sort without replacing data
Node *sortList2(Node *head) {
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while(curr != NULL){
        int val = curr->data;
        if(val == 0){
            addEnd(zeroTail, curr);
        }
        else if (val == 1){
            addEnd(oneTail, curr);
        }
        else{
            addEnd(twoTail, curr);
        }
        curr = curr->next;
    }

    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}
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

int main(){
	Node* head = NULL, *tail = NULL;

  	InsertAtTail(head, tail, 1);
  	InsertAtTail(head, tail, 2);
  	InsertAtTail(head, tail, 1);
  	InsertAtTail(head, tail, 0);
  	InsertAtTail(head, tail, 2);
  	InsertAtTail(head, tail, 0);
  	InsertAtTail(head, tail, 0);
	cout << "Original Linked List: ";
	print(head);

	cout << "Sorted Linked List: ";
	print(sortList2(head));
	return 0;
}