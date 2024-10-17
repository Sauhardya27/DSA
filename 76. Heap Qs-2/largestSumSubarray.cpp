#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &arr){
	// Using Kadane's algorithm
	int n = arr.size();
	int maxSum = arr[0];
	int currentSum = arr[0];

	for (int i = 1; i < n; i++){
		currentSum = max(arr[i], currentSum + arr[i]);
		maxSum = max(maxSum, currentSum);
	}

	return maxSum;
}