#include <bits/stdc++.h> 
using namespace std;
void heapify(vector<int> &arr, int n, int i){
    int smallest = i, left = 2*i + 1, right = 2*i + 2;

    if(left < n && arr[smallest] > arr[left])
        smallest = left;

    if(right < n && arr[smallest] > arr[right])
        smallest = right;

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i=n/2 - 1; i>=0; i--)
        heapify(arr, n, i);

    return arr;
}

int main(){
	vector<int> arr;
	arr = {54, 53, 55, 52, 50};

	arr = buildMinHeap(arr);

	cout << "Min heap: ";
	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << " ";

	cout << endl;
	return 0;
}
