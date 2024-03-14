#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>&inputStack, int count, int size){
   if(count == size/2){
      inputStack.pop();
      return;
   }

   int num = inputStack.top();
   inputStack.pop();

   solve(inputStack, count+1, size);
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	//Approach 1: In O(n) time and space complexity
   /*stack<int> s;
   int count = 0;
   while(count < N/2){
      s.push(inputStack.top());
      inputStack.pop();
      count++;
   }
   inputStack.pop();
   while(count != 0){
      inputStack.push(s.top());
      s.pop();
      count--;
   }*/
   
   //Approach 2: Using recursion
   int count = 0;
   solve(inputStack, count, N);
}

int main(){
	stack<int> S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	S.push(5);

	deleteMiddle(S, 5);
	cout << "Stack elements: ";
	while(!S.empty()){
		cout << S.top() << " ";
		S.pop();
	}
	cout << endl;
	return 0;
}