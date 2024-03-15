#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char>st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch =='['){
            st.push(ch);
        }
        else{
            if (!st.empty()) {
              char top = st.top();
              if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
                  (ch == ']' && top == '[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }

    if(st.empty())
        return true;
    else    
        return false;
}

int main(){
	string s;
	cout << "Enter the expression: " ;
	cin >> s;

	if(isValidParenthesis(s))
		cout << "The entered expression is a balanced expression" << endl;
	else	
		cout << "The entered expression is not a balanced expression" << endl;
	return 0;
}