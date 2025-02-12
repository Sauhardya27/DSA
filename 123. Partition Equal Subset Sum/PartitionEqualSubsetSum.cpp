#include <bits/stdc++.h>
using namespace std;

bool solve(int index, vector<int>& arr, int n, int target){
	if(index >= n)
		return 0;
	if(target < 0)
		return 0;
	if(target == 0)
		return 1;
		
	bool inc = solve(index+1, arr, n, target-arr[index]);
	bool exc = solve(index+1, arr, n, target);
	
	return inc | exc;
}

bool solveMem(int index, vector<int>& arr, int n, int target, vector<vector<int>> &dp){
	if(index >= n)
		return 0;
	if(target < 0)
		return 0;
	if(target == 0)
		return 1;
		
	if(dp[index][target] != -1)
		return dp[index][target];
		
	bool inc = solveMem(index+1, arr, n, target-arr[index], dp);
	bool exc = solveMem(index+1, arr, n, target, dp);
	
	return dp[index][target] = inc | exc;
}

bool solveTab(vector<int>& arr, int n, int t){
	vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
	
	for(int i=0; i<=n; i++)
		dp[i][0] = 1;
	
	for(int index=n-1; index>=0; index--){
		for(int target=1; target<=t; target++){
			bool inc = 0;
			
			if(target-arr[index] >= 0)
				inc = dp[index+1][target-arr[index]];
				
			bool exc = dp[index+1][target];
			
			dp[index][target] = inc | exc;
		}
	}
	return dp[0][t];
}

bool solveOpt(vector<int>& arr, int n, int t){
	vector<int> curr(t+1, 0);
	vector<int> next(t+1, 0);
	
	curr[0] = 1;
	next[0] = 1;
	
	for(int index=n-1; index>=0; index--){
		for(int target=1; target<=t; target++){
			bool inc = 0;
			
			if(target-arr[index] >= 0)
				inc = next[target-arr[index]];
				
			bool exc = next[target];
			
			curr[target] = inc | exc;
		}
		next = curr;
	}
	return next[t];
}

bool equalPartition(vector<int>& arr) {
	int n = arr.size();
	int totalSum = 0;
	
	for(int i=0; i<n; i++)
		totalSum += arr[i];
	
	if(totalSum & 1)
		return 0;
		
	int target = totalSum/2;
	// return solve(0, arr, n, target);
	
	
	// vector<vector<int>> dp(n, vector<int>(target+1, -1));
	// return solveMem(0, arr, n, target, dp);
	// return solveTab(arr, n, target);
	return solveOpt(arr, n, target);
}