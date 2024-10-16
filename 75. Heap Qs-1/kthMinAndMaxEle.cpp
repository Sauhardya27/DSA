#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k){
	vector<int> ans;
	priority_queue<int> pq;

	// Step 1: Build max-heap for 1st k elements
	for (int i = 0; i < k; i++){
		pq.push(arr[i]);
	}

	// Step 2: For the rest of the elements, check
	// if element < pq.top() => if yes, then pop the top
	// element, then insert element into the queue
	for (int i = k; i < n; i++){
		if (arr[i] < pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
	}

	// Step 3: Return the top element
	ans.push_back(pq.top());

	priority_queue<int, vector<int>, greater<int>> minHeap;
	// Step 1: Build min-heap for 1st k elements
	for (int i = 0; i < k; i++){
		minHeap.push(arr[i]);
	}

	// Step 2: For the rest of the elements, check
	// if element > minHeap.top() => if yes, then pop the top
	// element, then insert element into the queue
	for (int i = k; i < n; i++){
		if (arr[i] > minHeap.top()){
			minHeap.pop();
			minHeap.push(arr[i]);
		}
	}

	// Step 3: Return the top element
	ans.push_back(minHeap.top());

	return ans;
}