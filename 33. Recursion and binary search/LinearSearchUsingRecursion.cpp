#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int key){
	if(n < 1)
		return false;
	if(arr[0] == key)
		return true;
	else
		return linearSearch(arr+1, n-1, key);
}

int index(int arr[], int n, int key, int i){
	if(n < 1)
		return -1;
	if(arr[i] == key)
		return i;
	else
		return index(arr+1, n-1, key, i+1);
}

int main(){
	int arr[] = {2, 4, 6, 1, 11, 17};
	/*if(linearSearch(arr, 6, 0))
		cout << "Element found" << endl;
	else
		cout << "Element is not present in the array" << endl;*/

	int key = 17;
	cout << "Index of " << key << " is " << index(arr, 6, key, 0) << endl;
	return 0;
}