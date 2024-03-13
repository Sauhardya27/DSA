#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);

	if(s.empty()){
		cout << "Stack is empty" <<endl;
	}
	else{
		cout << "Stack is not empty" << endl;
	}

	cout << "Top element: " << s.top() << endl;

	cout << "Stack elements: " << endl;
	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}