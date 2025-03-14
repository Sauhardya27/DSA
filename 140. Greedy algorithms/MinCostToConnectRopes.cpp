#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int>& arr) {
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	int n = arr.size();
	
	for(auto &num: arr)
		pq.push(num);
		
	long long cost = 0;
	while(pq.size() > 1){
		long long first = pq.top();
		pq.pop();
		
		long long second = pq.top();
		pq.pop();
		
		long long mergedLength = first + second;
		cost += mergedLength;
		pq.push(mergedLength);
	}
	
	return cost;
}