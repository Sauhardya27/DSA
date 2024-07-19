#include <iostream>
using namespace std;

int merge(int* arr, int s, int e){
	int mid = s + (e-s)/2;
	int cnt = 0;

	int len1 = mid - s + 1;
	int len2 = e - mid;

	int* first = new int[len1];
	int* second = new int[len2];

	int k = s;
	for(int i=0; i<len1; i++)
		first[i] = arr[k++];

	k = mid+1;
	for(int i=0; i<len2; i++)
		second[i] = arr[k++];

	int index1 = 0, index2 = 0;
	k = s;
	while(index1 < len1 && index2 < len2){
		if(first[index1] < second[index2])
			arr[k++] = first[index1++];
		else{
			arr[k++] = second[index2++];
			cnt += (len1 - index1); //Extra line added
		}
	}

	while(index1 < len1)
		arr[k++] = first[index1++];

	while(index2 < len2)
		arr[k++] = second[index2++];

	delete[] first;
    delete[] second;

	return cnt;
}

int mergeSort(int* arr, int s, int e){
	int cnt = 0;
	if(s >= e)
		return cnt;

	int mid = s + (e-s)/2;
	cnt += mergeSort(arr, s, mid);
	cnt += mergeSort(arr, mid+1, e);
	cnt += merge(arr, s, e);

	return cnt;
}

int countInversions(int* arr, int s, int e){
	return mergeSort(arr, s, e);
}

int main(){
	int arr[] = {5, 4, 3, 2, 1};
	int n = 5;

	cout << "No. of inversions: " << countInversions(arr, 0, n-1) << endl;

	return 0;
}