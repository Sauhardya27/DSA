#include <bits/stdc++.h> 
#include <stack>
using namespace std;

void solve(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    solve(myStack, x);
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
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

	pushAtBottom(s, 60);
	cout << "Modified Stack:" << endl;
	printStack(s);
}
