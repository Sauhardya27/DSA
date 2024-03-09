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

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
        
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void addEnd(Node* &head, Node* &tail, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node* add(Node* first, Node* second){
    int carry = 0;
        
    Node* ansHead = NULL;
    Node* ansTail = NULL;
        
    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        if(first != NULL)
            val1 = first->data;
                
        int val2 = 0;
        if(second != NULL)
            val2 = second->data;
                
        int sum = carry + val1 + val2;
        int digit = sum%10;
            
        addEnd(ansHead, ansTail, digit);
            
        carry = sum/10;
        if(first != NULL)
            first = first -> next;
            
        if(second != NULL)
            second = second -> next;
    }
    return ansHead;
}

Node* addTwoLists(Node* first, Node* second){
    first = reverse(first);
    second = reverse(second);
        
    Node* result = add(first, second);
        
    return reverse(result);
}

int main(){
	Node* firstHead = NULL;
	Node* firstTail = NULL;
	Node* secondHead = NULL;
	Node* secondTail = NULL;

	InsertAtTail(firstHead, firstTail, 6);
	InsertAtTail(firstHead, firstTail, 3);
	InsertAtTail(secondHead, secondTail, 7);
	// InsertAtTail(secondHead, secondTail, 4);
	// InsertAtTail(secondHead, secondTail, 5);

	cout << "List 1: ";
	print(firstHead);
	cout << "List 2: ";
	print(secondHead);

	cout << "Resultant list after addition: ";
	print(addTwoLists(firstHead, secondHead));
	return 0;
}