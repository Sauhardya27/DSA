#include <bits/stdc++.h> 
using namespace std;

class NQueue{
    int n;
    int s;
    int freeSpot;
    int* arr;
    int* front;
    int* rear;
    int* next;
public:
    // Initialize your data structure.
    NQueue(int n, int s){
        n = n;
        s = s;
        freeSpot = 0;

        arr = new int[s];

        front = new int[n];
        rear = new int[n];

        for(int i=0; i<n; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[s];
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        //Overflow condition
        if(freeSpot == -1)
            return false;

        //find index to insert
        int index = freeSpot;

        //Update freeSpot
        freeSpot = next[index];

        //Check whether it is the first element to insert in the queue
        if(front[m-1] == -1)
            front[m-1] = index;
        else    
            next[rear[m-1]] = index;

        //Update next array to denote that element has been inserted at that index
        next[index] = -1;

        //Update rear index of that queue
        rear[m-1] = index;

        //Insert element in the array
        arr[index] = x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        //Underflow condition
        if(front[m-1] == -1)
            return -1;

        //Get the index to dequeue the element
        int index = front[m-1];

        //Update the front index to point to next index of that queue
        front[m-1] = next[index];

        //Update the next array to point to the next avail freeSpot
        next[index] = freeSpot;

        //Update freeSpot to utilize the space which has been emptied just now
        freeSpot = index;

        return arr[index];
    }
};

int main(){
	NQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;
	return 0;
}