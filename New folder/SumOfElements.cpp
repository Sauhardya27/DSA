#include <iostream>
using namespace std;

int sum(int arr[], int n){
	if(n < 1)
		return -1;
	if(n == 1)
		return arr[0];
	else
		return arr[0] + sum(arr+1, n-1);
}

int main(){
	int arr[] = {2, 4, 6, 1, 11, 17};
	cout << "Sum of all the elements of the array is: " << sum(arr, 6) << endl;
	return 0;
}