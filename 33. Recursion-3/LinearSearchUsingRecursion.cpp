#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int k){
	if(size == 0)
		return false;
	if(arr[0] == k)
		return true;
	else
		return linearSearch(arr+1, size-1, k);
}

int main(){
	int arr[5] = {1, 2, 7, 4, 5};
	if(linearSearch(arr, 5, 3))
		cout << "Element found!" << endl;
	else 
		cout << "Element not found!" << endl;
	return 0;
}