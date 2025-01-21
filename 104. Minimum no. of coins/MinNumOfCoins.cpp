#include <bits/stdc++.h> 
using namespace std;

int solveRec(vector<int> &num, int x){
    if(x == 0)
        return 0;
    
    if(x < 0)
        return INT_MAX; //Cannot reach x

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++){
        int ans = solveRec(num, x-num[i]);
        if(ans != INT_MAX)
            mini = min(mini, ans+1);//Add 1 considering the current element
    }

    return mini;
}

// Top Down Approach
int solveMem(vector<int> &num, int x, vector<int> &dp){
    if(x == 0)
        return 0;
    
    if(x < 0)
        return INT_MAX; //Cannot reach x

    if(dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++){
        int ans = solveRec(num, x-num[i]);
        if(ans != INT_MAX)
            mini = min(mini, ans+1);//Add 1 considering the current element
    }
    dp[x] = mini;

    return mini;
}

// Bottom Up Approach
int solveTab(vector<int> &num, int x){
    vector<int> dp(x+1, INT_MAX);

    dp[0] = 0; //Hitting the target value i.e. x == 0 similar to above 

    for(int i=1; i<=x; i++){
        //solve for every amount figure from 1 to x;
        for(int j=0; j<num.size(); j++){
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX) //Checking the second condition since so that 1 + INT_MAX doesn't overflow
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
        }
    }

    return dp[x];
}

int minimumElements(vector<int> &num, int x){
    // int ans = solveRec(num, x);
    
    // if(ans == INT_MAX)
    //     return -1;
    // return ans;

	// vector<int> dp(x+1, -1);

    // int ans = solveMem(num, x, dp);
    
    // if(ans == INT_MAX)
    //     return -1;
    // return ans;

	int ans = solveTab(num, x);
    
    if(ans == INT_MAX)
        return -1;
    return ans;
}