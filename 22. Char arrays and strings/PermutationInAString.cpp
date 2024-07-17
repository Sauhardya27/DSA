#include <iostream>
using namespace std;

bool checkEqual(int a[26], int b[26]){
	for (int i = 0; i < 26; i++){
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}

bool checkInclusion(string s1, string s2){
	int count1[26] = {0};

	for (int i = 0; i < s1.size(); i++)
		count1[s1[i] - 'a']++;

	// traverse s2 string in window of size s1 length and compare
	int i = 0;
	int windowSize = s1.size();
	int count2[26] = {0};

	// running for 1st window
	while (i < windowSize && i < s2.size()){
		count2[s2[i] - 'a']++;
		i++;
	}

	if (checkEqual(count1, count2))
		return 1;

	// process the remaining windows
	while (i < s2.size()){
		char newChar = s2[i];
		count2[newChar - 'a']++;

		char oldChar = s2[i - windowSize];
		count2[oldChar - 'a']--;

		if (checkEqual(count1, count2))
			return 1;
		i++;
	}
	return 0;
}

int main(){
	string s1 = "ab", s2 = "eidbaooo";
	if(checkInclusion(s1, s2))
		cout << "Permutation of given substring is present" << endl;
	else
		cout << "Permutation of given substring is not present" << endl;

	return 0;
}