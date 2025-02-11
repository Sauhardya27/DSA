#include <bits/stdc++.h>
using namespace std;

int solve(int dice, int faces, int target){
	if(target < 0)
		return 0;
	if(dice != 0 && target == 0)
		return 0;
	if(dice == 0 && target != 0)
		return 0;
	if(dice == 0 && target == 0)
		return 1;
	
	long long ans = 0;  
	for(int i=1; i<=faces; i++){
		ans = ans + solve(dice-1, faces, target-i);
	}
	
	return ans;
}

int solveMem(int dice, int faces, int target, vector<vector<long long>> &dp){
	if(target < 0)
		return 0;
	if(dice != 0 && target == 0)
		return 0;
	if(dice == 0 && target != 0)
		return 0;
	if(dice == 0 && target == 0)
		return 1;
		
	if(dp[dice][target] != -1)
		return dp[dice][target];
	
	long long ans = 0;  
	for(int i=1; i<=faces; i++){
		ans = ans + solveMem(dice-1, faces, target-i, dp);
	}
	
	return dp[dice][target] = ans;
}

int solveTab(int d, int f, int t){
	vector<vector<long long>> dp(d+1, vector<long long>(t+1, 0));
	dp[0][0] = 1;
	
	for(int dice=1; dice<=d; dice++){
		for(int target=1; target<=t; target++){
			long long ans = 0;  
			for(int i=1; i<=f; i++){
				if(target-i >= 0)
					ans = ans + dp[dice-1][target-i];
			}
			dp[dice][target] = ans;
		}
	}
	return dp[d][t];
}

int solveOpt(int d, int f, int t){
	vector<long long> prev(t+1, 0); //Refers to target made by d-1th dice
	vector<long long> curr(t+1, 0); //Refers to target made by dth dice
	
	prev[0] = 1;
	
	for(int dice=1; dice<=d; dice++){
		for(int target=1; target<=t; target++){
			long long ans = 0;  
			for(int i=1; i<=f; i++){
				if(target-i >= 0)
					ans = ans + prev[target-i];
			}
			curr[target] = ans;
		}
		prev = curr;
	}
	return prev[t];
}

int noOfWays(int m, int n, int x) {
	// return solve(n, m, x);
	
	// vector<vector<long long>> dp(n+1, vector<long long>(x+1, -1));
	//Because we are trying to access nth and xth index so n+1 * x+1
	// return solveMem(n, m, x, dp);
	
	// return solveTab(n, m, x);
	return solveOpt(n, m, x);
}