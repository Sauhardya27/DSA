#include <bits/stdc++.h>
using namespace std;

int solve(string &a, string &b, int i, int j){
	if(i == a.length())
		return 0;

	if(j == b.length())
		return 0;

	int ans = 0;
	if(a[i] == b[j])
		ans = 1 + solve(a, b, i+1, j+1);
	else
		ans = max(solve(a, b, i, j+1), solve(a, b, i+1, j));

	return ans;
}

int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
	if(i == a.length())
		return 0;

	if(j == b.length())
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int ans = 0;
	if(a[i] == b[j])
		ans = 1 + solveMem(a, b, i+1, j+1, dp);
	else
		ans = max(solveMem(a, b, i, j+1, dp), solveMem(a, b, i+1, j, dp));

	return dp[i][j] = ans;
}

int solveTab(string &a, string &b){
	int n1 = a.size();
	int n2 = b.size();

	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

	for(int i=n1-1; i>=0; i--){
		for(int j=n2-1; j>=0; j--){
			int ans = 0;

			if(a[i] == b[j])
				ans = 1 + dp[i+1][j+1];
			else
				ans = max(dp[i][j+1], dp[i+1][j]);

			dp[i][j] = ans;
		}
	}
	return dp[0][0];
}

int solveOpt(string &a, string &b){
	int n1 = a.size();
	int n2 = b.size();

	vector<int> curr(n2+1, 0);
	vector<int> next(n2+1, 0);

	for(int i=n1-1; i>=0; i--){
		for(int j=n2-1; j>=0; j--){
			int ans = 0;

			if(a[i] == b[j])
				ans = 1 + next[j+1];
			else
				ans = max(curr[j+1], next[j]);

			curr[j] = ans;
		}
		next = curr;
	}
	return next[0];
}

int longestCommonSubsequence(string text1, string text2) {
	// return solve(text1, text2, 0, 0);
	// int n1 = text1.size();
	// int n2 = text2.size();

	// vector<vector<int>> dp(n1, vector<int>(n2, -1));
	// return solveMem(text1, text2, 0, 0, dp);
	// return solveTab(text1, text2);
	return solveOpt(text1, text2);
}