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

Node* solve(Node* first, Node* second){
    if(first->next == NULL){
        first->next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* sortTwoLists(Node* first, Node* second)
{
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;

    if(first->data <= second->data)
        return solve(first, second);
    else 
        return solve(second, first);
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
	Node* firstHead = NULL;
	Node* firstTail = firstHead;
	Node* secondHead = NULL;
	Node* secondTail = secondHead;

	InsertAtTail(firstHead, firstTail, 1);
	InsertAtTail(firstHead, firstTail, 4);
	InsertAtTail(firstHead, firstTail, 5);

	InsertAtTail(secondHead, secondTail, 2);
	InsertAtTail(secondHead, secondTail, 3);
	InsertAtTail(secondHead, secondTail, 6);

	cout << "First sorted LL: ";
	print(firstHead);
	cout << "Second sorted LL: ";
	print(secondHead);

	cout << "Sorted LL: ";
	print(sortTwoLists(firstHead, secondHead));
	return 0;
}