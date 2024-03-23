#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
class Deque
{
public:
    int* arr;
    int front, rear;
    int size;
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int value)
    {
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = value;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int value)
    {
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front != 0 && rear == size-1){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){
            return -1;
        }
        
        int temp = arr[front];
        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return temp;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()){
            return -1;
        }
        
        int temp = arr[rear];
        arr[rear] = -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
        return temp;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        return front == -1;
    }

    // Returns true if the deque is full. Otherwise returns false.
	//The following code may vary acc to diff coding platforms and questions
    bool isFull()
    {
        return ((rear == size-1 && front == 0) || (front != 0 && rear == (front-1)%(size-1)));
    }
};

int main(){
	return 0;
}