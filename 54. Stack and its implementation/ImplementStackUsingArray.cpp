#include <iostream>
using namespace std;

class Stack{
	public:
	int* arr;
	int top;
	int size;

	Stack(int s){
		this->size = s;
		arr = new int[s];
		top = -1;
	}

	void push(int data){
		if(size - top > 1){
			top++;
			arr[top] = data;
		}
		else	
			cout << "Stack Overflow: " << endl;
	}

	bool isEmpty(){
		return top == -1;
	}

	void pop(){
		if(isEmpty())
			cout << "Stack underflow" <<endl;
		else
			top--;
	}

	int peek(){
		if(isEmpty()){
			cout << "Stack underflow" << endl;
			return -1;
		}
		else
			return arr[top];
	}
};



int main(){
	Stack s(5);
	s.push(5);
	s.push(7);
	cout<<"Top element : "<< s.peek()<<endl;
	s.pop();
	cout<<"Top element : "<< s.peek()<<endl;

	if(s.isEmpty()) {
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Stack is not Empty" << endl;
    }

	return 0;
}