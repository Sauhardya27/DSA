#include <iostream>
using namespace std;

class Heap{
	public:
	int arr[100];
	int size;

	Heap(){
		size = 0;
	}

	void insert(int x){
		int index = size++;
		arr[index] = x;

		while(index > 0){
			int parent = (index-1)/2;

			if(arr[index] > arr[parent]){
				swap(arr[index], arr[parent]);
				index = parent;
			}
			else
				return;
		}
	}

	void deleteHeap(){
		if(size == 0){
			cout << "Heap is empty" << endl;
			return;
		}

		arr[0] = arr[size-1];
		size--;

		int i=0;
		while(i<size){
			int leftChild = 2*i + 1, rightChild = 2*i + 2;

			if(leftChild < size && arr[leftChild] > arr[i]){
				swap(arr[i], arr[leftChild]);
				i = leftChild;
			}
			else if(rightChild < size && arr[rightChild] > arr[i]){
				swap(arr[i], arr[rightChild]);
				i = rightChild;
			}
			else
				return;
		}
	}

	void print(){
		if(size == 0){
			cout << "Heap is empty" << endl;
			return;
		}
		for(int i=0; i<size; i++)
			cout << arr[i] << " ";

		cout << endl;
	}
};

void heapify(int arr[], int n, int i){
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

int main(){
	Heap h;
	h.insert(5);
	h.insert(21);
	h.insert(1);
	h.insert(54);
	h.insert(14);
	h.print();

	h.deleteHeap();
    h.print();

	int arr[6] = {54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2 - 1; i>=0; i--) {
        heapify(arr, n, i);
    }

    cout << "Heapified array : ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
	return 0;
}