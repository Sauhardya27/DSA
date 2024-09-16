#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s)
{
	stack<int> st;
	st.push(-1);
	int maxLength = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			st.push(i);
		}
		else
		{
			st.pop();
			if (!st.empty())
			{
				// Calculate the length of the valid substring
				int currentLength = i - st.top();
				maxLength = max(maxLength, currentLength);
			}
			else
			{
				// Push the index of the current ')' to reset the base
				st.push(i);
			}
		}
	}
	return maxLength;
}

int main()
{
	string s;
	cout << "Enter the expression: ";
	cin >> s;

	cout << longestValidParentheses(s) << endl;
	return 0;
}