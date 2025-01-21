#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int> &nums, int n){
    //Iterating from right to left
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0]; //Only 1 element present

    int include = solve(nums, n-2) + nums[n];
    int exclude = solve(nums, n-1) + 0;

    return max(include, exclude);
}

//Top down approach
int solveMem(vector<int> &nums, int n, vector<int> &dp){
    //Iterating from right to left
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0]; //Only 1 element present

    if(dp[n] != -1)
        return dp[n];

    int include = solve(nums, n-2) + nums[n];
    int exclude = solve(nums, n-1) + 0;

    dp[n] = max(include, exclude);

    return dp[n];
}

//Bottom up approach
int solveTab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        int include = nums[i];
        if (i - 2 >= 0) // Only add dp[i-2] if it's valid
            include += dp[i - 2];
        int exclude = dp[i-1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // int n = nums.size();
    // int ans = solve(nums, n-1);
    // return ans;

	// vector<int> dp(n, -1);
    // return solveMem(nums, n-1, dp);

	return solveTab(nums);
}