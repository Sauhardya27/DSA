#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity){
	//base case;
	//Traversing from right to left
	if(index == 0){
		if(weight[0] <= capacity)
			return value[0];
		else
			return 0;
	}

	int include = 0;
	if(weight[index] <= capacity)
		include = value[index] + solve(weight, value, index-1, capacity - weight[index]);

	int exclude = solve(weight, value, index-1, capacity);

	int ans = max(include, exclude);
	return ans;
}

int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){
	//base case;
	//Traversing from right to left
	if(index == 0){
		if(weight[0] <= capacity)
			return value[0];
		else
			return 0;
	}

	if(dp[index][capacity] != -1)
		return dp[index][capacity];

	int include = 0;
	if(weight[index] <= capacity)
		include = value[index] + solveMem(weight, value, index-1, capacity - weight[index], dp);

	int exclude = solveMem(weight, value, index-1, capacity, dp);

	dp[index][capacity] = max(include, exclude);
	return dp[index][capacity];
}

int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

	for(int w = weight[0]; w <= capacity; w++){
		if(weight[0] <= capacity)
			dp[0][w] = value[0];
		else
			dp[0][w] = 0;
	}

	for(int index=1; index<n; index++){
		for(int w=0; w<=capacity; w++){
			int include = 0;

			if(weight[index] <= w)
				include = value[index] + dp[index - 1][w - weight[index]];

			int exclude = dp[index - 1][w];

			dp[index][w] = max(include, exclude);
		}
	}
	return dp[n-1][capacity];
}

int solveOpt(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<int> curr(capacity+1, 0);

	for(int w = weight[0]; w <= capacity; w++){
		if(weight[0] <= capacity)
			curr[w] = value[0];
		else
			curr[w] = 0;
	}

	for(int index=1; index<n; index++){
		for(int w=capacity; w>=0; w--){
			int include = 0;

			if(weight[index] <= w)
				include = value[index] + curr[w - weight[index]];

			int exclude = curr[w];

			curr[w] = max(include, exclude);
		}
	}
	return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{	
	//Since only no. of items and capacity is changing and hence the size is n*maxweight + 1
	// vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	// return solveMem(weight, value, n-1, maxWeight, dp);

	// return solveTab(weight, value, n, maxWeight);
	return solveOpt(weight, value, n, maxWeight);
}