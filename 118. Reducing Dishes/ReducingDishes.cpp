#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &satisfaction, int index, int time){
	if (index == satisfaction.size())
		return 0;

	int inc = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1);
	int exc = 0 + solve(satisfaction, index + 1, time); // Don't inc the time if not considered

	return max(inc, exc);
}

int solveMem(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp){
	if (index == satisfaction.size())
		return 0;

	if (dp[index][time] != -1)
		return dp[index][time];

	int inc = satisfaction[index] * (time + 1) + solveMem(satisfaction, index + 1, time + 1, dp);
	int exc = 0 + solveMem(satisfaction, index + 1, time, dp); // Don't inc the time if not considered

	dp[index][time] = max(inc, exc);
	return dp[index][time];
}

int solveTab(vector<int> &satisfaction){
	int n = satisfaction.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int index = n - 1; index >= 0; index--){
		for (int time = index; time >= 0; time--){
			int inc = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
			int exc = 0 + dp[index + 1][time];
			dp[index][time] = max(inc, exc);
		}
	}
	return dp[0][0];
}

int solveOpt(vector<int> &satisfaction){
	int n = satisfaction.size();
	vector<int> curr(n + 1, 0);
	vector<int> next(n + 1, 0);

	for (int index = n - 1; index >= 0; index--){
		for (int time = index; time >= 0; time--){
			int inc = satisfaction[index] * (time + 1) + next[time + 1];
			int exc = 0 + next[time];
			curr[time] = max(inc, exc);
		}
		next = curr;
	}
	return next[0];
}

int maxSatisfaction(vector<int> &satisfaction){
	sort(satisfaction.begin(), satisfaction.end());
	// return solve(satisfaction, 0, 0);
	int n = satisfaction.size();

	// vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	// return solveMem(satisfaction, 0, 0, dp);
	// return solveTab(satisfaction);
	return solveOpt(satisfaction);
}