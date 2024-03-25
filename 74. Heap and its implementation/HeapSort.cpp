#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
	int largest = i, left = 2*i + 1, right = 2*i + 2;

	if(left < n && arr[largest] < arr[left])
		largest = left;

	if(right < n && arr[largest] < arr[right])
		largest = right;

	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(vector<int> &arr, int size){
	while(size > 0) {
        swap(arr[0], arr[size-1]);

        size--;
        
        heapify(arr, size, 0);
    }
}

int main(){
	vector<int> arr = {54, 53, 55, 52, 50};
	int size = 5;

	//Build Heap
	for(int i = size/2 - 1; i>=0; i--) {
        heapify(arr, size, i);
    }

	heapSort(arr, size);

	cout << "Sorted array : ";
    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
	return 0;
}