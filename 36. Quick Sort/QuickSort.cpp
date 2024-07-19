#include <iostream>
using namespace std;

int partition(int* arr, int s, int e){
	int pivot = arr[s];
	int count = 0;

	//STEP 1: Count the no of elements less than pivot element => count
	//Swap the pivot element with the "s+count" element to place it to its correct position
	for(int i=s+1; i<=e; i++){
		if(arr[i] < pivot)
			count++;
	}

	int pivotIndex = s + count;
	swap(arr[s], arr[pivotIndex]);

	//STEP 2: Take two pointers as shown below, and move all the elements smaller than 
	//pivot to its left and all the elements greater than pivot to its right
	int i = s, j = e;
	while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] >= pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

	//STEP 3: Return pivot index
    return pivotIndex;
}

void quickSort(int* arr, int s, int e){
	if(s>=e)
		return;

	int pivot = partition(arr, s, e);
	quickSort(arr, s, pivot-1);
	quickSort(arr, pivot+1, e);
}

int main(){
	int arr[] = {3, 1, 4, 5, 2};
	int n = 5;

	cout << "Before sorting: ";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;

	quickSort(arr, 0, n-1);

	cout << "After sorting: ";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}