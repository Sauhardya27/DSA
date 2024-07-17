#include <iostream>
using namespace std;

string removeDuplicates(string s){
	string sol;
	for (char c : s){
		if (!sol.empty() && sol.back() == c){
			sol.pop_back();
		}
		else{
			sol.push_back(c);
		}
	}
	return sol;
}

int main(){
	string s = "abbaca";
	cout << "Modified string: " << removeDuplicates(s) << endl;
	return 0;
}