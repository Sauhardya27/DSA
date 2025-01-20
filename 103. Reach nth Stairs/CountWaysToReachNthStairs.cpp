#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

//Using Recursion
// int solve(int i, int nStairs){
// 	if (i == nStairs)
// 		return 1;

// 	if (i > nStairs)
// 		return 0;

// 	return (solve(i + 1, nStairs) + solve(i + 2, nStairs)) % MOD;
// }
int countDistinctWays(int nStairs)
{
	// int ans = solve(0, nStairs);
	// return ans;

	//Using bottom-up dp approach
	int n = nStairs;
	vector<int> dp(n+1);

    dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++){
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	return dp[n];
}