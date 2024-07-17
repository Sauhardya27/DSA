#include <iostream>
using namespace std;

string removeOccurrences(string s, string part){
	while (s.size() != 0 && s.find(part) < s.size())
		s.erase(s.find(part), part.size());
	return s;
}

int main(){
	string s = "daabcbaabcbc", part = "abc";
	cout << "Modified string: " << removeOccurrences(s, part) << endl;
	return 0;
}