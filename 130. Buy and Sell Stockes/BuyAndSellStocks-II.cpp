#include <bits/stdc++.h>
using namespace std;

int solve(int index, int buy, vector<int>& prices) {
	if (index == prices.size())
		return 0;

	int profit = 0;

	if (buy) {
		int canBuy = -prices[index] + solve(index + 1, 0, prices);
		int skipBuy = 0 + solve(index + 1, 1, prices);
		profit = max(canBuy, skipBuy);
	} else {
		int canSell = +prices[index] + solve(index + 1, 1, prices);
		int skipSell = 0 + solve(index + 1, 0, prices);
		profit = max(canSell, skipSell);
	}
	return profit;
}

int solveMem(int index, int buy, vector<int>& prices,
			 vector<vector<int>>& dp) {
	if (index == prices.size())
		return 0;

	if (dp[index][buy] != -1)
		return dp[index][buy];

	int profit = 0;

	if (buy) {
		int canBuy = -prices[index] + solveMem(index + 1, 0, prices, dp);
		int skipBuy = 0 + solveMem(index + 1, 1, prices, dp);
		profit = max(canBuy, skipBuy);
	} else {
		int canSell = +prices[index] + solveMem(index + 1, 1, prices, dp);
		int skipSell = 0 + solveMem(index + 1, 0, prices, dp);
		profit = max(canSell, skipSell);
	}
	return dp[index][buy] = profit;
}

int solveTab(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>> dp(n+1, vector<int>(2, 0));

	for (int index = n-1; index >= 0; index--) {
		for (int buy = 0; buy <= 1; buy++) {
			int profit = 0;

			if (buy) {
				int canBuy =  -prices[index] + dp[index + 1][0];
				int skipBuy = 0 + dp[index + 1][1];
				profit = max(canBuy, skipBuy);
			} else {
				int canSell = +prices[index] + dp[index + 1][1];
				int skipSell = 0 + dp[index + 1][0];
				profit = max(canSell, skipSell);
			}
			dp[index][buy] = profit;
		}
	}
	return dp[0][1];
}

int solveOpt(vector<int>& prices) {
	int n = prices.size();
	vector<int> curr(2, 0);
	vector<int> next(2, 0);

	for (int index = n-1; index >= 0; index--) {
		for (int buy = 0; buy <= 1; buy++) {
			int profit = 0;

			if (buy) {
				int canBuy =  -prices[index] + next[0];
				int skipBuy = 0 + next[1];
				profit = max(canBuy, skipBuy);
			} else {
				int canSell = +prices[index] + next[1];
				int skipSell = 0 + next[0];
				profit = max(canSell, skipSell);
			}
			curr[buy] = profit;
		}
		next = curr;
	}
	return next[1];
}

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>> dp(n, vector<int>(2, -1));

	// return solve(0, 1, prices);
	// return solveMem(0, 1, prices, dp);
	// return solveTab(prices);
	return solveOpt(prices);
}