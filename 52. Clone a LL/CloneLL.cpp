#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node *arb;

	Node(int data){
		this->data = data;
		this->next = NULL;
		this->arb = NULL;
	}
};

void InsertAtTail(Node *&h, Node *&t, int data){
	if (!h){
		h = new Node(data);
		t = h;
		return;
	}
	Node *temp = new Node(data);
	t->next = temp;
	t = temp;
}

void print(Node *head){
	if (head == NULL){
		cout << "List is empty." << endl;
		return;
	}

	while (head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

// Aproach 1 using unordered map
/*Node *copyList(Node *head){
	Node* cloneHead = NULL;
	Node* cloneTail = NULL;

	Node* temp = head;
	while(temp != NULL){
		InsertAtTail(cloneHead, cloneTail, temp->data);
		temp = temp->next;
	}

	unordered_map<Node*, Node*> oldToNewNode;
	Node* originalHead = head;
	temp = cloneHead;
	while(originalHead != NULL){
		oldToNewNode[originalHead] = temp;
		originalHead = originalHead->next;
		temp = temp->next;
	}

	originalHead = head;
	temp = cloneHead;
	while(originalHead != NULL){
		temp->arb = oldToNewNode[originalHead->arb];
		originalHead = originalHead->next;
		temp = temp->next;
	}
	return cloneHead;
}*/

// In linear space Complexity
Node *copyList(Node *head){
	// step 1: Create a Clone List
	Node *cloneHead = NULL;
	Node *cloneTail = NULL;

	Node *temp = head;
	while (temp != NULL){
		InsertAtTail(cloneHead, cloneTail, temp->data);
		temp = temp->next;
	}

	// step 2: insert nodes of Clone List in between originalList
	Node *originalNode = head;
	Node *cloneNode = cloneHead;
	while (originalNode != NULL && cloneNode != NULL){
		Node *next = originalNode->next;
		originalNode->next = cloneNode;
		originalNode = next;

		next = cloneNode->next;
		cloneNode->next = originalNode;
		cloneNode = next;
	}

	// step 3: Random pointer copy
	temp = head;
	while (temp != NULL){
		if (temp->next != NULL)
		{
			temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
		}
		temp = temp->next->next;
	}

	// step 4: revert step 2 changes
	Node *original = head;
	Node *copy = cloneHead;

	while (original && copy){
		original->next =
			original->next ? original->next->next : original->next;

		copy->next = copy->next ? copy->next->next : copy->next;
		original = original->next;
		copy = copy->next;
	}

	return cloneHead;
}

int main()
{
	return 0;
}