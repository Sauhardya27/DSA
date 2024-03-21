#include <iostream>
using namespace std;

class Node{
	public:

	int data;
	Node* next;

	Node(int d){
		data = d;
		next = NULL;
	}
};

class Queue{
	Node* qFront;
	Node* rear;

	public:
		Queue(){
			qFront = rear = NULL;
		}

		bool isEmpty(){
			if(qFront == NULL)
				return true;
			else	
				return false;
		}

		void enqueue(int x){
			Node* temp = new Node(x);

			if(rear == NULL){
				qFront = rear = temp;
				return;	
			}
			rear->next = temp;
			rear = temp;
		}

		void dequeue(){
			if(isEmpty())
				cout << "Queue underflow" << endl;
			else{
				Node* temp = qFront;
				qFront = qFront->next;

				if(qFront == NULL)
					rear = NULL;

				delete temp;
			}
		}

		int front(){
			if(isEmpty()){
				cout << "Queue underflow" << endl;
				return -1;
			}
			return qFront->data;
		}

		int size(){
			int count = 0;
			Node* temp = qFront;
			while(temp != NULL){
				count++;
				temp = temp->next;
			}
			return count;
		}
};

int main(){
	Queue q;
	q.enqueue(15);
	q.enqueue(11);
	q.enqueue(17);
	q.enqueue(20);

	cout << "Size = " << q.size() << endl;
	if(q.isEmpty())
		cout << "Queue is empty" << endl;
	else
		cout << "Queue is not empty" << endl;

	cout << "The element at the front of the queue is: " << q.front() << endl;
	q.dequeue();
	q.dequeue();

	cout << "Size = " << q.size() << endl;
	cout << "The element at the front of the queue is: " << q.front() << endl;
	return 0;
}