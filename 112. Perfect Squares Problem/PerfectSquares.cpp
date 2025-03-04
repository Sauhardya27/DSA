#include <bits/stdc++.h>
using namespace std;

int solve(int n){
	if (n == 0)
		return 0;

	int ans = n;
	for (int i = 1; i * i <= n; i++){
		int temp = i * i;
		ans = min(ans, 1 + solve(n - temp));
	}
	return ans;
}

int solveMem(int n, vector<int> &dp){
	if (n == 0)
		return 0;

	if (dp[n] != -1)
		return dp[n];

	int ans = n;
	for (int i = 1; i * i <= n; i++){
		int temp = i * i;
		ans = min(ans, 1 + solveMem(n - temp, dp));
	}
	dp[n] = ans;
	return dp[n];
}

int solveTab(int n){
	// In case of finding min, we initialize with INT_MAX and
	// In case of max, we initialize with INT_MIN
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j * j <= n; j++){
			int temp = j * j;

			if (i - temp >= 0)
				dp[i] = min(dp[i], 1 + dp[i - temp]);
		}
	}
	return dp[n];
}

int MinSquares(int n){
	// vector<int> dp(n+1, -1);
	// return solveMem(n, dp);
	return solveTab(n);
}