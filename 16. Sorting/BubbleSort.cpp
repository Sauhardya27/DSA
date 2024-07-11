#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n){   
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}
//Alternate loop iteration:
//i = 0 -> lt n-1;
//j = 0 -> lt n-i-1

int main(){
	vector<int> arr = {29,72,98,13,87,66,52,51,36};
	int n = 9;

	cout << "Array before sorting: ";
	for(int i=0; i<n; i++)
		cout << arr[i] <<" ";
	cout << endl;

	bubbleSort(arr, n);

	cout << "Array after sorting: ";
	for(int i=0; i<n; i++)
		cout << arr[i] <<" ";
	cout << endl;
	return 0;
}