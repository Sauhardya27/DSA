//Get minimum element from a stack in O(1) time and space complexity
#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    public:
    stack<int>s;
    int mini;    
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data > mini){
                s.push(data);
            }
            else{
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
        }
    }

    void pop() {
        if(s.empty())
            return;

        int curr = s.top();
        if(curr > mini){
            s.pop();
        }
        else{
            mini = 2*mini - curr;
            s.pop();
        }
    }

    int top() {
        if(s.empty())
            return -1;

        int curr = s.top();
        if(curr > mini)
            return curr;
        else    
            return mini;
    }

    int getMin() {
        if(s.empty())
            return -1;

        return mini;
    }  
};

int main(){
	SpecialStack st;
	st.push(13);
	st.push(47);
	st.push(8);

	cout << "Top element is: " << st.top() << endl;
	cout << "Minimum element in the present stack is: " << st.getMin() << endl;

	st.pop();

	cout << "Top element is: " << st.top() << endl;
	cout << "Minimum element in the present stack is: " << st.getMin() << endl;
	return 0;
}