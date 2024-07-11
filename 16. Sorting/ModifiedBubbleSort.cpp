#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n){   
    for(int i=1; i<n; i++){
        bool swapped = false;
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;    
            }
        }
        if(swapped == false)
            break; //Array is already sorted
    }
}

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