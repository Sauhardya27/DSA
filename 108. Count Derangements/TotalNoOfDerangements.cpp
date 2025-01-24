#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;

long long int solve(int n){
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    long long int ans = (((n-1) % MOD)*((solve(n-1) % MOD) + (solve(n-2) % MOD)) % MOD) % MOD;
    return ans;
}

// Top-Down Approach
long long int solveMem(int n, vector<long long int> &dp){
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = (((n-1) % MOD)*((solveMem(n-1, dp) % MOD) + (solveMem(n-2, dp) % MOD)) % MOD) % MOD;
    return dp[n];
}

// Bottom-Up Approach
long long int solveTab(int n){
    vector<long long int> dp(n+1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = (((i-1) % MOD)*((dp[i-1] % MOD) + (dp[i-2] % MOD)) % MOD) % MOD;
    }
    return dp[n];
}


// Space Optimization
long long int solveOpt(int n){
    vector<long long int> dp(n+1, 0);

    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i=3; i<=n; i++){
        long long int ans = (((i-1) % MOD)*((prev1 % MOD) + (prev2 % MOD)) % MOD) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int countDerangements(int n) {
    // vector<long long int> dp(n+1, -1);
    // long long int ans = solveMem(n, dp);
    // return solveTab(n);
	return solveOpt(n);
}