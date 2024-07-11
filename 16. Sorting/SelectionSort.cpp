#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int n){   
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
	vector<int> arr = {29,72,98,13,87,66,52,51,36};
	int n = 9;

	cout << "Array before sorting: ";
	for(int i=0; i<n; i++)
		cout << arr[i] <<" ";
	cout << endl;

	selectionSort(arr, n);

	cout << "Array after sorting: ";
	for(int i=0; i<n; i++)
		cout << arr[i] <<" ";
	cout << endl;
	return 0;
}