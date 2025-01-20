#include <bits/stdc++.h>
using namespace std;

// Using Top-Down Approach
int solve1(vector<int> &cost, int i, vector<int> &dp)
{
	if (i >= cost.size())
		return 0;

	if (dp[i] != -1)
		return dp[i];

	dp[i] = cost[i] + min(solve1(cost, i + 1, dp), solve1(cost, i + 2, dp));
	return dp[i];
}

// Using Bottom-Up Approach
int solve2(vector<int> &cost)
{
	int n = cost.size();
	vector<int> dp(n + 1);

	dp[0] = cost[0];
	dp[1] = cost[1];

	for (int i = 2; i < n; i++)
	{
		dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
	}

	return min(dp[n - 1], dp[n - 2]);
}

int minCostClimbingStairs(vector<int> &cost)
{
	// int n = cost.size();

	// vector<int> dp(n + 1, -1);

	// int ans = min(solve1(cost, 0, dp), solve1(cost, 1, dp));

	int ans = solve2(cost);
	return ans;
}