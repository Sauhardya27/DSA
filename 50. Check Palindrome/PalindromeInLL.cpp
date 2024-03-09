#include <iostream>
#include <vector>
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

//Using vector
bool checkPalindrome(vector<int> arr){
    int s = 0;
    int e = arr.size() - 1;
    while(s<=e){
        if(arr[s] == arr[e]){
            s++;
            e--;
        }
        else{
            return 0;
        }
    }
    return 1;
}

bool isPalindrome(Node* head){
    vector<int> arr;
	Node* temp = head;
	while(temp != NULL){
		arr.push_back(temp->data);
		temp = temp->next;
	}
	return checkPalindrome(arr);
}

int main(){
	Node* head = NULL;
	Node* tail = NULL;

	InsertAtTail(head, tail, 1);
	InsertAtTail(head, tail, 2);
	InsertAtTail(head, tail, 3);
	InsertAtTail(head, tail, 3);
	InsertAtTail(head, tail, 2);
	InsertAtTail(head, tail, 1);
	print(head);

	if(isPalindrome(head))
		cout << "The given LL is a palindrome";
	else
		cout << "The given LL is not a palindrome";
	return 0;
}