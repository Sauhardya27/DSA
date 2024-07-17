#include <iostream>
using namespace std;

string reverseWords(string s){
	int i = 0, n = s.size();
        string newString;
        while(i<n){
            while(i<n && s[i] == ' ')
                i++;

            int j = i;

            while(j<n && s[j] != ' ')
                j++;

            if(i<j){
                string w = s.substr(i, j-i);
                newString.empty() ? (newString = w) : (newString = w + " " + newString);
            }
            i = j + 1;
        }
        return newString;
}

int main(){
	string s = "the sky is blue";
	cout << "Reversed string: " << reverseWords(s) << endl;
	return 0;
}