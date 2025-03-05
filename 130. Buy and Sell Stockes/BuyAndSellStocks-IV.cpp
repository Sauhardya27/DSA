#include <bits/stdc++.h>
using namespace std;

int solveOpt1(vector<int>& prices, int k) {
	int n = prices.size();
	vector<vector<int>> curr(2, vector<int>(k + 1, 0));
	vector<vector<int>> next(2, vector<int>(k + 1, 0));

	for (int index = n - 1; index >= 0; index--) {
		for (int buy = 0; buy <= 1; buy++) {
			for (int limit = 1; limit <= k; limit++) {
				int profit = 0;

				if (buy) {
					int canBuy = -prices[index] + next[0][limit];
					int skipBuy = 0 + next[1][limit];
					profit = max(canBuy, skipBuy);
				} else {
					int canSell = +prices[index] + next[1][limit - 1];
					int skipSell = 0 + next[0][limit];
					profit = max(canSell, skipSell);
				}
				curr[buy][limit] = profit;
			}
		}
		next = curr;
	}
	return next[1][k];
}

int solve(int index, int operatioNo, int k, vector<int>& prices) {
	if (index == prices.size())
		return 0;

	if (operatioNo == 2 * k)
		return 0;

	int profit = 0;

	if ((operatioNo & 1) == 0) {
		int canBuy =
			-prices[index] + solve(index + 1, operatioNo + 1, k, prices);
		int skipBuy = 0 + solve(index + 1, operatioNo, k, prices);
		profit = max(canBuy, skipBuy);
	} else {
		int canSell =
			+prices[index] + solve(index + 1, operatioNo + 1, k, prices);
		int skipSell = 0 + solve(index + 1, operatioNo, k, prices);
		profit = max(canSell, skipSell);
	}
	return profit;
}

int solveMem(int index, int operatioNo, int k, vector<int>& prices,
			 vector<vector<int>>& dp) {
	if (index == prices.size())
		return 0;

	if (operatioNo == 2 * k)
		return 0;

	if (dp[index][operatioNo] != -1)
		return dp[index][operatioNo];

	int profit = 0;

	if ((operatioNo & 1) == 0) {
		int canBuy = -prices[index] +
					 solveMem(index + 1, operatioNo + 1, k, prices, dp);
		int skipBuy = 0 + solveMem(index + 1, operatioNo, k, prices, dp);
		profit = max(canBuy, skipBuy);
	} else {
		int canSell = +prices[index] +
					  solveMem(index + 1, operatioNo + 1, k, prices, dp);
		int skipSell = 0 + solveMem(index + 1, operatioNo, k, prices, dp);
		profit = max(canSell, skipSell);
	}
	return dp[index][operatioNo] = profit;
}

int solveTab(vector<int>& prices, int k) {
	int n = prices.size();
	vector<vector<int>> dp(n + 1, vector<int>(2*k+1, 0));

	for (int index = n - 1; index >= 0; index--) {
		for (int operatioNo = 0; operatioNo < 2*k; operatioNo++) {
			int profit = 0;

			if ((operatioNo & 1) == 0) {
				int canBuy = -prices[index] + dp[index + 1][operatioNo+1];
				int skipBuy = 0 + dp[index + 1][operatioNo];
				profit = max(canBuy, skipBuy);
			} else {
				int canSell = +prices[index] + dp[index + 1][operatioNo+1];
				int skipSell = 0 + dp[index + 1][operatioNo];
				profit = max(canSell, skipSell);
			}
			dp[index][operatioNo] = profit;
		}
	}
	return dp[0][0];
}

int solveOpt2(vector<int>& prices, int k) {
	int n = prices.size();
	vector<int> curr(2*k+1, 0);
	vector<int> next(2*k+1, 0);

	for (int index = n - 1; index >= 0; index--) {
		for (int operatioNo = 0; operatioNo < 2*k; operatioNo++) {
			int profit = 0;

			if ((operatioNo & 1) == 0) {
				int canBuy = -prices[index] + next[operatioNo+1];
				int skipBuy = 0 + next[operatioNo];
				profit = max(canBuy, skipBuy);
			} else {
				int canSell = +prices[index] + next[operatioNo+1];
				int skipSell = 0 + next[operatioNo];
				profit = max(canSell, skipSell);
			}
			curr[operatioNo] = profit;
		}
		next = curr;
	}
	return next[0];
}

int maxProfit(int k, vector<int>& prices) {
	// return solveOpt1(prices, k);
	// return solve(0, 0, k, prices);

	int n = prices.size();
	// vector<vector<int>> dp(n, vector<int>(2 * k, -1));
	// return solveMem(0, 0, k, prices, dp);
	// return solveTab(prices, k);
	return solveOpt2(prices, k);
}