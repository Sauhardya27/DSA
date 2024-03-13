#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;

	node(int d){
		this->data = d;
		this->next = NULL;
	}
};

node* getMiddle(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right){
    if(left == NULL)
        return right;

    if(right == NULL)
        return left;

    node* ans = new node(-1);
    node* temp = ans;

    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return ans->next;
}

node* mergeSort(node *head) {
    if(head == NULL || head->next == NULL)
        return head;

    node* mid = getMiddle(head);

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

void InsertAtTail(node *&h, node *&t, int data){
	if (!h){
		h = new node(data);
		t = h;
		return;
	}
	node *temp = new node(data);
	t->next = temp;
	t = temp;
}

void print(node *head){
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

int main(){
	node *head = NULL;
	node *tail = NULL;

	InsertAtTail(head, tail, 1);
	InsertAtTail(head, tail, 4);
	InsertAtTail(head, tail, 5);
	InsertAtTail(head, tail, 2);
	InsertAtTail(head, tail, -1);
	cout << "Unsorted LL: ";
	print(head);


	cout << "Sorted LL: ";
	print(mergeSort(head));
	return 0;
}