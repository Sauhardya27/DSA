#include <iostream>
using namespace std;

int partition(int* arr, int s, int e){
    int pivot = arr[s];
    int count = 0;

    // STEP 1: Count the number of elements less than pivot element => count
    for(int i = s + 1; i <= e; i++){
        if(arr[i] < pivot)
            count++;
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    // STEP 2: Move elements smaller than pivot to its left and greater to its right
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot) {
            i++;
        }
        while(arr[j] >= pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    // STEP 3: Return pivot index
    return pivotIndex;
}

int quickSelect(int* arr, int s, int e, int k){
    if(s <= e){
        int pivotIndex = partition(arr, s, e);

        // If the pivotIndex is the k-th element, return it
        if(pivotIndex == k)
            return arr[pivotIndex];

        // If k is less than pivotIndex, search in the left part
        if(k < pivotIndex)
            return quickSelect(arr, s, pivotIndex - 1, k);
        
        // If k is greater, search in the right part
        return quickSelect(arr, pivotIndex + 1, e, k);
    }

    // If k is out of bounds
    return -1;
}

int main(){
    int arr[] = {3, 1, 4, 5, 2};
    int n = 5;
    int k = 2; // Find the 3rd smallest element (0-based index)

    cout << "Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int result = quickSelect(arr, 0, n - 1, k);

    if(result != -1)
        cout << k + 1 << "th smallest element is: " << result << endl;
    else
        cout << "Invalid input for k" << endl;

    return 0;
}
