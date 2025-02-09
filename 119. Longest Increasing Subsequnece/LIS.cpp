#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr, int curr, int prev){
	if(curr == n)
		return 0;
		
	//include curr element
	int take = 0;
	if(prev == -1 || arr[curr] > arr[prev])
		take = 1 + solve(n, arr, curr+1, curr); //curr updates to next index, prev updates to curr
	
	//exclude curr element
	int dontTake = 0 + solve(n, arr, curr+1, prev);
	
	return max(take, dontTake);
}

int solveMem(int n, vector<int> &arr, int curr, int prev, vector<vector<int>> &dp){
	if(curr == n)
		return 0;
		
	if(dp[curr][prev+1] != -1)
		return dp[curr][prev+1];
		
	//include curr element
	int take = 0;
	if(prev == -1 || arr[curr] > arr[prev])
		take = 1 + solveMem(n, arr, curr+1, curr, dp); //curr updates to next index, prev updates to curr
		
	//exclude curr element
	int dontTake = 0 + solveMem(n, arr, curr+1, prev, dp);
	
	return dp[curr][prev+1] = max(take, dontTake); //Since prev ranges from -1 to n-1
	//we add 1 to make it valid
}

int solveTab(int n, vector<int> &arr){
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	//we create n+1 * n+1 becoz curr starts from n-1, and prev goes upto -1
	
	for(int curr=n-1; curr>=0; curr--){
		for(int prev=curr-1; prev>=-1; prev--){
			
			int take = 0;
			if(prev == -1 || arr[curr] > arr[prev])
				take = 1 + dp[curr+1][curr+1]; //curr updates to next index, prev updates to curr
				
			//exclude curr element
			int dontTake = 0 + dp[curr+1][prev+1];
			//Handle curr and prev in dp accordingly to avoid segmentation fault (index out of bounds)
			
			dp[curr][prev+1] = max(take, dontTake); //Since prev ranges from -1 to n-1
		}
	}
	return dp[0][0];
}

int solveOpt(int n, vector<int> &arr){
	vector<int> currRow(n+1, 0);
	vector<int> nextRow(n+1, 0);
	
	for(int curr=n-1; curr>=0; curr--){
		for(int prev=curr-1; prev>=-1; prev--){
			
			int take = 0;
			if(prev == -1 || arr[curr] > arr[prev])
				take = 1 + nextRow[curr+1]; //curr updates to next index, prev updates to curr
				
			//exclude curr element
			int dontTake = 0 + nextRow[prev+1];
			//Handle curr and prev in dp accordingly to avoid segmentation fault (index out of bounds)
			
			currRow[prev+1] = max(take, dontTake); //Since prev ranges from -1 to n-1
		}
		nextRow = currRow;
	}
	return nextRow[0];
}

int lis(vector<int>& arr) {
	int n = arr.size();
	// return solve(n, arr, 0, -1);
	
	// vector<vector<int>> dp(n, vector<int>(n+1, -1));
	// return solveMem(n, arr, 0, -1, dp);
	
	// return solveTab(n, arr);
	return solveOpt(n, arr);
}