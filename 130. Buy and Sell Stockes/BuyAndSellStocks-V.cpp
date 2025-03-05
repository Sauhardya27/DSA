#include <bits/stdc++.h>
using namespace std;

int solveOpt(vector<int>& prices, int fee) {
	int n = prices.size();
	vector<int> curr(2, 0);
	vector<int> next(2, 0);

	for (int index = n - 1; index >= 0; index--) {
		for (int buy = 0; buy <= 1; buy++) {
			int profit = 0;

			if (buy) {
				int canBuy = -prices[index] + next[0];
				int skipBuy = 0 + next[1];
				profit = max(canBuy, skipBuy);
			} else {
				int canSell = +prices[index] + next[1] - fee;
				int skipSell = 0 + next[0];
				profit = max(canSell, skipSell);
			}
			curr[buy] = profit;
		}
		next = curr;
	}
	return next[1];
}

int maxProfit(vector<int>& prices, int fee) {
	return solveOpt(prices, fee);
}