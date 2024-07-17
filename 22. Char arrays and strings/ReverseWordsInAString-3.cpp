#include <iostream>
using namespace std;

void reverse(string &s, int st, int e){
	while (st < e)
		swap(s[st++], s[e--]);
}

string reverseWords(string s){
	int n = s.size();
	int i = 0, prev = 0;
	while (i <= n){
		if (s[i] == ' ' || i == n){
			reverse(s, prev, i - 1);
			prev = i + 1;
		}
		i++;
	}
	return s;
}

int main(){
	string s = "Let's take LeetCode contest";
	cout << "Reversed string: " << reverseWords(s) << endl;
	return 0;
}