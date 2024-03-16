#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &stack, int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }

    int num = stack.top();
    stack.pop();

    insertAtBottom(stack, x);
    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    insertAtBottom(stack, num);
}

void printStack(stack<int>s){
	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
	cout<<endl;
}

int main(){
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << "Original Stack:" << endl;
	printStack(s);

	reverseStack(s);
	cout << "Modified Stack:" << endl;
	printStack(s);


	return 0;
}