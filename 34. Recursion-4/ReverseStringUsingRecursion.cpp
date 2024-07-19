#include <iostream>
using namespace std;

string reverse(int i, int j, string s){
	if(i>j)
		return s;
	else{
		swap(s[i], s[j]);
		return reverse(i+1, j-1, s);
	}	
}

int main(){
	string s = "abcde";
	cout << "Reversed string: " << reverse(0, 4, s) << endl;
	return 0;
}