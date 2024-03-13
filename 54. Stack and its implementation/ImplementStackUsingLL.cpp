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
class Stack{
	public:
	Node* top;

	Stack(){
		top = NULL;
	}

	void push(int data){
		Node* newNode = new Node(data);
		newNode->next = top;
		top = newNode;
	}

	bool isEmpty(){
		return top == NULL;
	}

	void pop(){
		if(isEmpty()){
			cout << "Stack underflow" << endl;
			return;
		}
		else{	
			Node* temp = top;
        	top = top->next;
        	delete temp;
		}
	}

	int peek(){
		if(isEmpty()){
			cout << "Stack underflow" << endl;
			return -1;
		}
		else	
			return top->data;
	}
};

int main(){
	Stack s;
	s.push(5);
	s.push(7);
	s.push(3);
	s.push(11);

	cout << "Top element: " << s.peek() << endl;
	s.pop();
	cout << "Top element: " << s.peek() << endl;

	cout << "Remaining stack elements:" << endl;
	while(!s.isEmpty()){
		cout << s.peek() << endl;
		s.pop();
	}
	return 0;
}