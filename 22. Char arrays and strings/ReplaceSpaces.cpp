#include <bits/stdc++.h> 
using namespace std;
string replaceSpaces(string &str){
	string sol;
	for(int i=0; i<str.size(); i++){
		if(str[i] == ' '){
			sol.push_back('@');
			sol.push_back('4');
			sol.push_back('0');
		}
		else
			sol.push_back(str[i]);
	}
	return sol;
}

int main(){
	string s = "the sky is blue";
	cout << "Reversed string: " << replaceSpaces(s) << endl;
	return 0;
}