#include <bits/stdc++.h> 
#include <stack>
using namespace std;
void sortedInsert(stack<int> &s, int n){
	if(s.empty() || (!s.empty() && s.top() < n)){
		s.push(n);
		return;	
	}

	int num = s.top();
	s.pop();

	sortedInsert(s, n);
	s.push(num);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty())
		return;

	int num = stack.top();
	stack.pop();

	sortStack(stack);

	sortedInsert(stack, num);
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
	s.push(21);
	s.push(14);
	s.push(96);
	s.push(37);
	s.push(53);

	cout << "Original Stack:" << endl;
	printStack(s);

	sortStack(s);
	cout << "Modified Stack:" << endl;
	printStack(s);
	return 0;
}