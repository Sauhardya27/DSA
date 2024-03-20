#include <bits/stdc++.h>
using namespace std;
class Queue {
private:
  int *arr;
  int size;
  int qFront;
  int rear;

public:
  Queue() {
    arr = new int[1000001];
    qFront = 0;
    rear = 0;
    size = 1000001;
  }

  bool isEmpty() {
    if (qFront == rear) {
      return true;
    } else {
      return false;
    }
  }

  void enqueue(int data) {
    if (rear == size)
      return;
    else{
      arr[rear] = data;
        rear++;  
    }
  }

  int dequeue() {
    if (isEmpty())
      return -1;

    else {
      int val = arr[qFront];
      arr[qFront] = -1;
      qFront++;
      if (qFront == rear) {
        qFront = 0;
        rear = 0;
      }
      return val;
    }
  }

  int front() {
    if (isEmpty())
      return -1;
    else
      return arr[qFront];
  }

  int qsize(){
	if (isEmpty())
      return -1;
	
	return rear-qFront;
  }
};

int main(){
	Queue q;
	q.enqueue(5);
	q.enqueue(16);
	q.enqueue(8);
	q.enqueue(27);

	cout << "Size = " << q.qsize() << endl;
	if(q.isEmpty())
		cout << "Queue is empty" << endl;
	else
		cout << "Queue is not empty" << endl;

	cout << "The element at the front of the queue is: " << q.front() << endl;
	int ans = q.dequeue();
	ans = q.dequeue();

	cout << "Size = " << q.qsize() << endl;
	cout << "The element at the front of the queue is: " << q.front() << endl;
	return 0;
}