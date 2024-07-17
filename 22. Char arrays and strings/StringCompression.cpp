#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char> &chars){
	int i = 0;
	int ansIndex = 0;
	int n = chars.size();

	while (i < n){
		int j = i + 1;
		while (j < n && chars[i] == chars[j])
			j++;

		chars[ansIndex++] = chars[i];
		int count = j - i;

		if (count > 1){
			string cnt = to_string(count);
			for (char ch : cnt)
				chars[ansIndex++] = ch;
		}
		i = j;
	}

	return ansIndex;
}

int main(){
	vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	vector<char> chars2 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
	cout << "Modified string 1: " << compress(chars1) << endl;
	cout << "Modified string 2: " << compress(chars2) << endl;
	return 0;
}