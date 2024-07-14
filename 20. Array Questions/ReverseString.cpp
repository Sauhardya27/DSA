#include <iostream>
#include <vector>
using namespace std;

void reverseString(char s[], int n){
	int st = 0;
	int e = n - 1;
	while (st <= e){
		swap(s[st++], s[e--]);
	}
}

int main(){
	char arr[] = "hello";
	int n = 8;

	cout << "Original string: " << arr << endl;

	reverseString(arr, 5);

	cout << "Reversed string: " << arr << endl;
	return 0;
}