#include <iostream>
using namespace std;

bool checkPalindrom(const string &s){
	int n = s.size();
	if(n<=1)
		return true;

	if(s[0] != s[n-1])
		return false;

	return checkPalindrom(s.substr(1, n-2));
}

int main(){
	string s = "nana";
	if(checkPalindrom(s))
		cout << "The given string is a palindrome" << endl;
	else
		cout << "The given string is not a palindrome" << endl;
	return 0;
}