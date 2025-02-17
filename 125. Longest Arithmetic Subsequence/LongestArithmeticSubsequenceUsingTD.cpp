#include <bits/stdc++.h>
using namespace std;

int solve(int index, int diff, vector<int>& arr){
	if(index < 0)
		return 0;
		
	int ans = 0;
	for(int j=index-1; j>=0; j--){
		if(arr[index] - arr[j] == diff)
			ans = max(ans, 1 + solve(j, diff, arr));
			//Adding 1, considering the current pair
	}
	return ans;
}

int solveMem(int index, int diff, vector<int>& arr, unordered_map<int, int> dp[]){
	if(index < 0)
		return 0;
		
	if(dp[index].count(diff))
		return dp[index][diff];
		
	int ans = 0;
	for(int j=index-1; j>=0; j--){
		if(arr[index] - arr[j] == diff)
			ans = max(ans, 1 + solveMem(j, diff, arr, dp));
			//Adding 1, considering the current pair
	}
	return dp[index][diff] = ans;
}

int lengthOfLongestAP(vector<int>& arr) {
	int n = arr.size();
	if(n <= 2)
		return n;
	
	unordered_map<int, int> dp[n+1];
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			// ans = max(ans, 2 + solve(i, arr[j] - arr[i], arr));
			//Adding two because of the last two elements from where we are starting
			ans = max(ans, 2 + solveMem(i, arr[j] - arr[i], arr, dp));
		}
	}
	return ans;
}