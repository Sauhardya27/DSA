#include <iostream>
using namespace std;

string reverse(int i, string s){
	int n = s.size();
	if(i>n/2)
		return s;
	else{
		swap(s[i], s[n-i-1]);
		return reverse(i+1, s);
	}	
}

int main(){
	string s = "abcde";
	cout << "Reversed string: " << reverse(0, s) << endl;
	return 0;
}