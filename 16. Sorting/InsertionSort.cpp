#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j=i-1;
        for(; j>=0; j--){
            if(arr[j] > temp)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = temp;
    }
}

int main(){
	vector<int> arr = {29,72,98,13,87,66,52,51,36};
	int n = 9;

	cout << "Array before sorting: ";
	for(int i=0; i<n; i++)
		cout << arr[i] <<" ";
	cout << endl;

	insertionSort(arr, n);

	cout << "Array after sorting: ";
	for(int i=0; i<n; i++)
		cout << arr[i] <<" ";
	cout << endl;
	return 0;
}