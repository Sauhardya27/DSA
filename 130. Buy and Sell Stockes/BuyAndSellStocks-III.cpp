#include <bits/stdc++.h>
using namespace std;

int solve(int index, int buy, vector<int>& prices, int limit) {
	if (index == prices.size())
		return 0;

	if(limit == 0)
		return 0;

	int profit = 0;

	if (buy) {
		int canBuy = -prices[index] + solve(index + 1, 0, prices, limit);
		int skipBuy = 0 + solve(index + 1, 1, prices, limit);
		profit = max(canBuy, skipBuy);
	} else {
		int canSell = +prices[index] + solve(index + 1, 1, prices, limit-1);
		int skipSell = 0 + solve(index + 1, 0, prices, limit);
		profit = max(canSell, skipSell);
	}
	return profit;
}

int solveMem(int index, int buy, vector<int>& prices, int limit,
			 vector<vector<vector<int>>> &dp) {
	if (index == prices.size())
		return 0;

	if(limit == 0)
		return 0;

	if (dp[index][buy][limit] != -1)
		return dp[index][buy][limit];

	int profit = 0;

	if (buy) {
		int canBuy = -prices[index] + solveMem(index + 1, 0, prices, limit, dp);
		int skipBuy = 0 + solveMem(index + 1, 1, prices, limit, dp);
		profit = max(canBuy, skipBuy);
	} else {
		int canSell = +prices[index] + solveMem(index + 1, 1, prices, limit-1, dp);
		int skipSell = 0 + solveMem(index + 1, 0, prices, limit, dp);
		profit = max(canSell, skipSell);
	}
	return dp[index][buy][limit] = profit;
}

int solveTab(vector<int>& prices) {
	int n = prices.size();
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3, 0)));

	for (int index = n-1; index >= 0; index--) {
		for (int buy = 0; buy <= 1; buy++) {
			for(int limit = 1; limit <= 2; limit++){
				int profit = 0;

				if (buy) {
					int canBuy = -prices[index] + dp[index + 1][0][limit];
					int skipBuy = 0 + dp[index + 1][1][limit];
					profit = max(canBuy, skipBuy);
				} else {
					int canSell = +prices[index] + dp[index + 1][1][limit-1];
					int skipSell = 0 + dp[index + 1][0][limit];
					profit = max(canSell, skipSell);
				}
				dp[index][buy][limit] = profit;
			}
		}
	}
	return dp[0][1][2];
}

int solveOpt(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>> curr(2, vector<int>(3, 0));
	vector<vector<int>> next(2, vector<int>(3, 0));

	for (int index = n-1; index >= 0; index--) {
		for (int buy = 0; buy <= 1; buy++) {
			for(int limit = 1; limit <= 2; limit++){
				int profit = 0;

				if (buy) {
					int canBuy = -prices[index] + next[0][limit];
					int skipBuy = 0 + next[1][limit];
					profit = max(canBuy, skipBuy);
				} else {
					int canSell = +prices[index] + next[1][limit-1];
					int skipSell = 0 + next[0][limit];
					profit = max(canSell, skipSell);
				}
				curr[buy][limit] = profit;
			}
		}
		next = curr;
	}
	return next[1][2];
}

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));

	// return solve(0, 1, prices, 2);
	// return solveMem(0, 1, prices, 2, dp);
	// return solveTab(prices);
	return solveOpt(prices);
}